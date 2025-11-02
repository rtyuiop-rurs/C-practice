#include<iostream>
#include "Random.h"

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(){
    bool playgame{true};
    int numbers{Random::get(1,100)};
    int answer{};
    char choice{};
    int tries{};
    while(playgame){
        bool won{false};
        std::cout<<"How many tries do you want?";
        std::cin>>tries;
        for(int i = 1; i <= tries; i++){
            std::cout<<"Guess a number between 1 and 100 #"<<i<<"\n";
            std::cin>>answer;
            if(answer > numbers)
                std::cout<<"too high"<<"\n";
            if(answer < numbers)
                std::cout<<"too low"<<"\n";
            if(answer == numbers){
                std::cout<<"Correct! You win!";
                won = true;
                break;
            }
        }
        if(!won){
            std::cout<<"Sorry, you lose. The correct number was "<<numbers<<".\n";
        }
        std::cout<<"Would you like to play again (y/n)?";
        std::cin>>choice;
        if(choice == 'n'){
            std::cout<<"Thank you for playing";
            playgame = false;
        }
        else if(choice == 'y'){
            playgame = true;
        }
    }
}