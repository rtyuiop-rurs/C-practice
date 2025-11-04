#include<iostream>
#include <string>

int main(){
    std::cout<<"Enter your name: ";
    std::string name{};
    std::getline(std::cin>>std::ws, name);
    std::cout<<"Enter a your age: ";
    int x{};
    std::cin>>x;
    int lent{static_cast<int>(name.length())};
    std::cout<<"Your name"<<" + "<<"length of name is: "<<lent + x;
    
}