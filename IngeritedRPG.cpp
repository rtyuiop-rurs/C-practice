#include<iostream>
#include "Random.h"
#include<array>
#include<cassert>
#include<string>
#include<string_view>

class Creature{
    protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};

    public:
    Creature( const std::string_view name, const char symbol, int health, int damage, int gold)
    : m_name{name},m_symbol{symbol},m_health{health},m_damage{damage},m_gold{gold}
    {}

    const std::string getName() const {return m_name;};
    char getSymbol() const {return m_symbol;};
    int getHealth() const {return m_health;};
    int getDamage() const {return m_damage;};
    int getGold() const {return m_gold;};

    void reduceHealth(int damage){
        m_health = m_health - damage;
    }

    bool isDead(){
        return m_health <= 0;
    }

    void addGold(int gold){
        m_gold = m_gold + gold;
    }
};

class Player : public Creature{
    int m_level{};
    public:
    Player( const std::string_view name, const char symbol = '@', int health = 10, int damage = 1, int gold = 0, int level = 1)
    : Creature{name,symbol,health,damage,gold}, m_level{level}
    {}

    void levelUp(){
        m_level++;
        Player::Creature::m_damage++;
    }

    int getLevel() const {return m_level;};

    bool hasWon(){
        return m_level >= 20;
    }

};

class Monster : public Creature{
    public:
    enum Type{
        dragon,
        orc,
        slime,
        MaxTypes,
    };
    private:
    static inline Creature MonsterData[] {
        Creature {"dragon",'D',20,4,100},
        Creature {"orc", 'O',4,2,25},
        Creature {"slime",'S',1,1,10}
    };
    public:
    Monster(Type t1)
    : Creature{MonsterData[t1]}
    {}

    static Monster genRandomMonster(){
        int ran{Random::get(0,MaxTypes - 1)};
        return Monster{static_cast<Type>(ran)};
    }
};



void print(std::string name, Player& os){
    std::cout<<"Welcome "<<name<<"\n";
    std::cout<<"You have "<<os.getHealth()<<" health and you are carrying "<<os.getGold()<<" gold and you deal"<<os.getDamage();
}

void attackMonster(Player& p1, Monster& m1){
    std::cout<<"You hit the "<<m1.getName()<<" for "<<p1.getDamage()<<"\n";
    m1.reduceHealth(p1.getDamage());
}

void attackPlayer(Monster& m1, Player& p1){
    std::cout<<"The "<<m1.getName()<<" hit you for "<<m1.getDamage()<<"\n";
    p1.reduceHealth(m1.getDamage());
}



void fightMonster(Player& p1){
    Monster monster{Monster::genRandomMonster()};
    std::cout<<"You ecountered a "<<monster.getName()<<"\n";

    while(!monster.isDead() && p1.getHealth() > 0){
            char choice{};
            std::cout<<"(R)un or (F)ight: ";
            std::cin>>choice;
            switch(choice){
                case 'R' :
                    if(Random::get(1, 100) > 50){
                        return;
                    }
                    else{
                        std::cout<<"You failed to flee";
                        attackPlayer(monster,p1);
                        if(p1.isDead()){
                            std::cout<<"You died\n";
                            return;
                        }
                    }
                    break;
                case 'F' :
                    attackMonster(p1,monster);
                    if(monster.isDead()){
                        std::cout<<"You killed the "<<monster.getName()<<"\n";
                        p1.levelUp();
                        std::cout<<"You leveled up!\n";
                        p1.addGold(monster.getGold());
                        std::cout<<"You received "<<monster.getGold()<<" gold\n";
                        return;
                    }
                    else{
                        attackPlayer(monster,p1);
                        if(p1.isDead()){
                            std::cout<<"You died\n";
                            return;
                        }
                    }
                    break;
                default:
                    std::cout<<"Invalid choice. Please enter R or F\n";
                    break;
            }
    }
        
}


int main(){
    std::string name{};
    std::cout<<"Enter your name: ";
    std::cin>>name;
    Player p1{name};

    while(!p1.hasWon() && p1.getHealth() > 0){
        fightMonster(p1);
    }

    if(p1.hasWon()){
        std::cout<<"Congrats you won!! you took away "<<p1.getGold();
    }
    else{
        std::cout<<"Unfortunately you lost... and your collected gold "<<p1.getGold()<<" is lost forever...";
    }


	return 0;
}

