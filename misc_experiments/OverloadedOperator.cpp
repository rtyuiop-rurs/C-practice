#include<iostream>
#include<string>
#include<optional>
#include<limits>
#include<string_view>

enum MonsterType{
    orc,
    goblin, 
    ogre, 
    troll,
    skeleton,
};

constexpr std::string_view getMonsterName(MonsterType& monster){

    switch(monster){
        case orc:  return "Orc";
        case goblin: return "Goblin"; 
        case ogre: return "Ogre";              
        case troll: return "Troll" ; 
        case skeleton: return "Skeleton";
        default: return "ERROR";
    };
}

constexpr std::optional<MonsterType>getMonsterString(std::string_view sv){
    if(sv == "orc" || sv == "Orc") return orc;
    if(sv == "goblin" || sv == "Goblin") return goblin;
    if(sv == "troll" || sv == "Troll") return troll;
    if(sv == "skeleton" || sv == "Skeleton") return skeleton;

    return {};
}

std::istream& operator>>(std::istream& in, MonsterType& monster){
    std::string s{};
    in >> s;
    std::optional match{getMonsterString(s)};
    
    if(match){
        monster = *match;
        return in;
    }
    in.setstate(std::ios_base::failbit);
    return in;
    
}

std::ostream& operator<<(std::ostream& out, MonsterType monster)
{
    return out << getMonsterName(monster);  
}


int main() {
    std::cout<<"Enter a monster: ";
    MonsterType mon1{};
    std::cin>>mon1;
    
    if(std::cin){
        std::cout<<"Your monster is: "<< mon1;
    }
    else{
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Your monster was invalid";
    }

    return 0;
}