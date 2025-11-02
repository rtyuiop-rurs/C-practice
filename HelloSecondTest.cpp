#include<iostream>
int main(){
    std::cout<<"Enter a integer: ";
    int x{}, y{};
    std::cin>>x;
    std::cout<<"Enter a second integer: ";
    std::cin>>y;
    std::cout<<x<<" + "<<y<<" is : "<<x+y<<".\n";
    std::cout<<x<<" - "<<y<<" is : "<<x-y<<".\n";
    return 0;
}