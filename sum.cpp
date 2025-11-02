#include <iostream>

int getnum(){
    std::cout<<"Enter two number: ";
    int x{};
    int y{};
    std::cin>>x>>y;
    return x+y;
}

int main(){
    int sum{getnum()};
    std::cout<<sum;
}