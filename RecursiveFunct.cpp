#include<iostream>
#include<functional>

int choice(){
    std::cout<<"Enter your choice <1 for factorial, 2 for sum>: ";
    int choice{0};
    std::cin>>choice;
    return choice;
}

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

int factorial(int x){
    if(x == 0){
        return 1;
    }

    return x + factorial(x - 1);
}

using ArithmeticFunction = std::function <int(int)>;

ArithmeticFunction getFunction(int x){
    switch(x){
        case 1 : return &factorial;
        case 2 : return &recursive;
        default : return nullptr;
    }
}

int main(){
    std::cout<<"Enter your number: ";
    int num{0};
    std::cin>>num;
    int ch{choice()};
    ArithmeticFunction fcn{getFunction(ch)};
    std::cout<<fcn(num);
}
