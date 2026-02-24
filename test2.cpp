#include<iostream>
int getSum(int last_num){
    int sum{0};
    int i = 0;
    while(i < last_num){
        i++;
        sum += i;
    }

    return sum;
}

int getFactorialSum(int last_num){
    int sum{1};
    int i = 1;
    while(i < last_num){
        i++;
        sum *= i;
    }

    return sum;
}


int main(){
    std::cout<<"Last number?: ";
    int number;
    std::cin>>number;
    char choice{'?'};
    std::cout<<"Is factorial?: ";
    std::cin>>choice;
    int sum{0};

    if(choice == 'y'){
        sum = getFactorialSum(number);
    }else{
       sum =  getSum(number);
    }

    std::cout<<sum<<"\n";
}