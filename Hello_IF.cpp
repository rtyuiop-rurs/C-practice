#include<iostream>

int choice(){
    std::cout<<"Enter a number from 0 to 9: ";
    int x{};
    std::cin>>x;
    return x;
} 

int main(){
    int x{choice()};
    if(x == 0){
        std::cout<<"Your number is not a prime number";
    }
    else if(x == 1 || x == 4 || x == 7){
        std::cout<<"Your number is not a prime number";
    }
    else{
        std::cout<<"Your number is a prime number";
    }
}