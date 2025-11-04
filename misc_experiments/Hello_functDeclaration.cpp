#include<iostream>

int minus(int x, int y);

int main(){
    std::cout<<"x - y = "<<minus(5,6);
}

int minus(int x, int y){
    return x - y;
}