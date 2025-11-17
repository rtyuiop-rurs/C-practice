#include<iostream>

constexpr int square[] {0, 1, 4, 9};

void getTrueNUm(int answer){
    const int index{4};
    bool correct{false};
    for(std::size_t i = 0 ; i < 4; i++ ){
        if(square[i] == answer){
            correct = true;
            std::cout<<answer<<" is a perfect square";
        }
    }
    if(!correct && answer != -1){
        std::cout<<answer<<" is not a perfect square";
    }
}

int main(){
    int answer{0};
    do{
        std::cout<<"Enter a number (-1) to quit: ";
        std::cin>>answer;
        getTrueNUm(answer);

    }while(answer != -1);
}