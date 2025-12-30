#include<iostream>
#include "Random.h"

int getRandnum(){
    std::cout<<"Choose your range of numbers: ";
    int min{0};
    int max{0};
    std::cin>>min>>max;
    int randNum{Random::get(min,max)};
    return randNum;
}

int getTries(){
    std::cout<<"Enter the amount of tries: ";
    int tries{0};
    std::cin>>tries;
    return tries;
}

void Game(){
    std::cout<<"Welcome to High-Low Game!\n";
    int rand{getRandnum()};
    std::cout<<"Instructions: Guess the number!:\n";
    int tries{getTries()};
    do{
        int answer{0};
        std::cout<<"Enter the correct Number: ";
        std::cin>>answer;
        if(answer < rand && tries > 0){
            std::cout<<"A little higher!\n";
            tries--;
        }
        if(answer > rand && tries > 0){
            std::cout<<"A little lower!\n";
            tries--;
        }
        if(answer == rand){
            std::cout<<"Congrats! you got the right answer!\n";
            break;
        }
    }while(tries > 0);

    if(tries == 0){
        std::cout<<"Sorry you lost! the actual number was: "<<rand<<"\n";
    }

}

int main(){
    char choice{'?'};
    while(true){
        Game();
        std::cout<<"Do you want to play again? <Y for yes and N for no>: ";
        std::cin>>choice;
        if(choice == 'N'){
            break;
        }
        else{
            continue;
        }
    }
}