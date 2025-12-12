#include<iostream>
#include "Random.h"

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char getDifficulty(){
    while(true){
        std::cout<<"Enter the difficulty you want <E for easy, M for medium and H for hard>: ";
        char d{'?'};
        std::cin>>d;
        if(!std::cin){
            std::cin.clear();
            ignoreLine();
            std::cout<<"That wasn't a valid input.  Try again.\n";
            continue;
        }
        ignoreLine();
        if(d != 'H' && d!= 'E' && d!= 'M'){
            std::cout<<"That wasn't a valid input.  Try again.\n";
            continue;
        }
        if(d == 'E'){
            std::cout<<"YOU chose Easy difficulty\n";
        }
        else if(d == 'M'){
            std::cout<<"YOU chose Medium difficulty!\n";
        }
        else{
            std::cout<<"YOU chose Hard difficulty!\n";
        }
        return d;
    }
}

int getInput(){
    std::cout<<"1.ROCK\n";
    std::cout<<"2.SCISSOR\n";
    std::cout<<"3.PAPER\n";
    std::cout<<"===========================\n";
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

void GameLogic(int choice, int randChoice, int& lives, int& f_lives, char diff){
    if(choice == randChoice){
        std::cout<<"ITS A DRAW!!\n";
        std::cout<<"===========================\n";
        std::cout<<"My lives: "<<f_lives<<"\n";
        std::cout<<"Your lives: "<<lives<<"\n";
    }
   else if(randChoice == 2 && choice == 1 || randChoice == 1 && choice == 3 || randChoice == 3 && choice == 2){
        std::cout<<"I LOST!!\n";
        f_lives--;
        std::cout<<"===========================\n";
        std::cout<<"My lives: "<<f_lives<<"\n";
    }
    else if(choice == 2 && randChoice == 1 || choice == 1 && randChoice == 3 || choice == 3 && randChoice == 2){
        std::cout<<"YOU LOST!!\n";
        if(diff == 'E')
            lives--;
        if(diff == 'M')
            lives -= 2;
        if(diff == 'H')
            lives -= 3;
        std::cout<<"===========================\n";
        std::cout<<"Your lives: "<<lives<<"\n";
    }
}

bool playAgain(){
    char choice{};
    while(true){
        std::cout<<"Do you want to play again? (y/n)\n ";
        std::cin>>choice;
        ignoreLine();
        if(choice == 'y' || choice == 'Y' ){
            return true;
        }
        else if(choice == 'n' || choice == 'N'){
            return false;
        }
        else{
            std::cout<<"Invalid input\n";
        }
    }
}



int main(){
    do{
        std::cout<<"WELCOME TO ROCK PAPER SCISSOR!\n";
        char diff(getDifficulty());
        int lives{6};
        int f_lives{6};
        while(lives > 0 && f_lives > 0){
            int player{getInput()};
            int rand{getRandomAnswer()};
            GameLogic(player,rand,lives,f_lives,diff);
             if(lives == 0){
                std::cout<<"Well looks like you lost, :)\n";
                break;
            }
            if(f_lives == 0){
                std::cout<<"No way...."<<":(\n";
                break;
            }
        }

    }while(playAgain());
    std::cout << "Thanks for playing! Goodbye!\n";
    return 0;
}
