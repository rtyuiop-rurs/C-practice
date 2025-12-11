#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>

int getnameAmount(){
    int index{0};
    std::cout<<"Enter the amount of students: ";
    std::cin>>index;
    return index;
}

char getChoice(){
    std::cout<<"Enter if you want to sort the names <a for ascending and d for descending: ";
    char choice{'?'};
    std::cin>>choice;
    return choice;
}

struct Student{
    std::string name{"none"};
    int scorepoints{0};
};


bool compareAscending(const Student& a, const Student& b){
    return a.scorepoints > b.scorepoints;
}

bool compareDescending(const Student& a, const Student& b){
    return a.scorepoints < b.scorepoints;
}

using getComparison = std::function<bool(Student,Student)>;

getComparison comparison(char choice){
    switch(choice){
        case 'a' : return &compareAscending;
        case 'd' : return &compareDescending;
        default : return nullptr;
    }
}

void getNames(int index,char choice){
    std::vector <Student> student(index);
    for(int i = 0; i < index; i++){
        std::cout<<"Enter the names of the student"<<" #"<<i+1<<": ";
        std::cin>>student[i].name;
        std::cout<<"\n";
        std::cout<<"Enter the points that they have: ";
        std::cin>>student[i].scorepoints;
    }
    std::cout<<"\n";
    std::sort(student.begin(),student.end(),comparison(choice));
    std::cout<<"The sorted list of names: \n";
    for(int i = 0; i < index; i++){
        std::cout<<i+1<<"# "<<student[i].name<<" "<<student[i].scorepoints<<"\n";
    }
}


int main(){
    int index{getnameAmount()};
    char choice{getChoice()};
    getNames(index,choice);
}