#include<iostream>
class Student{
    public:
        enum Grade{
            A,
            B,
            C,
            None,
        };

    private:
        std::string m_name;
        double m_marks;
        int m_id;
        Grade m_grade;
    
    public:
        Student(Grade grade = None, std::string_view name = "None", double marks = 0.0, int id = 000)
        : m_grade{grade}
        , m_name{name}
        , m_marks{marks}
        , m_id{id}
        {
        }

        Grade getGrade() const {return m_grade;};
        std::string_view getname() const {return m_name;};
        double getMarks() const {return m_marks;};
        int getID() const {return m_id;};

        void setValues(){
            std::cout<<"Enter your Name: \n";
            std::cin>>m_name;
            std::cout<<"Enter your ID: \n";
            std::cin>>m_id;
        }

        Grade calcGrade(Student& s){
            std::cout<<"Enter your total marks: ";
            std::cin>>s.m_marks;
            if(s.m_marks >= 50.0 && s.m_marks < 70.0){
                std::cout<<"Grade: C\n";
                return Grade::C;
                
            }
            if(s.m_marks >= 70.0 && s.m_marks < 90.0){
                std::cout<<"Grade: B\n";
                return Grade::B;
            }
            if(s.m_marks >= 90.0){
                std::cout<<"Grade: A\n";
                return Grade::A;
            }
            return Grade::None;
        }
};

void print(Student& s){
    std::cout<<"Name: "<<s.getname()<<" "<<"ID: "<<s.getID()<<" "<<"\n";
    s.calcGrade(s);
}

int main(){
    Student s{};
    s.setValues();
    print(s);
}
