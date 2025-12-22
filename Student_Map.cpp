#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<string_view>

struct StudentGrade{
    std::string name{"none"};
    char grade{'?'};
};

class GradeMap{
    std::vector<StudentGrade> m_map{};
    public:
    char& operator[] (std::string_view name);
};

char& GradeMap::operator[](std::string_view name){
    auto found = std::find_if(m_map.begin(),m_map.end(),
                    [name](const auto& s){
                            return s.name == name;
                    });

    if(found != m_map.end()){
        return found->grade;
    }

    m_map.push_back(StudentGrade{std::string{name}});
    return m_map.back().grade;
}

int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}