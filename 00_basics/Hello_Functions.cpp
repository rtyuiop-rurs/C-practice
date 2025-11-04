#include<iostream>

int returnNUM(){
    return 5;
}
int takeInput(){
    std::cout<<"Enter a number: "<<std::endl;
    int x;
    std::cin>>x;
    std::cout<<"This is the number you've inputted: "<<x<<std::endl;
    return x;
}
int main(){
    int takeValue{takeInput()};
    int returnValue{returnNUM()};
    std::cout<<"This is your number times 2: "<<takeValue*2<<std::endl;
    std::cout<<"This is your number times 5: "<<takeValue*returnValue<<std::endl;
}