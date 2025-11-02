#include<iostream>
#include<string_view>
#include<string>

class Student{
    int s_id{0};
    std::string s_name{"none"};
    int s_password{0};

    void printCreate(){
       std::cout<<"Name: "<<s_name<<" ID: "<<s_id<<" Password: "<<s_password;
    }

    public:
        Student(int id, std::string_view name, int password)
        : s_id{id}
        , s_name{name}
        , s_password{password}
    {
        std::cout<<"Constructor constructed!\n";
        printCreate();
    }

};


int main(){
    Student Jimmy{1221202134, "Jimmy", 140523};
    Student James{1221250525, "James", 150523};
}