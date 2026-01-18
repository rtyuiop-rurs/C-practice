#include<iostream>
#include<string>

class myString{
    std::string name{"none"};
    public:
        explicit myString(std::string_view m_name = {})
        : name{m_name}
        {}

        std::string_view operator()(int s1, int s2){
            return std::string_view{name}.substr(
                static_cast<std::string_view::size_type>(s1),
                static_cast<std::string_view::size_type>(s2)
            );
        }

        std::ostream& operator<<(std::ostream& out){
            out << name <<"\n";
            return out;
        }
};

int main()
{
    myString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}