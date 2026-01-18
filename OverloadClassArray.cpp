#include<iostream>
#include<algorithm>
#include<vector>

struct StudentGrade{
    std::string s_name;
    char s_grade;
};

class GradeMap{
    std::vector<StudentGrade> m_map{};
    public:
        char& operator[](std::string_view name);
};

char& GradeMap:: operator[](std::string_view name){
    auto find = std::find_if(m_map.begin(),m_map.end(),
                    [name](const auto& student){
                        return (student.s_name == name);
                    });
    if(find != m_map.end()){
        return find->s_grade;
    }

    m_map.push_back(StudentGrade{std::string{name}});
    return m_map.back().s_grade;
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