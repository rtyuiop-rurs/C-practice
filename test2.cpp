#include<iostream>

int main(){
    std::cout<<"Last number?: ";
    int number;
    std::cin>>number;
    int sum = 1;
    int i = 0;
    while( i < number){
        i++;
        sum *= i;
    }
    std::cout<<"Sum factorial: "<<sum;

}