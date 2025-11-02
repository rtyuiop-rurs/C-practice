#include <iostream>
#include<string>
#include<optional>
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


int main() {
    std::cout << "Enter a Monster: ";
    std::string Monster{};
    std::cin>>Monster;

    std::optional<MonsterType> mon1{getMonsterString(Monster)}; 

    if(!mon1){
        std::cout<<"You've entered invalid Monster!\n";
    }else{
        std::cout<<"You've entered : "<<getMonsterName(*mon1);
    }

    return 0;
}