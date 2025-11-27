#include<iostream>
#include<array>
#include<limits>
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

namespace Weapon{
    enum weapon{
        sword,
        shield,
        halberds,
        hammer,
        greatsword,
        weapon_count,
    };

    constexpr std::array weapon_enum {sword,
        shield,
        halberds,
        hammer,
        greatsword,
    };

    constexpr std::array<std::string_view, weapon_count> weapon_string{"sword",
        "shield",
        "halberds",
        "hammer",
        "greatsword",
    };

    constexpr std::array<int,weapon_count> weapon_cost  {12,22,25,31,45};
    static_assert(std::size(weapon_enum) == weapon_count);
    static_assert(std::size(weapon_string) == weapon_count);
    static_assert(std::size(weapon_cost) == weapon_count);
}

class Customer{
    static constexpr int get_min{100};
    static constexpr int get_max{200};
    std::string_view m_name{"???"};
    std::array<int, Armor::armor_count> cart{};
    std::array<int, Weapon::weapon_count> W_cart{};
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

    bool buyW(Weapon::weapon f){
        if(m_gold < Weapon::weapon_cost[f]){
            std::cout<<"You can't afford that\n";
            return false;
        }

        m_gold -= Weapon::weapon_cost[f];
        ++W_cart[f];
        return true;
    }

    int getGold() {return m_gold;};
    int getInventory(Armor::armor e) {return cart[e];};
    int getWeaponsInventory (Weapon::weapon f) {return W_cart[f];};
};

Armor::armor buyArmor(Customer& p){
    char choice{0};
    while(true){
        std::cout<<"Enter the armor set you want to buy (q to quit): ";
        std::cin>>choice;
        if(std::cin.peek() != '\n') {
            std::cin.clear();
            ignoreLine();
            std::cout << "Invalid input! Please enter a single character.\n";
            continue;
        }
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

        std::cout<<"Invalid choice! Please enter a number between 0 and "<<(Armor::armor_count-1)<<"\n";
    }
}

Weapon::weapon buyWeapons(Customer& p){
    char w_choice{'?'};
    while(true){
        std::cout<<"Enter the weapon you want to buy (q to quit): ";
        std::cin>>w_choice;
        if(std::cin.peek() != '\n') {
            std::cin.clear();
            ignoreLine();
            std::cout << "Invalid input! Please enter a single character.\n";
            continue;
        }
        if(!std::cin){
            std::cin.clear(); 
            ignoreLine();  
            std::cout << "Invalid input! Please enter a valid choice.\n";
            continue;      
        }
        ignoreLine();
        if(w_choice == 'q'){
            return Weapon::weapon_count;
        }

        int Wval{getNum(w_choice)};
        if(Wval >= 0 && Wval < Weapon::weapon_count){
            return static_cast<Weapon::weapon>(Wval);
        }

        std::cout<<"Invalid choice! Please enter a number between 0 and "<<(Weapon::weapon_count-1)<<"\n";
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

void weaponShop(Customer& p){
    while(true){
        std::cout<<"Here is the weapons for today: \n";
        for(auto e : Weapon::weapon_enum){
            std::cout<<e<<") "<<Weapon::weapon_string[e]<<" Weapons costs: "<<Weapon::weapon_cost[e]<<"\n";
        }
        Weapon::weapon choice{buyWeapons(p)};
        if(choice == Weapon::weapon_count){
            break;
        }
        bool success{p.buyW(choice)};
        if(success){
            std::cout<<"You bought "<<Weapon::weapon_string[choice]<<" and you have: "<<p.getGold()<<" left\n";
        }
    }
}

void printInventory(Customer& p){
    std::cout<<"\n=== FINAL INVENTORY ===\n";
    
    bool hasArmor = false;
    bool hasWeapons = false;
    
    std::cout<<"Armor:\n";
    for(auto e : Armor::armor_enum){
        if(p.getInventory(e) > 0){
            std::cout<<"  - "<<Armor::armor_string[e]<<" set x"<<p.getInventory(e)<<"\n";
            hasArmor = true;
        }
    }
    if(!hasArmor){
        std::cout<<"  (no armor)\n";
    }
    
    std::cout<<"Weapons:\n";
    for(auto f : Weapon::weapon_enum){
        if(p.getWeaponsInventory(f) > 0){
            std::cout<<"  - "<<Weapon::weapon_string[f]<<" x"<<p.getWeaponsInventory(f)<<"\n";
            hasWeapons = true;
        }
    }
    if(!hasWeapons){
        std::cout<<"  (no weapons)\n";
    }
    
    std::cout<<"Gold left: "<<p.getGold()<<"\n";
    std::cout<<"======================\n";
}

int main(){
    std::string name{"??"};
    std::cout<<"Enter your name: ";
    std::cin>>name;
    ignoreLine(); 
    
    Customer p{name};
    std::cout<<"Hello "<<name<<"! You have "<<p.getGold()<<" gold.\n";
    
    while(true){
        std::cout<<"\nWhere would you like to go?\n";
        std::cout<<"1) Armor Shop\n";
        std::cout<<"2) Weapon Shop\n"; 
        std::cout<<"3) Show Inventory & Exit\n";
        std::cout<<"Enter your choice: ";
        
        int choice{0};
        std::cin>>choice;
        ignoreLine(); 
        
        if(choice == 1){
            armorShop(p);
        }
        else if(choice == 2){
            weaponShop(p);
        }
        else if(choice == 3){
            break;
        }
        else{
            std::cout<<"Invalid choice! Please enter 1, 2, or 3.\n";
        }
    }
    
    printInventory(p);
}