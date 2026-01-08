#include<iostream>
#include "Random.h"
#include<vector>
#include<string>
#include<cassert>
#include<algorithm>
#include <limits>

constexpr double Attack_MIN{30.00};
constexpr double Attack_MAX{80.00};
constexpr double Health_MIN{50.0};
constexpr double Health_MAX{300.00};
constexpr double bide_bonus{10.00};
constexpr double Health_MIN_player{600.00};
constexpr double Health_MAX_player{1000.00};
constexpr double LevelBonus{1.15};
constexpr double Insult_bonus{0.50};
constexpr double brace_reduction{1.15};
constexpr double Attack_boost{0.05};

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Enemy{
    std::string m_name{"none"};
    double m_health{0.0};
    double m_attack{0.0};
    double m_exp{0.0};
    int m_level{0};
    public:
        explicit Enemy(std::string name = "none", double health = 0.0, double attack = 0.0, double exp = 0.0, int level = 0)
        : m_name{name}, m_health{health}, m_attack{attack}, m_exp{exp}, m_level{level}
        {}

        const std::string& getName() const {return m_name;};
        double getHealth() const {return m_health;};
        double getAttack() const {return m_attack;};
        double getEXP() const {return m_exp;};
        int getLevel() const {return m_level;};

        void setName(std::string name) {m_name = name;};
        void setHealth(double health) {m_health = std::max(0.0,health);};
        void setAttack(double attack) {m_attack = attack;};
        void setEXP(double xp) {m_exp = xp;};
        void setLevel(int level) {m_level = level;};

        friend std::ostream& operator <<(std::ostream& out, const Enemy& a){
            out <<
            "\nName: "<< a.getName() <<
            "\nHealth Points: "<<a.getHealth()<<
            "\nAttack power: "<<a.getAttack()<<
            "\nLevel: "<<a.getLevel()<<"\n";
            return out;
        }

        bool operator==(const Enemy& b) const {
            return (this->m_name == b.m_name)&&
                   (this->m_health == b.m_health)&&
                   (this->m_attack == b.m_attack)&&
                   (this->m_exp == b.m_exp)&&
                   (this->m_level == b.m_level);
        }
};

std::string genNames() {
    static const std::vector<std::string> names {
        "Dragon", "Undead", "Demon", "Giant", 
        "Beast", "Spirit", "Aberration", "Skeleton",
        "Cursed knight", "Boss baby"
    };
    
    return names[Random::get<std::size_t>(0, names.size() - 1)];
}

int setLevel(Enemy& player){
    if (player.getEXP() >= 2800) return 10;
    if (player.getEXP() >= 2300) return 9;
    if (player.getEXP() >= 1850) return 8;
    if (player.getEXP() >= 1450) return 7;
    if (player.getEXP() >= 1100) return 6;
    if (player.getEXP() >= 800) return 5;
    if (player.getEXP() >= 550) return 4;
    if (player.getEXP() >= 350) return 3;
    if (player.getEXP() >= 200) return 2;
    if (player.getEXP() >= 100) return 1;
    return 0;
}

void updateLevel(Enemy& player){
    int newLevel = setLevel(player);
    if(newLevel > player.getLevel()){
        for(int level = player.getLevel() + 1; level <= newLevel; level++){
            player.setAttack(player.getAttack() * LevelBonus);
            player.setHealth(player.getHealth() * LevelBonus);
            std::cout << "Level " << level << " reached!\n";
        }
        player.setLevel(newLevel);
        std::cout << "You are now level " << newLevel << "!\n";
        std::cout << "Health: " << player.getHealth() << "\n";
        std::cout << "Attack: " << player.getAttack() << "\n";
    }
}

