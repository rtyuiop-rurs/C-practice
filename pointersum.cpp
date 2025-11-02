#include<iostream>

void squared(int* f, int* g){
    if(*f > *g){
        std::cout<<"The first number is bigger";
    }
    else{
        std::cout<<"The second number is larger";
    }
}

int main(){
    int x{};
    int y{};
    std::cout<<"Enter two numbers: ";
    std::cin>>x>>y;
    squared(&x, &y);
}
