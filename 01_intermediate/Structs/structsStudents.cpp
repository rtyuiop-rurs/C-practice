#include<iostream>

struct Student{
    int id{};
    int age{};
    double marks{};
};

int main(){
    Student s1{};
    Student s2{};
    std::cout<<"Enter id for student 1: "<<"\n";
    std::cin>>s1.id;
    std::cout<<"Enter age for student 1: "<<"\n";
    std::cin>>s1.age;
    std::cout<<"Enter overall marks for student 1: "<<"\n";
    std::cin>>s1.marks;
    std::cout<<"Enter id for student 2: "<<"\n";
    std::cin>>s2.id;
    std::cout<<"Enter age for student 2: "<<"\n";
    std::cin>>s2.age;
    std::cout<<"Enter overall marks for student 2: "<<"\n";
    std::cin>>s2.marks;
    std::cout<<"ID for student 1: "<<s1.id<<"\n";
    std::cout<<"ID for student 2: "<<s2.id<<"\n";
    std::cout<<"Age for student 1: "<<s1.age<<"\n";
    std::cout<<"Age for student 2: "<<s2.age<<"\n";
    std::cout<<"Marks for student 1: "<<s1.marks<<"\n";
    std::cout<<"Marks for student 2: "<<s2.marks<<"\n";
    
}