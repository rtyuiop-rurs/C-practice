#include <iostream>
#include <string>

int main(){
    std::cout<<"Enter name of person #1: ";
    std::string name1{};
    std::getline(std::cin>>std::ws, name1);
    std::cout<<"Enter the age of the person: ";
    int age1{};
    std::cin>>age1;
    std::cout<<"Enter name of person #2: ";
    std::string name2{};
    std::getline(std::cin>>std::ws, name2);
    std::cout<<"Enter the age of the person: ";
    int age2{};
    std::cin>>age2;

    if(age1 > age2){
        std::cout<<name1<<"( age "<<age1<<" ) "<<"is older than "<<name2<<"( age "<<age2<<" ) ";
    }else{
        std::cout<<name2<<"( age "<<age2<<" ) "<<"is older than "<<name1<<"( age "<<age1<<" ) ";
    }
}   