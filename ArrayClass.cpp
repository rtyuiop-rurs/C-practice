#include<iostream>
#include<array>

class StudentArray{
    std::string m_name{"none"};
    int m_score{0};
    public:
        StudentArray(std::string name = "none", int score = 0)
        : m_name{name}, m_score{score}
        {};

        void setName (std::string name) {m_name = name;};
        void setScore (int score) {m_score = score;};

        friend std::ostream& operator<<(std::ostream& out, const StudentArray& a){
            out<< a.m_name <<" "<< a.m_score <<"\n";
            return out;
        }
};


int main() {
    std::size_t index;
    std::cout << "Enter how many students: ";
    std::cin >> index;
    
    StudentArray* arr = new StudentArray[index];
    std::string* names = new std::string[index];
    int* score = new int[index];
    
    for(std::size_t i = 0; i < index; i++){
        std::cout<<"Enter the names of the students "<<i+1<<": ";
        std::cin>>names[i];
        arr[i].setName(names[i]);
    }
    for(std::size_t i = 0; i < index; i++){
        std::cout<<"Enter the scores of the students "<<i+1<<": ";
        std::cin>>score[i];
        arr[i].setScore(score[i]);
    }
    for(std::size_t i = 0; i < index; i++){
       std::cout<<arr[i]<<"\n";
    }
    delete[] arr;
    delete[] score;
    delete[] names;

    arr = nullptr;
    score = nullptr;
    names = nullptr;
    return 0;
}