void setMonsterPool(std::vector<Enemy>& MonsterPool, int diff){
    std::size_t index{Random::get<std::size_t>(2,15)};
    for(std::size_t i = 0; i < index; i++){
        std::string getNames(genNames());
        int Monster_level = 1;
        switch(diff){
            case 1 :
                Monster_level = Random::get(1,3);
                break;
            case 2 :
                Monster_level = Random::get(4,6);
                break;
            case 3:
                Monster_level = Random::get(7,10);
                break;
            default: 
                Monster_level = 1;
        }

        double base_health{Random::get(Health_MIN,Health_MAX)};
        double base_attack{Random::get(Attack_MIN,Attack_MAX)};

        double health = base_health * (1 + 0.2 * (Monster_level - 1));
        double attack = base_attack * (1+ 0.1  * (Monster_level - 1));
        double EXP = 50 * Monster_level * Monster_level;

        Enemy Monster{getNames,health,attack,EXP,Monster_level};
        MonsterPool.push_back(Monster);
    }
}

std::size_t generateMOn(std::vector<Enemy>& MonsterPool){
    assert(!MonsterPool.empty());
    std::size_t monIndex{Random::get<std::size_t>(0, MonsterPool.size() - 1)};
    if(MonsterPool[monIndex].getName() == "Boss baby"){
        MonsterPool[monIndex].setAttack(MonsterPool[monIndex].getAttack() + 50);
        MonsterPool[monIndex].setHealth(MonsterPool[monIndex].getHealth() + 50);
    }
    return monIndex;
}

void gainEXP(Enemy& player, Enemy& enemy){
   double xp_gained = enemy.getEXP() * 0.5;
   player.setEXP(player.getEXP() + xp_gained);
   std::cout << "Gained " << xp_gained << " EXP!\n";
   updateLevel(player);  // Check for level up immediately
}

double dealDamage(Enemy& attacker, Enemy& defender){
    double attack = attacker.getAttack();

    if(defender.getHealth() > 0){
        std::cout<<"\n=====================================\n";
        std::cout<<attacker.getName()<<" Strikes at "<<defender.getName()<<" for "<<attack<<" damage ";
        std::cout<<"\n=====================================\n";
        defender.setHealth(defender.getHealth() - attack);
    }
    return attack;
}

void Insult(Enemy& enemy, Enemy& player){
    static const std::vector<std::string> insults {
        "Stupid", "Poopyhead", "Ugly", "Lame", 
        "Loser", "Idiot", "Childish", "Lanky",
        "Fat", "Flat", "Boss baby"
    };
    std::string Insultnames{insults[Random::get<std::size_t>(0,insults.size() - 1)]};
    std::cout<<player.getName()<<" insulted "<<enemy.getName()<<player.getName()<<" called them "<<Insultnames<<"\n";
    enemy.setAttack(enemy.getAttack() - Insult_bonus);
    std::cout<<enemy.getName()<<" Attack lowered to : "<<enemy.getAttack()<<"\n";
}

bool isDead(const Enemy& dead){
    return dead.getHealth() <= 0;
}

void deleteDead(std::vector<Enemy>& MonsterPool, std::size_t index){
    MonsterPool.erase(MonsterPool.begin() + index);
}

void AttackBoost(Enemy& player, int choice){
    if(choice == 5){
        std::cout <<player.getName()<< " gained spirit after that successful Insult!\n";
        player.setAttack(player.getAttack() + Attack_boost);
        std::cout << "New permanent attack: " << player.getAttack() << "\n";
    }
    else{
        player.setAttack(player.getAttack() + Attack_boost);
        std::cout <<player.getName()<< " gained spirit after that successful attack!\n";
        std::cout << "New permanent attack: " << player.getAttack() << "\n";
    }
}


void printPlayerChoice(){
    std::cout<<"\n==== Your Turn! ====\n";
            std::cout << "Choose action:\n";
            std::cout << "1. Attack\n";
            std::cout << "2. Check status\n";
            std::cout << "3. Flee\n";
            std::cout << "4. Bide   <skip a turn to get a major attack boost>\n";
            std::cout << "5. Insult <Lowers enemy attack stat>\n";
            std::cout << "6. Brace  <Lowers enemy next attack>\n";
            std::cout << "Choice: ";
}

