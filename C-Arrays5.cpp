#include <array>
#include <iostream>
#include <string_view>

namespace Animal{
    enum animalType{
        chicken,
        dog,
        elephant,
        cat,
        duck,
        snake,
        animalCount,
    };

    struct Data{
        std::string_view name{"none"};
        int legs{0};
        std::string_view sound{"none"};
    };

    using namespace std::string_view_literals;
    constexpr std::array animalEnum{chicken,dog,elephant,cat,duck,snake,};
    static_assert(std::size(animalEnum) == animalCount);
    constexpr std::array animalstring{"chicken"sv,"dog"sv,"elephant"sv,"cat"sv,"duck"sv,"snake"sv};
    static_assert(std::size(animalstring) == animalCount);

    constexpr std::array <Animal::Data, animalCount> AnimalData{{
        {animalstring[0], 2, "cuckoo"sv},
        {"dog"sv, 4, "woof"sv},
        {"elephant"sv, 4, "pawoo"sv},
        {"cat"sv, 4, "meow"sv},
        {"duck"sv, 2, "quack"sv},
        {"snake"sv, 0, "hisss"sv},
    }};

    static_assert(std::size(AnimalData) == animalCount);
};

constexpr Animal::Data returnData(Animal::animalType animal){
    return Animal::AnimalData[animal];
}

std::ostream& operator<<(std::ostream& out, const Animal::Data& data){
    return out << data.name << " has " << data.legs << " legs and says " << data.sound;
}

std::ostream& operator<<(std::ostream& out, Animal::animalType animal){
    return out << returnData(animal);
}

std::istream& operator>> (std::istream& in, Animal::animalType& animal){
    std::string input {};
    std::getline(in >> std::ws, input);

    // Iterate through the list of names to see if we can find a matching name
    for (std::size_t index=0; index < Animal::animalstring.size(); ++index)
    {
        if (input == Animal::animalstring[index])
        {
            // If we found a matching name, we can get the enumerator value based on its index
            animal = static_cast<Animal::animalType>(index);
            return in;
        }
    }

    // We didn't find a match, so input must have been invalid
    // so we will set input stream to fail state
    in.setstate(std::ios_base::failbit);

    // On an extraction failure, operator>> zero-initializes fundamental types
    // Uncomment the following line to make this operator do the same thing
    // color = {};
    return in;
} 

int main(){

    auto animal{Animal::animalCount};
    std::cout<<"Enter a new animal: ";
    std::cin>>animal;
    if(!std::cin)
        std::cout<<"That animal couldn't be found.\n";
    else
        std::cout<<animal<<"\n";
    
    std::cout<<"\n";

    std::cout<<"Here is the data for the rest of the animals: \n";
    for(auto e : Animal::animalEnum){
        int i;
        i++;
        std::cout<<i<<". "<<e<<"\n";
    }
        
}
