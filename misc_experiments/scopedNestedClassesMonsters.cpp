#include<iostream>
#include<string>
#include<string_view>
#include "Random.h"
#include<random>

class Monster{
    public:
        enum Type{
            Dragon,
            Goblin,
            Ogre,
            Orc,
            Skeleton,
            Troll,
            Vampire,
            Zombie,
            maxMonsterTypes,
        };
    private:
        Type m_type;
        std::string m_name{"???"};
        std::string m_roar{"???"};
        int m_hitpoints{0};

    public:
    Monster(Type type, std::string name, std::string roar, int hitpoint)
    : m_type{type}, m_name{name}, m_roar{roar}, m_hitpoints{hitpoint}
    {
    }

    constexpr std::string_view getTypeString()const{
        switch(m_type){
            case Dragon : return "Dragon";
            case Goblin : return "Goblin";
            case Ogre   : return "Ogre";
            case Orc    : return "Orc";
            case Skeleton : return "Skeleton";
            case Troll   : return "troll";
            case Vampire : return "Vampire";
            case Zombie  : return "Zombie";
            default: return "none";
        };
    }

   
    std::string getName() {return m_name;};
    std::string getRoar() const {return m_roar;};
    int getHP() const {return m_hitpoints;};

    void print(){
        std::cout<<m_name<<" "<<"the "<<getTypeString()<<" has "<<m_hitpoints<< " hitpoints and says "<<m_roar<<"\n";
    }

};

namespace MonsterGenerator{
    std::string MonsterName(int i){
        switch(i){
            case 1 : return "Briggs";
            case 2 : return "Manny";
            case 3 : return "Vargas";
            case 4 : return "Jimmy";
            case 5 : return "Klein";
            default : return "null";
        }
    }

    std::string MonsterRoar(int i){
        switch(i){
            case 1 : return "*roar*";
            case 2 : return "*screams*";
            case 3 : return "*vibrates*";
            case 4 : return "*rattles*";
            case 5 : return "*shouts*";
            default : return "*taunt*";
        }
    }

    Monster::Type generateType(int i){
        switch(i){
            case 1 : return Monster::Dragon;
            case 2 : return Monster::Goblin;
            case 3 : return Monster::Ogre;
            case 4 : return Monster::Orc;
            case 5 : return Monster::Skeleton;
            case 6 : return Monster::Troll;
            case 7 : return Monster::Vampire;
            case 8 : return Monster::Zombie;
            default: return Monster::maxMonsterTypes;
        }

    }


    Monster generate(){
        return Monster{ generateType(Random::get(1,8)), MonsterName(Random::get(0,5)), MonsterRoar(Random::get(0,5)), Random::get(1,100)};
    }

}


int main(){
	Monster m{ MonsterGenerator::generate() };
	m.print();
    Monster p{MonsterGenerator::generate()};
    p.print();


	return 0;
}