#include<iostream>
#include<string>
#include<string_view>

struct Monster{
    enum MonsterType{
        ogre,
        dragon,
        orc,
        spider,
        slime
    };
    MonsterType type;
    std::string name{};
    int health{};
};

constexpr std::string_view printMonsterType(Monster& m1){
    switch(m1.type){
        case Monster::ogre: return "ogre"; break;
        case Monster::dragon: return "dragon"; break;
        case Monster::orc: return "orc"; break;
        case Monster::spider: return "giant spider"; break;
        case Monster::slime: return "slime"; break;
        default: return "unknown";
    };
}

void printMonster(Monster& m1){
   std::cout<<"This "<<printMonsterType(m1)<<" is named "<<m1.name<<" and has "<<m1.health<<" health\n";
}



int main(){
    Monster m1{Monster::ogre, "Torg", 145};
    Monster m2{Monster::slime, "Blurp", 23};
    printMonster(m1);
    printMonster(m2);

}