void playerStatus(Enemy& player){
   if(player.getHealth() > 0){
    std::cout<<"============";
    std::cout<<player;
    std::cout<<"============";
   }
}

int getEnemyChoice(){
    int enemy_choice{};
    int roll = Random::get(1, 100);
    if(roll <= 60)          enemy_choice = 1; // attack
    else if(roll <= 80)     enemy_choice = 2; // bide
    else if(roll <= 95)     enemy_choice = 3; // brace
    else                    enemy_choice = 4; // insult
    return enemy_choice;
}

void Battle(std::vector<Enemy>& MonsterPool, Enemy& player){
    if(MonsterPool.empty()){
        std::cout<<"The monsterpool is empty\n";
        return;
    }


    std::size_t MonIndex{generateMOn(MonsterPool)};
    Enemy& enemy = MonsterPool[MonIndex];
    std::cout << "\n===== NEW BATTLE =====\n";
    std::cout << "You encounter: " << enemy.getName() << "\n";
    std::cout << enemy;

    int round{1};
    bool player_turn{true};
    bool bide{false};
    bool brace{false};
    bool enemy_bide{false};
    bool enemy_brace{false};

    while(player.getHealth() > 0 && !MonsterPool.empty()){
        if(player_turn){
            printPlayerChoice();
            int choice{0};
            std::cin>>choice;
            ignoreLine();
            if(!std::cin){
                std::cin.clear(); 
                ignoreLine();  
                std::cout << "Invalid input! Please enter a number.\n";
                continue;
            }
            switch(choice){
                case 1 :
                    if(bide){
                        std::cout<<player.getName()<<" Releases a powerful attack!\n";
                        std::cout<<player.getName()<<" Bide has ended\n";
                        player.setAttack(player.getAttack() - bide_bonus);
                        bide = false;
                    }
                    if(enemy_brace){
                        double brace_damage = std::max(0.0, player.getAttack() - brace_reduction);
                        enemy.setHealth(enemy.getHealth() - brace_damage);
                        std::cout<<"Braced reduced the attack to: "<<brace_damage<<"\n";
                        enemy_brace = false;
                    }
                    else{
                        dealDamage(player,enemy);
                    }
                    if(isDead(enemy)){
                        std::cout << "\n*** Victory! You defeated the enemy "<<enemy.getName()<<" ***\n";
                        AttackBoost(player,choice);
                        gainEXP(player,enemy);
                        deleteDead(MonsterPool,MonIndex);
                        return;
                    }
                    break;
                case 2:
                    player_turn = true;
                    playerStatus(player);
                    std::cout<<"\n";
                    playerStatus(enemy);
                    std::cout<<"\n";
                    continue;
                case 3 :
                    std::cout << "You attempt to flee...\n";
                    if(Random::get(1, 100) > 50) {
                        std::cout << "You successfully escaped!\n";
                        return;  // End battle
                    } else {
                        std::cout << "You failed to escape!\n";
                        // Enemy gets a free attack when flee fails
                        std::cout << enemy.getName() << " gets a free attack!\n";
                        dealDamage(enemy,player);
                        std::cout << "You take " << dealDamage << " damage!\n";
                    }
                    break;
                case 4 :
                    std::cout<<"You bide your attack!\n";
                    std::cout << enemy.getName() << " gets a free attack!\n";
                    dealDamage(enemy,player);
                    player.setAttack(player.getAttack() + bide_bonus);
                    bide = true;
                    std::cout<<player.getName()<<" attack increased temporarily to: "<<player.getAttack()<<"\n";
                    break;
                case 5 :
                    Insult(enemy,player);
                    AttackBoost(player,choice);
                    break;
                case 6:
                    brace = true;
                    std::cout<<"You braced for an attack!\n";
                    break;
                default :
                    std::cout << "Invalid choice! You hesitate...\n";
                    break;
            }
        }
        else{
            int enemy_choice{getEnemyChoice()};
            std::cout << "\n[ENEMY TURN]\n";
            switch(enemy_choice){
                case 1:
                    std::cout << enemy.getName() << " attacks you!\n";
                    if(enemy_bide){
                        std::cout<<enemy.getName()<<" Releases a powerful attack!\n";
                        std::cout<<enemy.getName()<<" Bide has ended\n";
                        enemy.setAttack(enemy.getAttack() - bide_bonus);
                        enemy_bide = false;
                    }
                    if(brace){
                        double brace_damage = std::max(0.0, enemy.getAttack() - brace_reduction);
                        player.setHealth(player.getHealth() - brace_damage);
                        std::cout<<"Braced reduced the attack to: "<<brace_damage<<"\n";
                        brace = false;
                    }else{
                        dealDamage(enemy,player);
                    }
                    if(isDead(player)){
                        std::cout << "\n*** DEFEAT! " << enemy.getName() << " has defeated you! ***\n";
                    }
                    break;
                case 2 :
                    std::cout<<enemy.getName()<<" bide their attack!\n";
                    std::cout << player.getName() << " gets a free attack!\n";
                    dealDamage(player,enemy);
                    enemy.setAttack(enemy.getAttack() + bide_bonus);
                    enemy_bide = true;
                    std::cout<<enemy.getName()<<" attack increased temporarily to: "<<enemy.getAttack()<<"\n";
                    break;
                case 3 :
                    enemy_brace = true;
                    std::cout<<enemy.getName()<<" braced for an attack!\n";
                    break;
                case 4 :
                    Insult(player,enemy);
                    break;
                default :
                    std::cout<<"The enemy hesitates\n";
                    
            }
        }

        player_turn = !player_turn;
        std::cout << "\n[Battle Status]\n";
        std::cout<<player;
        std::cout<<enemy;
        
        // Pause between rounds
        std::cout << "\nPress Enter to continue...";
        ignoreLine();
        
        round++;
    }
}


