#include<iostream>

int main(){
    char x{};
    std::cout<<"Enter a single character: ";
    std::cin>>x;
    std::cout<<"You've entered "<<x<<" Which is ASCII code for "<<static_cast<int>(x);
}