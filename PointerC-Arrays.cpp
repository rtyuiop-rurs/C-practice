#include<iostream>
#include <cstring>


void printArrayBackwards(char str[255]){
    const char* begin{str};
    const char* end{str + std::strlen(str)};
    for(; end >= begin; end--){
        std::cout<<*end<<" ";
    }
}

void printArray(char str[255]){
    const char* begin{str};
    const char* end{str + std::strlen(str)};
    for(; begin != end; begin++){
        std::cout<<*begin<<" ";
    }
}

int main(){
    char str[] {"Hello World"};
    printArray(str);
    std::cout<<"\n";
    printArrayBackwards(str);
}