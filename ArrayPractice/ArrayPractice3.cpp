#include<iostream>
#include<vector>
#include "Random.h"
#include<string>
#include<limits>

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

namespace wordList{
    std::vector<std::string_view> words{"apple","banana","sanwich","guns","toilet","poop","cup","economy",
        "responsibility"};
    
    std::string_view generateWord(){
        return words[Random::get(0,words.size()-1)];
    }
}

class Gamedata{
    private:
    std::string_view word{wordList::generateWord()};
    std::vector<char> letters{std::vector<char>(26)};    
    std::size_t getIndex (char c) { return static_cast<std::size_t>((c % 32) - 1);};
    public:
    std::string_view getWord() const {return word;};

    void setGuessed (char c) {letters[getIndex(c)] = true;};
    bool getGuessed (char c) {return letters[getIndex(c)];};
};

char getInput(Gamedata& f, int& lives){
    bool correct{false};
    while(true){
        std::cout<<"Enter a letter: ";
        char s;
        std::cin>>s;
        if(!std::cin){
            std::cin.clear();
            ignoreLine();
            std::cout<<"Invalid input! Try again!";
            continue;
        }
        ignoreLine();
        if( s < 'a' || s > 'z'){
            std::cout<<"Invalid input! Try again!";
            continue;
        }
        if(f.getGuessed(s)){
            std::cout<<"You have entered that before! try again!";
            continue;
        }
        for(auto e : f.getWord()){
            if(s == e){
                correct = true;
            }
        }
        if(correct){
            std::cout<<"You've guessed right!";
        }
        else{
            lives--;
            std::cout<<"You've guessed wrong!";
        }

        return s;
    }
}

void printstate(Gamedata& f, char c){
    std::cout<<"words: ";
    for(auto e : f.getWord()){
        if(f.getGuessed(e)){
            std::cout<<e;
        }
        else{
            std::cout<<"_";
        }
    }
    std::cout<<"\n";
}


int main(){
    std::cout<<"Welcome to C++man (a variant of Hangman)"<<"\n";
    std::cout<<"To win: guess the word.  To lose: run out of pluses."<<"\n";
    Gamedata f;
    int plus{6};
    while(true){
        char c{getInput(f,plus)};
        std::cout<<"lives remaining: "<<plus<<"\n";
        f.setGuessed(c);
        printstate(f,c);
        bool allguessed{true};
        for(auto e : f.getWord()){
            if(!f.getGuessed(e)){
                allguessed = false;
                break;
            }
        }
        if(allguessed){
            std::cout<<"Congrats you win!";
            break;
        }
        if(plus < 1){
            std::cout<<"You lose! the word was: "<<f.getWord();
            break;
        }
    }
}