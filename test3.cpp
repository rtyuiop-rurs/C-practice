#include<iostream>
#include<memory>
#include<vector>
#include<string>

class person{
    protected:
    std::string m_name;
    int m_id;
    public:
    person(std::string_view name = "none", int id = 000)
    : m_name{name}, m_id{id}
    {}

    virtual ~person() = default;

    std::string_view getName() const {return m_name;};
    int getID() const {return m_id;};

    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, person& p1){
        p1.print(out);
        return out;
    }

};

class Teacher : public person{
    int class_teaching;
    public:
    Teacher(std::string_view name = "none", int id = 00, int class_t = 00)
    : person{name,id}, class_teaching{class_t}
    {}

    int getClass() const {return class_teaching;};

    void setTeacher(){
        std::cout<<"Enter teacher name: ";
        std::cin>>m_name;
        std::cout<<"Enter ID: ";
        std::cin>>m_id;
        std::cout<<"Enter class id: ";
        std::cin>>class_teaching;
    }

    std::ostream& print(std::ostream& out) const override {
        out <<"Name: "<< getName() <<" ID: "<< getID() <<" Class ID: "<<getClass() ;
        return out;
    }
};

class Student : public person{
    int m_class_id;
    std::vector<int> m_score;
    public:
    Student(std::string_view name = "none", int id = 00, int classID = 00, int score = 0)
    : person{name,id}, m_class_id{classID}
    {}
    
    int getClassID() const {return m_class_id;};

    void setStudent(){
        std::cout<<"Enter student name: ";
        std::cin>>m_name;
        std::cout<<"Enter ID: ";
        std::cin>>m_id;
        std::cout<<"Enter class id: ";
        std::cin>>m_class_id;
    }

    void setScore(){
        std::cout<<"Enter amount of subjects: ";
        int index{0};
        std::cin>>index;
        for(int i = 0; i < index; i++){
            std::cout<<"Enter score for subject "<<i+1<<": ";
            int subject;
            std::cin>>subject;
            m_score.push_back(subject);
        }
    }

    int getSumScore() const{
        int sum{0};
        for(auto i : m_score){
            sum += i;
        }

        return sum;
    }

    std::ostream& print(std::ostream& out) const override{
        out <<"Name: "<< getName() <<"\nID: "<< getID() <<"\nClass ID: "<< getClassID();

        out<<"\nScore: ";
        if(!m_score.empty()){
            for(auto i : m_score){
                out<<"["<<i<<"],";
            }

            out<<"\nSum of score: "<<getSumScore()<<"\n";
        }

        return out;
    }
};

int main(){
    std::cout<<"Enter how many person: ";
    int num{0};
    std::cin>>num;
    std::cout<<"Teacher or student: <T teacher, S student> ";
    char choice{'?'};
    std::cin>>choice;
    if(choice == 'T'){
        std::vector<std::unique_ptr<Teacher>> Teachers;
        for(int i = 0; i < num; i++){
            Teachers.emplace_back(std::make_unique<Teacher>());
            Teachers.back()->setTeacher();
        }   

        for(auto &p : Teachers){
            std::cout<<*p<<"\n";
        }
    }
    else if(choice == 'S'){
        std::vector<std::unique_ptr<Student>> Students;
        for(int i = 0; i < num; i++){
            Students.emplace_back(std::make_unique<Student>());
            Students.back()->setStudent();
            Students.back()->setScore();
        }

        for(auto &p : Students){
            std::cout<<*p<<"\n";
        }
    }
    
}