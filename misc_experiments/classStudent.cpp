#include<iostream>
#include<string_view>

class Student{
    int m_id{};
    std::string m_name{};
    double m_TotalMarks{};

    public:
        Student(int id = 0, std::string_view name = "empty", double TotalMarks = 0.0)
        : m_id{id}
        , m_name{name}
        , m_TotalMarks{TotalMarks}
        {
            std::cout<<"Contructor contructed!";
        }

        void setValues(){
            std::cout<<"Enter your Name: \n";
            std::cin>>m_name;
            std::cout<<"Enter your ID: \n";
            std::cin>>m_id;
            std::cout<<"Enter your total marks: \n";
            std::cin>>m_TotalMarks;
        }

        std::string_view getName() const {return m_name;};
        int getID() const {return m_id;};
        double getmarks() const {return m_TotalMarks;};

};


double getExtraMarks(Student& f){
    double totalMarks{f.getmarks()};
    double extraMarks{};
    std::cout<<"Enter your extra marks: \n";
    std::cin>>extraMarks;
    return totalMarks * extraMarks/100;
}

void printALL(Student& f){
    double ExtraMarks{getExtraMarks(f)};
    std::cout<<"Name: "<<f.getName()<<" "<<"ID: "<<f.getID()<<" "<<"Marks: "<<f.getmarks()<<" "<<"Extra Marks: "<<ExtraMarks;
}

int main(){
    Student f{};
    f.setValues();
    printALL(f);
}