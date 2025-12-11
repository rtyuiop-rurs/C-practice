#include<iostream>
#include<functional>

char getOperation(){
    char op{'?'};
    std::cout<<"Enter your operations: <+,-,/,*>: ";
    std::cin>>op;
    return op;
}

int add(int x, int y){
    return x + y;
}

int substract(int x, int y){
    return x - y;
}

int divide(int x, int y){
    return x / y;
}

int multiply(int x, int y){
    return x * y;
}

using Arithmetic = std::function <int(int,int)>;

Arithmetic getArithmetic(char op){
    switch(op){
        case '+' : return &add;
        case '-' : return &substract;
        case '/' : return &divide;
        case '*' : return &multiply;
        default : return nullptr;
    }
}

int main(){
    int x{0};
    int y{0};
    std::cout<<"Enter your numbers: ";
    std::cin>>x>>y;
    Arithmetic fcn{getArithmetic(getOperation())};
    std::cout<<fcn(x,y);
}