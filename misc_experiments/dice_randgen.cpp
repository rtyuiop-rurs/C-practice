#include<iostream>
#include<random>

int main(){
    std::random_device rd{};
    std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt{ss};

    std::uniform_int_distribution die10{1,10};

    std::cout<<die10(mt);
    
    return 0;
}