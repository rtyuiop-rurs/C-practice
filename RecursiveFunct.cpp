#include<iostream>

int recursive(int x){
    int total{0};
    int last_num{0};
    total += x % 10;
    last_num += x / 10;
    if(last_num == 0){
       return total;
    }
    return total + recursive(last_num) ;
}

int main(){
    std::cout<<"Enter your number: ";
    int num{0};
    std::cin>>num;
    int total{recursive(num)};
    std::cout<<total;
}
