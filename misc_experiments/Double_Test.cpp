#include<iostream>

double value(){
    double x{};
    std::cout<<"Enter a double value: ";
    std::cin>>x;
    return x;
}

char operation(){
    char opp{};
    std::cout<<"Enter +, -, *, or /: ";
    std::cin>>opp;
    return opp;
}

void calc(double x, double y, char opp){
    if(opp == '-'){
        std::cout<<x<<" - "<<y<<" = "<<x - y;
    }
    else if( opp == '+'){
        std::cout<<x<<" + "<<y<<" = "<<x + y;
    }
    else if( opp == '*'){
        std::cout<<x<<" * "<<y<<" = "<<x * y;
    }
    else if(opp == '/'){
        std::cout<<x<<" / "<<y<<" = "<<x / y;
    }
    else{
        return;
    }
}

int main(){
    double x{value()};
    double y{value()};
    char f{operation()};
    calc(x,y,f);
}