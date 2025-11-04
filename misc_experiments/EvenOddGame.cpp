#include<iostream>
#include<limits>
#include<string>
#include "Random.h"

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool evenOdd(int min, int max){
    const int num{Random::get(min, max)};
    int tries{};
    std::string guesses{};
    std::cout<<"How many tries?: ";
    std::cin>>tries;
    if(!std::cin){
        std::cin.clear(); 
        ignoreLine();
        std::cout<<"Invalid input\n";
        return false;    
    }
    ignoreLine();
    for(int i = 1; i <= tries;){
        std::cout<<"Guess if the number is Even or Odd #"<<i<<"\n";
        std::cin>>guesses;
         if (!std::cin) {    
            std::cin.clear(); 
            ignoreLine();  
            std::cout << "Invalid input! Please enter a number.\n";
            continue;      
        }
        if(guesses != "even" && guesses != "odd"){
            std::cout<<"Only put even and odd please\n";
            continue;
        }
        if(num % 2 == 0 && guesses == "even"){
            std::cout<<"You got it right!\n";
            std::cout<<"The number was: "<<num<<"\n";
            return true;
        }
        else if(num % 2 != 0 && guesses == "odd"){
            std::cout<<"You got it right!\n";
            std::cout<<"The number was: "<<num<<"\n";
            return true;
        }
        i++;
    }
    std::cout<<"Sorry you lose! the  number was "<<num<<"\n";
    return false;

}

bool playAgain(bool f){
    char choice{};
    do{
        std::cout<<"Do you want to play again? (y/n)\n ";
        std::cin>>choice;
        if (choice == 'y' || choice == 'Y') return true;
        if (choice == 'n' || choice == 'N') return false;
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
        bool playgame{evenOdd(min, max)};
        if(!playAgain(playgame)){
            return false;
        }
    }

    return 0;
}


