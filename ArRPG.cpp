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
        {};

        void setName(std::string name) {m_name = name;};
        void setHealth(double health) {m_health = health;};
        void setAttack(double attack) {m_attack = attack;};

        std::string getName() const {return m_name;};
        double getHealth()   {return m_health;};
        double getAttack()  {return m_attack;};

        friend std::ostream& operator<<(std::ostream& out, const Enemy& a){
            out << a.m_name <<" \nHealth : "<< a.m_health <<" \nAttack : "<< a.m_attack<<"\n";
            return out;
        }

        bool operator==(const Enemy& other) const {
        return this->m_name == other.m_name && 
               this->m_health == other.m_health &&
               this->m_attack == other.m_attack;
        }
};


std::string genNames(){
    int rand{Random::get(1,6)};
    switch (rand){
        case 1 : return "Goblin";
        break;
        case 2 : return "Dragon";
        break;
        case 3 : return "Drake";
        break;
        case 4 : return "Ogre";
        break;
        case 5 : return "Orc";
        break;
        case 6 : return "Spider";
        break;
        default : return "none";
    }
    return "none";
}

void addMonster(std::vector<Enemy>& a){
    int index{Random::get(1,10)};
    for(std::size_t i = 0; i < index; i++){
        std::string name{genNames()};
        double Attack{Random::get(20.0,100.0)};
        double Health{Random::get(100.00,500.00)};

        a.emplace_back(name,Health,Attack);
    }
}

void printMonsters(std::vector<Enemy>& a){
    int i{0};
    for(auto& e : a){
        std::cout<<i<<" "<<e;
        i++;
    }
}

Enemy& generateOneMonster(std::vector<Enemy>& a){
    if(a.empty()){
        std::cout<<"No monster is availabe\n";
    }

    std::size_t monIndex{Random::get<std::size_t>(0, a.size() - 1)};
    return a[monIndex];
}


bool dealDamage(Enemy& attacker, Enemy& defender, std::vector<Enemy>& a) {
    if(defender.getHealth() <= 0) return false;
    double damage = attacker.getAttack();
    double newHealth = defender.getHealth() - damage;
    
    if(defender.getHealth() > 0){
        std::cout << attacker.getName() << " hits " << defender.getName() << " for " << damage << " damage!\n";
        defender.setHealth(newHealth);
    }
    if(defender.getHealth() <= 0){
        auto it = std::find(a.begin(),a.end(),defender);
        if(it != a.end()){
            a.erase(it);
        }
        return true;
    }
    return false;
}

void playerStatus(Enemy& player){
    std::cout<<"\n===== Status =====\n";
    std::cout<<"Name: "<<player.getName()<<"\n";
    std::cout<<"Health: "<<player.getHealth()<<"\n";
    std::cout<<"Attack: "<<player.getAttack()<<"\n";
    std::cout<<"===================";
}

