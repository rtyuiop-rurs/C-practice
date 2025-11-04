#include<iostream>
#include<vector>
#include<cassert>

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
}


std::vector legs{2,4,4,4,2,0};


int main(){
    assert(std::size(legs) == Animals::animalcount);
    std::cout<<legs[Animals::elephant];
    std::cout<<legs[Animals::chicken];
    std::cout<<legs[Animals::animalcount];
}