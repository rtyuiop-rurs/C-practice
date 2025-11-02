#include<iostream>

int calculate(int x, int y, char z){

    switch(z)
    {
        case '+':
            return x + y;
            break;
        case '-':
            return x - y;
            break;
        case '*':
            return x * y;
            break;
        case '/':
            return x / y;
            break;
        case '%':
            return x % y;
            break;
        default:
            std::cout<<"Error";
            return 0;
            break;
    }
}

int main(){
    int x{};
    int y{};
    char z{};

    std::cout<<"Enter two integers: ";
    std::cin>>x>>y;

    std::cout<<"Enter an operation +,-,*,/,%: ";
    std::cin>>z;

    int f{calculate(x,y,z)};
    std::cout<<"Results: "<<f<<"\n";

    return 0;

}