void battle(std::vector<Enemy>& MonsterPool, Enemy& player) {
    if(MonsterPool.empty()){
        std::cout << "There are no monsters left!\n";
        return;  // Need to return here
    }

    Enemy& enemy = generateOneMonster(MonsterPool);
    std::cout << "\n===== NEW BATTLE =====\n";
    std::cout << "You encounter: " << enemy.getName() << "\n";
    std::cout << enemy;

    int round{1};  
    bool player_turn{true};
    bool bide{false};

    while(player.getHealth() > 0 && enemy.getHealth() > 0) {
        std::cout << "\n--- Round " << round << " ---\n";  // Fixed room display
        
        if(player_turn) {
            std::cout << "\n[YOUR TURN]\n";
            
            std::cout << "Choose action:\n";
            std::cout << "1. Attack\n";
            std::cout << "2. Check status\n";
            std::cout << "3. Flee\n";
            std::cout << "4. Bide <skip a turn to get a attack boost>\n";
            std::cout << "Choice: ";

            int choice{0};
            std::cin >> choice;
            std::cin.ignore();  // Clear newline from input buffer

            switch(choice) {
                case 1: 
                    std::cout << player.getName() << " strikes at " << enemy.getName() << "!\n";
                    if(dealDamage(player, enemy, MonsterPool)) {
                        std::cout << "\n*** Victory! You defeated " << enemy.getName() << "! ***\n";
                        // Battle ends when enemy dies, break out of switch
                        player.setAttack(player.getAttack() + 0.020);
                        std::cout << "You gained an attack boost!\n";
                        std::cout << "New attack: " << player.getAttack() << "\n";
                        return;  // End battle function
                    }
                    // Cancels out bide attack boost
                    if(bide){
                        std::cout<<player.getName()<<" Bide has ended\n";
                        player.setAttack(player.getAttack() - 0.70);
                    }
                     
                    // Only apply attack boost if attack was successful but didn't kill
                    player.setAttack(player.getAttack() + 0.020);
                    std::cout << "You gained an attack boost!\n";
                    break;
                    
                case 2:
                    std::cout << "\n[STATUS]\n";
                    playerStatus(player);
                    std::cout<<"\n";
                    playerStatus(enemy);
                    player_turn = true;  // Stay on player's turn
                    continue;  // Skip enemy turn
                    
                case 3:
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
                    player.setHealth(player.getHealth() - enemy.getAttack());
                    std::cout << "You take " << enemy.getAttack() << " damage!\n";
                    player.setAttack(player.getAttack() + 0.70);
                    bide = true;
                    std::cout<<player.getName()<<" attack increased temporarily to: "<<player.getAttack()<<"\n";
                    break;
                    
                default: 
                    std::cout << "Invalid choice! You hesitate...\n";
                    break;
            }
        } else {
            // Enemy's turn
            std::cout << "\n[ENEMY TURN]\n";
            std::cout << enemy.getName() << " attacks you!\n";
            
            std::vector<Enemy> dummyPlayerContainer;
            dummyPlayerContainer.push_back(player);  // Add player copy
            
            Enemy& tempPlayerRef = dummyPlayerContainer[0];  // Get reference to copy
            
            if(dealDamage(enemy, tempPlayerRef, dummyPlayerContainer)) {
                // This means player would die
                std::cout << "\n*** DEFEAT! " << enemy.getName() << " has defeated you! ***\n";
                player.setHealth(0);  // Actually kill the real player
                return;  // End battle
            }
            
            // Update real player's health
            player.setHealth(tempPlayerRef.getHealth());
        }

        // Switch turns
        player_turn = !player_turn;

        // Check battle end conditions
        if (enemy.getHealth() <= 0) {
            std::cout << "\n*** VICTORY! You defeated " << enemy.getName() << "! ***\n";
            auto it = std::find(MonsterPool.begin(), MonsterPool.end(), enemy);
            if (it != MonsterPool.end()) {
                MonsterPool.erase(it);
            }
            return;
        }
        
        if (player.getHealth() <= 0) {
            std::cout << "\n*** DEFEAT! You have been slain by " << enemy.getName() << "! ***\n";
            return;
        }

        // Show battle status at end of round
        std::cout << "\n[Battle Status]\n";
        playerStatus(player);
        std::cout<<"\n";
        playerStatus(enemy);
        
        // Pause between rounds
        if (round < 10) {  // Only pause for first few rounds
            std::cout << "\nPress Enter to continue...";
            std::cin.get();
        }
        
        round++;
    }
}

int main() {
    std::vector<Enemy> MonsterPool;
    addMonster(MonsterPool);
    
    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);
    double getHealth{Random::get(300.00,1000.00)};
    double getAttack{Random::get(50.00,80.00)};
    Enemy player{playerName, getHealth, getAttack};
    
    std::cout << "\nWelcome, " << playerName << "!\n";
    std::cout << "There are " << MonsterPool.size() << " monsters in the area.\n";
    
    // Battle until player dies or all monsters are defeated
    while (player.getHealth() > 0 && !MonsterPool.empty()) {
        battle(MonsterPool, player);
        
        if (player.getHealth() > 0 && !MonsterPool.empty()) {
            std::cout << "\nMonsters remaining: " << MonsterPool.size() << "\n";
            std::cout << "Continue fighting? (y/n): ";
            char choice;
            std::cin >> choice;
            std::cin.ignore();
            
            if (choice != 'y' && choice != 'Y') {
                break;
            }
        }
    }
    
    if (player.getHealth() <= 0) {
        std::cout << "\nGAME OVER! You have been defeated.\n";
    } else if (MonsterPool.empty()) {
        std::cout << "\nCONGRATULATIONS! You cleared all monsters!\n";
    }
    
    return 0;
}