#include<iostream>

class Fruit{
    std::string m_name{};
    std::string m_color{};
    public:
    Fruit(const std::string_view name, const std::string_view color)
    : m_name{name},m_color{color}
    {}

    const std::string_view getName() const {return m_name;};
    const std::string_view getColor() const {return m_color;};
};


class Apple : public Fruit{
    double fibre{};
    public:
    Apple(const std::string_view color="red", const std::string_view name="Apple", const double fbr=0.0)
    : Fruit{name,color}, fibre{fbr}
    {}

    double getFBR() const {return fibre;};

    friend std::ostream& operator<<(std::ostream& out, const Apple& p1){
        out <<"Apple("<< p1.getName() <<","<<p1.getColor()<<","<<p1.fibre<<")";
        return out;
    }

};

class Banana : public Fruit{
    public:
    Banana(const std::string_view name = "Banana", const std::string_view color = "Yellow")
    : Fruit{name,color}
    {}

    friend std::ostream& operator<<(std::ostream& out, const Banana& p1){
        out <<"Banana("<< p1.getName() <<","<<p1.getColor()<<")";
        return out;
    }

};

class GrannySmith : public Apple{
    public:
    GrannySmith(const std::string_view name = "green", const std::string_view color = "granny smith apple", const double fbr = 0.0)
    : Apple{name,color,fbr}
    {}
};

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}