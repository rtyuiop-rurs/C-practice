#include<iostream>

constexpr int isEven(int x){
    return (x % 2) == 0;
}

int main(){

    std::cout<<"Enter a number : ";
    int x{};
    std::cin>>x;

    if(isEven(x)){
        std::cout<<x<<" Is even";
    }
    else{
        std::cout<<x<<" Is odd";
    }

}
