#include<iostream>
#include "Random.h"
#include<vector>
#include<string>
#include<cassert>
#include<algorithm>

class Enemy{
    std::string m_name{"none"};
    double m_health{0.0};
    double m_attack{0.0};
    public:
        Enemy(std::string name = "none", double health = 0.0, double attack = 0.0)
        : m_name{name}, m_health{health}, m_attack{attack}
        {}

        std::string_view getName() const {return m_name;};
        double getHealth() const {return m_health;};
        double getAttack() const {return m_attack;};

        void setName(std::string name) {m_name = name;};
        void setHealth(double health) {m_health = std::max(0.0,health);};
        void setAttack(double attack) {m_attack = attack;};

        friend std::ostream& operator <<(std::ostream& out, const Enemy& a){
            out <<"\nName: "<< a.getName() <<" \nHealth Points: "<<a.getHealth()<<"\nAttack power: "<<a.getAttack()<<"\n";
            return out;
        }

        bool operator==(const Enemy& b) const {
            return (this->m_name == b.m_name)&&
                   (this->m_health == b.m_health)&&
                   (this->m_attack == b.m_attack);
        }
};

std::string genNames() {
    static const std::vector<std::string> names {
        "Dragon", "Undead", "Demon", "Giant", 
        "Beast", "Spirit", "Aberration", "Skeleton"
    };
    
    return names[Random::get<std::size_t>(0, names.size() - 1)];
}

void generateEnemyPool(std::vector<Enemy>& Monsters){
    int index{Random::get(1,10)};
    for(std::size_t i = 0; i < index; i++){
        std::string names{genNames()};
        double health{Random::get(50.0,300.00)};
        double attack{Random::get(30.00,80.00)};

        Monsters.emplace_back(names,health,attack);
    }
}

std::size_t getOneEnemy(std::vector<Enemy>& Monsters){
    std::size_t MonIndex{Random::get<std::size_t>(0, Monsters.size() - 1)};
    return MonIndex;
}

double dealDamage(const Enemy& attacker, Enemy& defender){
    double damage = attacker.getAttack();

    if(defender.getHealth() > 0){
        std::cout<<attacker.getName()<<" strikes at "<<defender.getName()<<" for "<< damage <<" damage\n";
        defender.setHealth(defender.getHealth() - damage);
    }

    return damage;
}

bool isDead(const Enemy& dead){
    return dead.getHealth() <= 0;
}

void deleteDead(std::vector<Enemy>& Monster, std::size_t index){
    Monster.erase(Monster.begin() + index);
}

void printPlayerChoice(){
    std::cout<<"\n==== Your Turn! ====\n";
            std::cout << "Choose action:\n";
            std::cout << "1. Attack\n";
            std::cout << "2. Check status\n";
            std::cout << "3. Flee\n";
            std::cout << "4. Bide <skip a turn to get a attack boost>\n";
            std::cout << "Choice: ";
}


void playerStatus(Enemy& player){
   if(player.getHealth() > 0){
    std::cout<<"============";
    std::cout<<player;
    std::cout<<"============";
   }
}

void Battle(std::vector<Enemy>& MOnsterPool, Enemy& player){
    if(MOnsterPool.empty()){
        std::cout<<"The monster pool is empty\n";
        return;
    }

    std::size_t enemy_index{getOneEnemy(MOnsterPool)};
    Enemy& enemy = MOnsterPool[enemy_index];
    std::cout << "\n===== NEW BATTLE =====\n";
    std::cout << "You encounter: " << enemy.getName() << "\n";
    std::string_view enemyName = enemy.getName();
    std::cout << enemy;

    int round{1};
    bool player_turn = true;
    bool bide{false};

    while(player.getHealth() > 0 && !MOnsterPool.empty()){
        if(player_turn){
            printPlayerChoice();
            int choice{0};
            std::cin>>choice;
            std::cin.ignore();
            switch(choice){
                case 1 :
                    if(bide){
                        std::cout<<player.getName()<<" Releases a powerful attack!\n";
                    }
                    dealDamage(player,enemy);
                    if(isDead(enemy)){
                        deleteDead(MOnsterPool,enemy_index);
                        std::cout << "\n*** Victory! You defeated " << enemyName << "! ***\n";
                        // Battle ends when enemy dies, break out of switch
                        player.setAttack(player.getAttack() + 0.020);
                        std::cout << "You gained an attack boost!\n";
                        std::cout << "New attack: " << player.getAttack() << "\n";
                        return;  // End battle function
                    }
                     if(bide){
                        std::cout<<player.getName()<<" Bide has ended\n";
                        player.setAttack(player.getAttack() - 0.70);
                        bide = false;
                    }
                     
                    // Only apply attack boost if attack was successful but didn't kill
                    player.setAttack(player.getAttack() + 0.020);
                    std::cout << "You gained an attack boost!\n";
                    break;
                case 2 :
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
                        double damage = enemy.getAttack();
                        player.setHealth(player.getHealth() - damage);
                        std::cout << "You take " << damage << " damage!\n";
                    }
                    break;
                case 4 :
                    std::cout<<"You bide your attack!\n";
                    std::cout << enemy.getName() << " gets a free attack!\n";
                    dealDamage(enemy,player);
                    player.setAttack(player.getAttack() + 0.70);
                    bide = true;
                    std::cout<<player.getName()<<" attack increased temporarily to: "<<player.getAttack()<<"\n";
                    break;
                default :
                    std::cout << "Invalid choice! You hesitate...\n";
                    break;
            }
        }
        else{
            std::cout << "\n[ENEMY TURN]\n";
            std::cout << enemy.getName() << " attacks you!\n";
            dealDamage(enemy,player);
            if(isDead(player)){
                std::cout << "\n*** DEFEAT! " << enemy.getName() << " has defeated you! ***\n";
            }
        }

        player_turn = !player_turn;
        if(isDead(enemy)){
            deleteDead(MOnsterPool,enemy_index);
        }

        std::cout << "\n[Battle Status]\n";
        std::cout<<player;
        std::cout<<enemy;
        
        // Pause between rounds
        if (round < 10) {  // Only pause for first few rounds
            std::cout << "\nPress Enter to continue...";
            std::cin.get();
        }
        
        round++;
    }
}   

int main(){
    std::vector<Enemy> Monsterpool;
    generateEnemyPool(Monsterpool);
    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);
    double getHealth{Random::get(300.00,1000.00)};
    double getAttack{Random::get(50.00,80.00)};
    Enemy player{playerName, getHealth, getAttack};

    std::cout<<"\nWelome "<<playerName<<"\n";
    std::cout<<Monsterpool.size()<<" amount of Monsters in the area\n";

    while(player.getHealth() > 0 && !Monsterpool.empty()){
        Battle(Monsterpool,player);
        if(player.getHealth() > 0 && !Monsterpool.empty()){
            std::cout<<Monsterpool.size()<<" amount of Monsters remaining\n";
            std::cout << "Continue fighting? (y/n): ";
            char choice;
            std::cin >> choice;
            std::cin.ignore();

            if(choice != 'Y' && choice != 'y'){
                break;
            }
        } 
    }

    if (player.getHealth() <= 0) {
        std::cout << "\nGAME OVER! You have been defeated.\n";
    } else if (Monsterpool.empty()) {
        std::cout << "\nCONGRATULATIONS! You cleared all monsters!\n";
    }
    
    return 0;

}

