#include<iostream>
#include<array>

int main(){
    constexpr std::array<double, 365> temp{};
    std::array hello{"H","E","L","L","O"};
    double sum;

    for(int i = 0; i < 5; i++){
        std::cout<<hello[i];
    }
}