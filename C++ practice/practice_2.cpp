#include<iostream>

int getinput(){
    int input{0};
    int even{0};
    int odd{0};
    int sum{0};
    for(int i=1; i<=10; i++){
        std::cout<<"enter 10 numbers: ";
        std::cin>>input;
        if((input % 2) == 0){
            even++;
        }
        else{
            odd++;
        }
        sum += input;
    }
    std::cout<<"there are "<<even<<" even numbers\n";
    std::cout<<"there are "<<odd<<" odd numbers\n";
    std::cout<<"The sum is "<<sum;
    return 0;
}

int main(){
    getinput();
    return 0;
}