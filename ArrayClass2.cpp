#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>

class StudentArray{
    std::string m_name{"none"};
    int m_score{0};
    char m_grade{'?'};
    int m_id{0};
    public: 
        StudentArray(std::string name = "none", int score = 0, char grade = 'N', int id = 0)
        : m_name{name}, m_score{score}, m_grade{grade}, m_id{id}
        {};

        void setName(std::string name) {m_name = name;};
        void setScore(int score) {m_score = score;};
        void setGrade(char grade) {m_grade = grade;};
        void setID(int id) {m_id = id;};

        int getScore() const {return m_score;};
        std::string_view getName() const {return m_name;};
        char getGrade() const {return m_grade;};
        int getID() const {return m_id;};

        friend std::ostream& operator<<(std::ostream& out, const StudentArray& a){
            out << a.m_name <<" Score: "<< a.m_score <<" Grade: "<< a.m_grade <<" ID: "<< a.m_id << "\n";
            return out;
        }

        friend std::istream& operator>>(std::istream& in, StudentArray& a){
            in >> a.m_name;
            return in;
        }
};

void addStudent(std::vector<StudentArray>& student){
    std::size_t index{0};
    std::cout<<"Enter the amount of Students: ";
    std::cin>>index;

    for(std::size_t i = 0; i < index; i++){
        std::string name{"none"};
        int score{0};
        char grade{'N'};
        int id{0};

        std::cout<<"Enter the name of student #"<<i+1<<": ";
        std::cin>>name;

        std::cout<<"Enter the score of the student #"<<i+1<<": ";
        std::cin>>score;

        std::cout<<"Enter the Identity number of the student #"<<i+1<<": ";
        std::cin>>id;

        if(score < 40){
            grade = 'F';
        }else if(score > 40 && score < 50){
            grade = 'E';
        }else if(score >= 50 && score < 60){
            grade = 'C';
        }else if(score >= 60 && score < 80 ){
            grade = 'B';
        }
        else{
            grade = 'A';
        }

       student.push_back(StudentArray(name,score,grade,id));
    }
}

void deleteIndex(std::vector<StudentArray>& a){
    std::size_t d_index{0};
    std::cout<<"Enter the index to delete: ";
    std::cin>>d_index;
    if(d_index >= 0 && d_index < a.size()){
        a.erase(a.begin() + d_index);
    }
}

void printStudent(std::vector<StudentArray>& a){
    int i{0};
    for(const auto& m_student : a){
        std::cout<<i<<". "<<m_student;
        i++;   
    }
}

void searchName(std::vector<StudentArray>& a){
    StudentArray b;
    std::string name{"none"};
    std::cout<<"Enter the name of the Student: ";
    std::cin >> name;
    std::size_t foundIndex{444};
    for(std::size_t i = 0; i < a.size(); i++){
        if(a[i].getName() == name){
            foundIndex = i;
            break;
        }
    }

    if(foundIndex != 444){
        std::cout<<a[foundIndex];
    }
    else{
        std::cout<<"Student not found!";
    }
}

void searchID(std::vector<StudentArray>& a){
    StudentArray b;
    int id{0};
    std::cout<<"Enter the id of the student: ";
    std::cin>>id;
    std::size_t foundIndex{444};
    for(std::size_t i = 0; i < a.size(); i++){
        if(a[i].getID() == id){
            foundIndex = i;
            break;
        }
    }
    if(foundIndex!= 444){
        std::cout<<a[foundIndex];
    }
    else{
        std::cout<<"Student not found!";
    }
}

void searchGrade(std::vector<StudentArray>& a){
    std::vector<StudentArray> b;
    char grade{'?'};
    std::cout<<"Enter the grade of the student: ";
    std::cin>>grade;
    for(std::size_t i = 0; i < a.size(); i++){
        if(a[i].getGrade() == grade){
            b.push_back(a[i]);
        }
    }

    if (b.empty()) {
        std::cout << "No students found with grade " << grade << std::endl;
    }
    else{
        for (auto& e : b) {
            std::cout << e << " ";
        }
    }
}



bool compareAscending(StudentArray& a, StudentArray& b){
    return a.getScore() > b.getScore();
}

bool compareDescending(StudentArray& a, StudentArray& b){
    return a.getScore() < b.getScore();
}

using getComparison = std::function<bool(StudentArray&,StudentArray&)>;

getComparison comparison(){
    std::cout<<"Enter what kind of sort <A for ascending and D for Descending>: ";
    char choice_sort{'?'};
    std::cin>>choice_sort;
    switch(choice_sort){
        case 'A' : return &compareAscending;
        case 'D' : return &compareDescending;
        default : return nullptr;
    }
}

void getSearch(std::vector<StudentArray>& a){
    std::cout<<"Enter the parameter for the search <N by name and G my grade and D by ID> : ";
    char choice_search{'?'};
    std::cin>>choice_search;
    switch(choice_search){
        case 'N' : searchName(a);
        break;
        case 'G' : searchGrade(a);
        break;
        case 'D' : searchID(a);
        break;
        default : std::cout<<"Invalid input\n";
    }
}


int main(){
    std::vector<StudentArray> student;
    char choice{'N'};
    char choice_sort{'?'};
    while(true){
        if(student.size() == 0){
            std::cout<<"The system is Empty, Please add students data: ";
            addStudent(student);
        }
        std::cout<<"\n\n";
        std::cout<<"Welcome to Student database system!\n";
        std::cout<<"1. use + to add student details\n";
        std::cout<<"2. use - to delete student details\n";
        std::cout<<"3. use S to search for student details\n";
        std::cout<<"4. use P to list out all the student details\n";
        std::cout<<"5. use C to sort the student details\n";
        std::cout<<"6. use E to quit\n";
        std::cin>>choice;
        std::cout<<"\n\n";
        if(choice == '+'){
            addStudent(student);
        }
        if(choice == '-'){
            deleteIndex(student);
        }
        if(choice == 'S'){
            getSearch(student);
        }
        if(choice == 'P'){
            printStudent(student);
        }
        if(choice == 'C'){
            std::sort(student.begin(),student.end(),comparison());
        }
        if(choice == 'E'){
            std::cout<<"Goodbye!";
            break;
        }
        else{
            std::cout<<"Invalid input!";
        }
    }
}
