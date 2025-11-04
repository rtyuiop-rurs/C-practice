#include<iostream>
#include<string_view>

class Ball{
    std::string m_color{"Black"};
    double m_radius{10};

    public:
        Ball(double radius)
        : Ball{"Black",radius}
        {
        }
        Ball(std::string_view color = "Black", double radius = 10.0)
        : m_color{color}
        , m_radius{radius}
        {
            print();
        }

        
    void print() const
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }

};

int main(){
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}