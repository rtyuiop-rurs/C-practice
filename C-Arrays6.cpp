#include<iostream>

constexpr int square[] {0,1,4,9};

void getAnswer(int answer){
    bool correct{false};
    constexpr int index{4};
    for(std::size_t i = 0; i < index; i++){
        if(square[i] == answer){
            correct = true;
            std::cout<<answer<<" is a perfect square!\n";
        }
    }

    if(!correct  && answer != -1){
        std::cout<<answer<<" is not a perfect square!\n";
    }
}

int main(){
    int answer{0};
    do{
        std::cout<<"Enter a number (-1 to exit): ";
        std::cin>>answer;
        getAnswer(answer);
    }while(answer != -1);

    return 0;
}