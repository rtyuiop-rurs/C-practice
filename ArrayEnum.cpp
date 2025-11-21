#include<iostream>
#include<cassert>
#include<array>

namespace Animals{
    enum animals{
        chicken, 
        dog,
        cat,
        elephant,
        duck,
        snake,
        animalcount,
    };

    constexpr std::array<std::string_view,animalcount> animal_strings {
        "chicken","dog","cat","elephant","duck","snake"
    };

    constexpr std::array Legs {2,4,4,4,2,0};

}

void getInput(Animals::animals i){
    std::cout<<"Enter your animal: ";
    std::string input{"???"};
    std::cin>>input;
    std::size_t found_index;
    bool found{false};
    for(std::size_t index = 0; index < Animals::animalcount; index++){
        if(input == Animals::animal_strings[index]){
            found = true;
            found_index = index;
            break;
        }
    }
    if(found){
        std::cout<<"A "<<Animals::animal_strings[found_index]<<" have : "<<Animals::Legs[found_index]<<" legs\n";
    }
    else{
        std::cout<<"That animals can't be found";
    }
}


int main(){
    Animals::animals i;
    getInput(i);
    std::cout<<"\n";
    std::cout<<"Here is the list of all the animals:\n";
    for(std::size_t index = 0; index < Animals::animalcount; index++){
        std::cout<<"A "<<Animals::animal_strings[index]<<" have : "<<Animals::Legs[index]<<" legs\n";
    }
}