int main(){
    while(true){
        int diff{0};
        std::cout<<"Enter your difficulty < 1 for easy, 2 for medium and 3 for Hard >: ";
        std::cin>>diff;
        std::vector<Enemy> Monsterpool;
        setMonsterPool(Monsterpool,diff);
        std::string playerName;
        std::cout << "Enter your name: ";
        std::cin>>playerName;
        double getHealth{Random::get(Health_MIN_player,Health_MAX_player)};
        double getAttack{Random::get(Attack_MIN,Attack_MAX)};
        int level{Random::get(1,3)};
        double exp{50.0};
        Enemy player{playerName, getHealth, getAttack,exp,level};

        std::cout<<"\nWelcome "<<playerName<<"\n";
        std::cout<<Monsterpool.size()<<" amount of Monsters in the area\n";

        while(player.getHealth() > 0 && !Monsterpool.empty()){
            Battle(Monsterpool,player);
            if(player.getHealth() > 0 && !Monsterpool.empty()){
                std::cout<<Monsterpool.size()<<" amount of Monsters remaining\n";
                std::cout << "Continue fighting? (y/n): ";
                char choice;
                std::cin >> choice;
                if(!std::cin){
                    std::cin.clear(); 
                    ignoreLine();  
                    std::cout << "Invalid input! Please enter the correct choice!.\n";
                    continue;
                }
                ignoreLine();
                if(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N' ){
                    std::cout<<"Please out the correct input!\n";
                    continue;
                }
                if(choice != 'Y' && choice != 'y'){
                    break;
                }
            } 
        }

        if (player.getHealth() <= 0) {
            std::cout << "\nGAME OVER! You have been defeated.\n";
        }
        else if (Monsterpool.empty()) {
            std::cout << "\nCONGRATULATIONS! You cleared all monsters!\n";
        }

        std::cout<<"Enter q to quit and r to play again: ";
        char choice_play{'?'};
        std::cin>>choice_play;
        if(choice_play == 'r'){
            continue;
        }
        else{
            return false;
        }
    }
}

