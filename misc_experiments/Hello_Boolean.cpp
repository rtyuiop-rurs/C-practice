#include<iostream>

bool prime(int x){
    if(x==2 || x == 3 || x == 5 || x == 7){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    std::cout<<"Enter a number from 0 to 9 : ";
    int x{};
    std::cin>>x;
    if(prime(x)){
        std::cout<<"the number is a prime number";
    }
    else{
        std::cout<<"the number is not a prime number";
    }
}