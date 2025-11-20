#include<iostream>
#include<array>
#include<limits>
#include "Random.h"

int charNumToInt(char c){
    return c - '0';
}

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

namespace Potion{
    enum Type{
        healing,
        mana,
        speed,
        invincibility,
        potion_count,
    };

    constexpr std::array<std::string_view, potion_count> potionStrings{
        "healing","mana","speed","invincibility"
    };
    constexpr std::array types{healing, mana, speed, invincibility};
    constexpr std::array<int,potion_count> potion_cost{20,30,12,50};
    static_assert(std::size(potionStrings) == potion_count);
    static_assert(std::size(types) == potion_count);
    static_assert(std::size(potion_cost) == potion_count);
}

class Player{
    static const int Max_gold{120};
    static const int Min_gold{80};
    std::string_view m_name{"???"};
    int m_gold{0};
    std::array<int, Potion::potion_count> m_inventory{}; 

    public:
    explicit Player(std::string_view name): 
        m_name{name},m_gold{Random::get(Min_gold,Max_gold)}
    {};

    bool buy(Potion::Type p){
        if(m_gold < Potion::potion_cost[p]){
            return false;
        }

        m_gold -= Potion::potion_cost[p];
        ++m_inventory[p];
        return true;
    }

    int getGold() {return m_gold;};
    int getInventory(Potion::Type p) const {return m_inventory[p];}; 
};

Potion::Type getInput(){
    char choice{};
    while(true){
        std::cout<<"Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        std::cin>>choice;
        if(!std::cin){
            std::cin.clear();
            ignoreLine();
            std::cout<<"That wasn't a valid input.  Try again.\n";
            continue;
        }
        if(choice == 'q')
            return Potion::potion_count;
       
        int val {charNumToInt(choice)};
        if(val >=0 && val < Potion::potion_count)
            return static_cast<Potion::Type>(val);

        std::cout << "I didn't understand what you said.  Try again: ";
        ignoreLine();
    }
}

void printShop(Player& p){
    while(true){
        std::cout<<"Here's our selection for today: \n";
        for(auto e : Potion::types){
            std::cout<<e<<") "<<Potion::potionStrings[e]<<" costs "<<Potion::potion_cost[e]<<"\n";
        }
        Potion::Type choice {getInput()};
        if(choice == Potion::potion_count)
            return;

        bool success{p.buy(choice)};
        if(!success){
            std::cout<<"Sorry, you can't afford that";
        }
        else{
            std::cout<<"You bought: "<<Potion::potionStrings[choice]<<" and you have: "<<p.getGold()<<" gold left\n";
        }
    }
}

void printInventory(Player& p){
    std::cout<<"Your inventory is : \n";
    for(auto e: Potion::types ){
        if(p.getInventory(e) > 0){
            std::cout<<p.getInventory(e)<<" x amount potion of "<<Potion::potionStrings[e]<<"\n";
        }
    }

    std::cout<<"The amount of gold left is: "<<p.getGold()<<"\n";
}

int main(){
    std::cout<<"Enter your name: ";
    std::string name{"???"};
    std::cin>>name;
    Player v{name};
    std::cout<<"Hello "<< name << " you have "<< v.getGold() << " gold " <<"\n";
    printShop(v);
    std::cout<<"\n";
    printInventory(v);
}