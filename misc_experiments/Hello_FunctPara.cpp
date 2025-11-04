#include<iostream>
int returnNum(){
    std::cout<<"Enter a integer: ";
    int x{};
    std::cin>>x;
    return x;
}

int doubleNumber(int x){
    return x*2;
}

int main(){
    returnNum;
    std::cout<<doubleNumber(returnNum());
}