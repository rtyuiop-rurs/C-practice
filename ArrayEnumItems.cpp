#include<iostream>
#include<vector>
#include<cassert>

namespace Player{
    enum items{
        health_potion,
        torches,
        arrows,
        itemCount,
    };
}

const std::string_view returnItemS(Player::items i){
    switch(i){
        case Player::health_potion : return "health potion";
        break;
        case Player::torches : return "torch";
        break;
        case Player::arrows : return "arrow";
        break;
        default: return "none";
    }
}

const std::string_view returnItemP(Player::items i){
    switch(i){
        case Player::health_potion : return "health potions";
        break;
        case Player::torches : return "torches";
        break;
        case Player::arrows : return "arrows";
        break;
        default: return "none";
    }
}

template <typename T>
constexpr std::size_t converter(T value){
    static_assert(std::is_integral<T>() || std::is_enum<T>());

    return static_cast<std::size_t>(value); //convert enum index into array index;
}

void printInventory(const std::vector<int>& inventory, Player::items i){
    bool plural{inventory[converter(i)] != 1}; 
    std::cout<<"You have: "<<inventory[converter(i)];
    std::cout<<(plural ?  returnItemP(i) : returnItemS(i))<<"\n";
}

void printHold(std::vector<int>& arr){
    int elements{0};
    std::string itemName{"none"};

    for(auto elemen : arr){
        elements += elemen;
    }
    
    std::cout<<"Number of items hold: "<<elements;
}

int main(){
    std::vector inventory{1,5,10};
    assert(std::size(inventory) == Player::itemCount);
    for(int i = 0; i < Player::itemCount; i++){
        auto item{static_cast<Player::items>(i)};
        printInventory(inventory,item);
    }

    printHold(inventory);
}





