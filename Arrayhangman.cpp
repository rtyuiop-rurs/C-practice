#include<iostream>
#include "Random.h"
#include<vector>
#include<string>

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

namespace wordList{
    std::vector<std::string_view> words{"borrow", "carry", "burn", "cassete", "almost", "broccoli", "opinion", "luggage", "distance"};
    std::string_view generateWord(){
        return words[Random::get(0,words.size()-1)];
    }
}

class Sessions{
    private:
    std::string_view m_word{wordList::generateWord()};
    std::vector<bool> m_letterguessed{std::vector<bool>(26)};
    std::size_t toIndex (char c) const {return static_cast<std::size_t>((c % 32) -1);};

    public:
    std::string_view getWord() const {return m_word;};

    bool getLetterguessed(char c) const {return m_letterguessed[toIndex(c)];};
    void setLetterguessed(char c){m_letterguessed[toIndex(c)] = true;};
};

void printDisplay(const Sessions& a){
        std::cout<<"words: "<<"\n";
        for(auto e : a.getWord()){  //only checks true value within a.getWord()
            if(a.getLetterguessed(e))
                std::cout<<e; //prints out only what's true within m_letterguessed && getword(), nothing else!!
            else
                std::cout<<"_";
        }
        std::cout<<"\n";
}

char UserInput(Sessions& let, int& lives){
    while(true){
        bool correct{false};
        std::cout<<"Enter your next letter: ";
        char s{};
        std::cin>>s;
        if(!std::cin){
            std::cin.clear();
            ignoreLine();
            std::cout<<"That wasn't a valid input.  Try again.";
            continue;
        }
        ignoreLine();
        if(s < 'a' || s > 'z'){
            std::cout<<"That wasn't a valid input.  Try again.";
            continue;
        }
        if(let.getLetterguessed(s)){
            std::cout<<"you have guessed the letter: try again";
            continue;
        }
        for(auto e : let.getWord()){
            if(s == e){
                correct = true;
            }
        }
        if(correct){
            std::cout<<"Correct guess!";
        }
        else if(!correct){
            std::cout<<"Incorrect guess!";
            lives--;
        }
        return s;   
    }
}

int main(){
    std::cout<<"Welcome to C++man (a variant of Hangman)\n";
    std::cout<<"To win: guess the word.  To lose: run out of lives.\n";
    Sessions f{};
    int count{6};
    while(true){
        printDisplay(f);
        std::cout<<"lives remaining: "<<count<<"\n";
        char c{UserInput(f,count)};
        f.setLetterguessed(c);
        bool allguessed = true;
        for(auto e : f.getWord()){
            if(!f.getLetterguessed(e)){
                allguessed = false;
                break;
            }
        }
        if(allguessed){
            std::cout<<"You've guessed the word! :"<<f.getWord();
            break;
        }
        if(count < 1){
            std::cout<<"you lost the answer was: "<<f.getWord();
            break;
        }
    }


}
