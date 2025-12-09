#include<iostream>


int recursive(int x){
    if(x == 0){
        return 1;
    }
    
    return x * recursive(x - 1);
}       

int main(){
    std::cout<<"Enter a number: ";
    int num{0};
    std::cin>>num;
    int factorial{recursive(num)};
    std::cout<<factorial;
}