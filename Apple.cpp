#include<iostream>
#include<string_view>

std::string_view getQuantityPhrase(int x){
    if(x < 0)
        return "Negative";
    else if( x == 0)
        return "no";
    else if(x == 1)
        return "a single";
    else if(x == 2)
        return "a couple";
    else if(x == 3)
        return "a few";
    else if(x > 3)
        return "many";
    else
        return "lots of";
}

std::string_view getApplesPluralized(int y){
    if( y == 1){
        return "Apple";
    }
    else{
        return "Apples";
    }
}

int main(){
    constexpr int maryApples { 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}