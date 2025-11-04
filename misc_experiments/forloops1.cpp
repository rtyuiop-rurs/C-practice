#include<iostream>

int sumTo(int x){
    int sum{0};
    for(int i=1; i <= x; i++){
        sum += i;
        std::cout<<i;
        if(i < x){
            std::cout<<" + ";
        }
    }
    return sum;
}

int main(){
    std::cout<<"Enter a number to sum to: ";
    int y{};
    std::cin>>y;
    int x{sumTo(y)};
    std::cout<<" = "<<x;
}