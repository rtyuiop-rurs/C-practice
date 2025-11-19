#include<iostream>
#include "Random.h"

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void drawUI(){
    std::cout<<"WELCOME TO ROCK PAPER SCISSOR!\n";
    std::cout<<"1.ROCK\n";
    std::cout<<"2.SCISSOR\n";
    std::cout<<"3.PAPER\n";
}

int getInput(){
    while(true){
        int choice{0};
        std::cout<<"Enter Your Choice!!:";
        std::cin>>choice;
        if(!std::cin){
            std::cin.clear();
            ignoreLine();
            std::cout<<"That wasn't a valid input.  Try again.\n";
            continue;
        }
        ignoreLine();
        if(choice < 1 || choice > 3){
            std::cout<<"That wasn't a valid input.  Try again.\n";
            continue;
        }
        if(choice == 1){
            std::cout<<"YOU chose ROCK!\n";
        }
        else if(choice == 2){
            std::cout<<"YOU chose SCISSOR!\n";
        }
        else{
            std::cout<<"YOU chose PAPER!\n";
        }
        return choice;
    }
}

int getRandomAnswer(){
    int comp{Random::get(1,3)};

    if(comp == 1){
        std::cout<<"I chose ROCK!\n";
    }
    else if(comp == 2){
        std::cout<<"I chose SCISSOR!\n";
    }
    else{
        std::cout<<"I chose PAPER!\n";
    }
    return comp;
}

void GameLogic(int choice, int randChoice){
    if(choice == randChoice){
        std::cout<<"ITS A DRAW!!\n";
    }
   else if(randChoice == 2 && choice == 1 || randChoice == 1 && choice == 3 || randChoice == 3 && choice == 2){
        std::cout<<"I LOST!!\n";
    }
    else if(choice == 2 && randChoice == 1 || choice == 1 && randChoice == 3 || choice == 3 && randChoice == 2){
        std::cout<<"YOU LOST!!\n";
    }
}


int main(){
    int choice{1};
    do{
        drawUI();
        int player{getInput()};
        int rand{getRandomAnswer()};
        GameLogic(player,rand);
        std::cout<<"Enter 0 to exit or any number to play again: ";
        std::cin>>choice;
    }while(choice != 0);
}
