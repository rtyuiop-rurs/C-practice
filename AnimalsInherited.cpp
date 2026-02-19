#include<iostream>
#include<vector>

class Animal{
    protected:
    int legs{0};
    std::string name{"none"};

    Animal(int leg = 0, std::string_view nname = "none")
    : legs{leg}, name{nname}
    {}

    virtual ~Animal() = default;

    public:
    virtual std::string_view getName() const {return name;};
    virtual std::string_view speak() = 0;
    virtual int getLegs() const {return legs;};
};

class Cat : public Animal{
    public:
    Cat(std::string_view name, int legs = 4)
    : Animal{legs,name}
    {}

    virtual std::string_view speak(){
        return "Meow";
    }

};

class Dog : public Animal{
    public:
    Dog(std::string_view name, int legs = 4)
    : Animal{legs,name}
    {}

    virtual std::string_view speak(){
        return "Woof";
    }
};

int main(){
    Cat c1{"Emil"};
    Dog d1{"John"};
    Dog dd{"Johnny"};
    Cat cc{"Emily"};

    std::vector<Animal*> animal{};

    animal.push_back(&c1);
    animal.push_back(&d1);
    animal.push_back(&cc);
    animal.push_back(&dd);

    for(const auto anml : animal){
        std::cout<<anml->getName()<<" has "<<anml->getLegs()<<" legs and says "<<anml->speak()<<"\n";
    }

}