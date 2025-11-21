#include<iostream>
#include<array>
#include "Random.h"

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getNum (char c){
    int num = c - '0';
    return num;
}

namespace Armor{
    enum armor{
        copper,
        iron,
        gold,
        diamond,
        netherite,
        armor_count
    };

    constexpr std::array armor_enum {
        copper,
        iron,
        gold,
        diamond,
        netherite,
    };

    constexpr std::array<std::string_view, armor_count> armor_string{
        "copper",
        "iron",
        "gold",
        "diamond",
        "netherite"
    };

    constexpr std::array<int,armor_count> armor_cost{30,40,50,66,78};
    static_assert(std::size(armor_enum) == armor_count);
    static_assert(std::size(armor_string) == armor_count);
    static_assert(std::size(armor_cost) == armor_count);
}

class Customer{
    static constexpr int get_min{80};
    static constexpr int get_max{120};
    std::string_view m_name{"???"};
    std::array<int, Armor::armor_count> cart{};
    int m_gold{0};

    public:

    explicit Customer(std::string_view name)
    : m_name{name},
      m_gold{Random::get(get_min,get_max)}
    {}

    bool buy(Armor::armor e){
        if(m_gold < Armor::armor_cost[e]){
            std::cout<<"You can't afford that\n";
            return false;
        }

        m_gold -= Armor::armor_cost[e];
        ++cart[e];
        return true;
    }

    int getGold() {return m_gold;};
    int getInventory(Armor::armor e) {return cart[e];};
};

Armor::armor buyArmor(Customer& p){
    char choice{0};
    while(true){
        std::cout<<"Enter the armor set you want to buy (q to quit): ";
        std::cin>>choice;
        if(!std::cin){
            std::cin.clear(); 
            ignoreLine();  
            std::cout << "Invalid input! Please enter a valid choice.\n";
            continue;      
        }
        ignoreLine();
        if(choice == 'q'){
            return Armor::armor_count;
        }

        int val{getNum(choice)};
        if(val >= 0 && val < Armor::armor_count){
            return static_cast<Armor::armor>(val);
        }
    }
}

void armorShop(Customer& p){
    while(true){
        std::cout<<"Here is the armor sets for today: \n";
        for(auto e : Armor::armor_enum){
            std::cout<<e<<") "<<Armor::armor_string[e]<<" armor costs: "<<Armor::armor_cost[e]<<"\n";
        }
        Armor::armor choice{buyArmor(p)};
        if(choice == Armor::armor_count){
            break;
        }
        bool success{p.buy(choice)};
        if(success){
            std::cout<<"You bought "<<Armor::armor_string[choice]<<" and you have : "<<p.getGold()<<" left\n";
        }
    }
}

void printInventory(Customer& p){
    std::cout<<"Inventory: \n";
    for(auto e : Armor::armor_enum){
        if(p.getInventory(e) > 0){
            std::cout<<e<<") "<<"Armor bought: "<<Armor::armor_string[e]<<" x"<<p.getInventory(e)<<"\n";
        }
    }
    std::cout<<"The amount of gold left is: "<<p.getGold();
}

int main(){
    std::string name{"??"};
    std::cout<<"Enter your name: ";
    std::cin>>name;
    Customer p{name};
    std::cout<<"Hello "<<name<<" You have "<<p.getGold()<<" amount of gold\n";
    armorShop(p);
    printInventory(p);
}