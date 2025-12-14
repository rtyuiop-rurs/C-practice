#include<iostream>
#include<algorithm>
#include<array>
#include<functional>

struct Student{
    std::string name{"none"};
    int points{};
};


std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.name;
    return os;
}


template <std::size_t N>
void getBestStudent(const std::array<Student,N>& student){
    auto getMax = std::max_element(student.begin(),student.end(),
                       [](const Student& a, const Student& b){
                        return a.points < b.points;
                       });

    std::cout<<*getMax<<" is the best student ever";

}

int main(){
    std::array<Student, 8> arr{
    { { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 }, // Dan has the most points (8).
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };

    getBestStudent(arr);
}