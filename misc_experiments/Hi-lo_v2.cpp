#include<iostream>
#include<limits>
#include "Random.h"

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool hiLO(int min, int max){
    const int numbers{Random::get(min,max)};
    int tries{};
    int guesses{};
    std::cout<<"How many tries?: ";
    std::cin>>tries;
    if (!std::cin){    
        std::cin.clear(); 
        ignoreLine();
        std::cout<<"Invalid input\n";
        return false;    
    }
    ignoreLine();
    for(int i{1}; i <= tries;){
        std::cout<<"Guess a number between 1 and 100 #"<<i<<"\n";
        std::cin>>guesses;
        if (!std::cin) {    
            std::cin.clear(); 
            ignoreLine();  
            std::cout << "Invalid input! Please enter a number.\n";
            continue;      
        }
        if(guesses <= 0 || guesses > 100){
            std::cout<<"Only put number between 1 and 100 please\n";
            continue;
        }
        if(guesses > numbers){
            std::cout<<"Your guess is too high\n";
        }
        else if(guesses < numbers){
            std::cout<<"Your guesses is too low\n";
        }
        else if(guesses == numbers){
            std::cout<<"You guessed right!\n";
            return true;
        }
        i++;
    }
    std::cout<<"Sorry you lose! the correct number was "<<numbers<<"\n";
    return false;
}

bool playAgain(bool f){
    char choice{};
    do{
        std::cout<<"Do you want to play again? (y/n)\n ";
        std::cin>>choice;
        if(choice == 'y' || choice == 'Y' ){
            return true;
        }
        else if(choice == 'n' || choice == 'N'){
            return false;
        }
        else{
            std::cout<<"Invalid input\n";
            continue;
        }
    }while(f == false);
    return true;
}


int main(){
    int min{};
    int max{};
    std::cout<<"Enter the range of the random numbers (min - max): ";
    std::cin>>min>>max;
    while(true){
        bool replay{hiLO(min,max)};
        if(!playAgain(replay)){
            return false;
        }
    }
}