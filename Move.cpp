#include<iostream>
#include<string>
#include<utility>
#include<vector>

int main(){
    int lenght{};
    std::cout<<"Enter the lenght: ";
    std::cin>>lenght;
    std::vector<std::string> Names{};

    for(int i = 0; i < lenght; i++){
        std::string names{};
        std::cin>>names;
        Names.push_back(names);
    }
}