#include<iostream>
#include<vector>
int getSum(int last_num){
    int sum{0};
    int i = 0;
    std::vector<int> odd_num;
    std::vector<int> even_num;
    while(i < last_num){
        i++;
        if( i % 2 == 0){
            even_num.push_back(i);
        }
        else{
            odd_num.push_back(i);
        }
        sum += i;

    }

    std::cout<<"EVEN NUMBERS\n";
    for(auto i : even_num){
        std::cout<<i<<" ";
    }

    std::cout<<"\nODD NUMBERS\n";
    for(auto i : odd_num){
        std::cout<<i<<" ";
    }

    return sum;
}

int getFactorialSum(int last_num){
    int sum{1};
    int i = 1;
    std::vector<int> odd_num;
    std::vector<int> even_num;

    while(i < last_num){
        i++;
        sum *= i;
        if(i % 2 == 0){
            even_num.push_back(i);
        }
        else{
            odd_num.push_back(i);
        }
    }

    std::cout<<"EVEN NUMBERS\n";
    for(auto i : even_num){
        std::cout<<i<<" ";
    }

    std::cout<<"\nODD NUMBERS\n";
    for(auto i : odd_num){
        std::cout<<i<<" ";
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

    std::cout<<"\nSUM\n";
    std::cout<<sum<<"\n";
}