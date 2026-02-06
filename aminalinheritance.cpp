#include <iostream>
#include <string_view>
#include <string>
#include <array>

class Animal
{
protected:
    std::string m_name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name)
        : m_name{ name }    
    {}

public:
    std::string_view getName() const { return m_name; }
    virtual std::string_view speak() const { return "???";};
    virtual Animal* legs() const {std::cout<<"Animal has legs"; return nullptr;};
};

class Cat: public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name}
    {
    }

    std::string_view speak()  { return "Meow"; }
    Cat* legs() const  override  {std::cout<<"Cat has 4 legs"; return nullptr;};
};

class Dog: public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const { return "Woof"; };
    Dog* legs() const override {std::cout<<"Dog has 4 legs"; return nullptr;};
};

class Bird : public Animal{
    public:
    Bird(std::string_view name)
    : Animal{name}
    {}

    std::string_view speak() const {return "Chirp";};
    Bird* legs() const  override {std::cout<<"Bird has 2 legs"; return nullptr;};
};


int main(){
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };
    
    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    const Bird millie {"Millie"};
    const Bird justin {"Justin"};

    // Before C++20, with the array size being explicitly specified
    const std::array<const Animal*, 8> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke, &millie, &justin };

    for (const auto animal : animals)
    {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
        std::cout<< animal->getName() << "has "    << animal->legs()  << "\n";
    }

    return 0;
}