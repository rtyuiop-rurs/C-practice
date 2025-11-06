#include<iostream>
#include<vector>
#include<cassert>

namespace Inventory{
    enum item{
        sword,
        shield,
        gun,
        itemcount,
    };
};

template <typename T>
constexpr std::size_t returnIdex(T type){
    return static_cast<std::size_t>(type);
}

std::string_view isPlural(Inventory::item& i){
    switch(i){
        case Inventory::gun : return " guns\n";
        break;
        case Inventory::shield : return " shields\n";
        break;
        case Inventory::sword : return " swords\n";
        break;
        default : return "none";
    }
}

std::string_view isSingular(Inventory::item& i){
    switch(i){
        case Inventory::gun : return " gun\n";
        break;
        case Inventory::shield : return " shield\n";
        break;
        case Inventory::sword : return " sword\n";
        break;
        default : return "none";
    }
}

void printInventory(std::vector<int>& arr, Inventory::item i){
    bool plural{arr[returnIdex(i)] != 1};
    std::cout<<"You have "<<arr[returnIdex(i)];
    if(plural){
        std::cout<<isPlural(i);
    }else{
        std::cout<<isSingular(i);
    }
}

void printAuto(std::vector<int>& arr){
    int elements{0};
    for(auto elemen : arr){
        elements += elemen;
    }
    std::cout<<"You have: "<<elements<<" amount of items\n";
}

int main(){
    std::vector<int> v1{1, 5, 10};
    printAuto(v1);
    for(int i = 0; i < 3; i++){
        auto item{static_cast<Inventory::item>(i)};
        printInventory(v1,item);
    }
}