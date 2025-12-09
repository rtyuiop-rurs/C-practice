#include<iostream>
#include<limits>
#include<functional>

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int add(int x,int y){
    return x+y;
}

int subtract(int x, int y){
    return x - y;
}

int divide(int x, int y){
    return x / y;
}

int multiply(int x, int y){
    return x * y;
}

char getoperations(){
    std::cout<<"Enter your operations <( +, - , * , / >: ";
    while(true){
        char op{'?'};
        std::cin>>op;
        if(!std::cin){
            std::cin.clear();
            ignoreLine();
            std::cout<<"That wasn't a valid input.  Try again.\n";
            continue;
        }
        ignoreLine();
        if(op != '+' && op != '-' && op != '*' && op != '/'){
            std::cout<<op<<" is not an operation try again: ";
            continue;
        }
        return op;
    }
}

int getNum(){
    int x{0};
    std::cout<<"Enter a number: ";
    std::cin>>x;
    return x;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char c){
   switch(c){
    case '+' : return &add;
    case '-' : return &subtract;
    case '/' : return &divide;
    case '*' : return &multiply;
    default : return nullptr;
   };
}

int main(){
    int x{getNum()}; 
    int y{getNum()};
    char op{getoperations()};
    ArithmeticFunction fcn {getArithmeticFunction(op)};
    std::cout<<fcn(x,y);
}