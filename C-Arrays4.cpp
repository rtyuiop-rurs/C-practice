#include<iostream>
#include<array>

struct Gold{
    std::string_view name{" "};
    int gold{0};
};

template <typename T, std::size_t N>
void printArray(const std::array<T,N>& arr){
    for(const auto& item : arr){
        std::cout<<"A "<<item.name<<" costs: "<<item.gold<<" gold";
        std::cout<<"\n";
    }
}


int main(){
    constexpr std::array<Gold, 4> price{{
        {"sword", 5},
        {"dagger", 3},
        {"club", 2},
        {"spear", 7},
    }};
    printArray(price);
}
