#include<iostream>
#include<vector>
#include "Random.h"

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

namespace wordList{
    std::vector<std::string_view> word{"mystery","broccoli","account","almost",
        "spaghetti","opinion","beutiful","distance","luggage","skibidi"};
    
    std::string_view Word(){
        return word[Random::get(0,word.size()-1)];
    }
}

class Session{
    private:
        std::string_view m_words{wordList::Word()};
        std::size_t getIndex(char c) const  {return static_cast<std::size_t>((c % 32)-1);};
        std::vector<bool> m_indexValue{std::vector<bool>(26)};
    public:
        std::string_view getWords() const {return m_words;};

        bool getIndexValue(char c) const {return m_indexValue[getIndex(c)];};
        void setIndexValue(char c) {m_indexValue[getIndex(c)] = true;};
};

void printUI(Session& a){
        std::cout<<"words: ";
        for(auto& e : a.getWords()){
            if(a.getIndexValue(e)){
                std::cout<<e;
            }
            else{
                std::cout<<"_";
            }
        }
        std::cout<<"\n";
}

char getInput(Session& a, int& lives){
    while(true){
        bool correct{false};
        std::cout<<"Enter your letter: ";
        char c{};
        std::cin>>c;
        if(!std::cin){
            std::cin.clear();
            ignoreLine();
            std::cout<<"You entered invalid input! try again: ";
            continue;
        }
        ignoreLine();
        if(c < 'a' || c > 'z'){
            std::cout<<"You entered invalid input! try again: ";
            continue;
        }
        if(a.getIndexValue(c)){
            std::cout<<"You've entered that before\n";
            continue;
        }
        for( auto s : a.getWords()){
            if(c == s){
                correct = true;
            }
        }
        if(correct){
            std::cout<<"You've guessed right!\n";
        }
        else if(!correct){
            std::cout<<"you guessed wrong;\n";
            lives--;
        }
        return c;
    }
}

int main(){
    Session f;
    std::cout<<"Welcome to C++man (a variant of Hangman)"<<"\n";
    std::cout<<"To win: guess the word.  To lose: run out of pluses."<<"\n";
    int lives{6};
    while(true){
        bool allcorrect{true};
        char c{getInput(f,lives)};
        f.setIndexValue(c);
        printUI(f);
        std::cout<<"You've entered: "<<c<<"\n";
        for(auto e : f.getWords()){
            if(!f.getIndexValue(e)){
                allcorrect = false;
            }
            else{
                allcorrect = true;
            }
        }
        std::cout<<"your lives: "<<lives<<"\n";
        if(lives < 1){
            std::cout<<"Sorry you're out of lives!"<<"The word was: "<<f.getWords();
            break;
        }
        else if(allcorrect){
            std::cout<<"Congrats you've gotten the word: "<<f.getWords();
            break;
        }
    }
}