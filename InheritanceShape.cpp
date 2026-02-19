#include<iostream>
#include<vector>
#include<algorithm>

class Shape{
    public:
    virtual std::ostream& print(std::ostream& out) const  = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& s1){
        return s1.print(out);
    }

    virtual ~Shape() = default;
};

class Point{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

class Triangle : public Shape{
    Point t1;
    Point t2;
    Point t3;
    public:
    Triangle(const Point& m1, const Point& m2, const Point& m3)
    : t1{m1}, t2{m2}, t3{m3}
    {}

    std::ostream& print(std::ostream& out) const override {
        out <<"Triangle("<< t1 <<" "<< t2 <<" "<< t3<<" )";
        return out;
    }
};

class Circle : public Shape{
    Point c1;
    int radius;
    public:
    Circle(const Point& m1, int rad)
    : c1{m1}, radius{rad}
    {}

    std::ostream& print(std::ostream& out) const override{
        out <<"Circle("<< c1 <<" Radius: "<<radius<<" )";
        return out;
    }

    int getRadius() const {return radius;};
};

std::vector<Circle*> downcastVector(const std::vector<Shape*> Shapevtr){
    std::vector<Circle*> derivedvtr;
    for(Shape* baseptr : Shapevtr){
        Circle* derivedptr = dynamic_cast<Circle*>(baseptr);
        if(derivedptr != nullptr)
            derivedvtr.push_back(derivedptr);
    }

    return derivedvtr;
}

int getLargestRadius(const std::vector<Circle*>& c1){
    if(c1.empty()){
        return 0;
    }

    auto largest = c1[0]->getRadius();

    for(std::size_t i = 0; i < c1.size(); i++){
        if(c1[i]->getRadius() > largest){
            largest = c1[i]->getRadius();
        }
    }

    return static_cast<int>(largest);
}

#include <vector>
#include <iostream>

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3},
      new Circle{Point{3,4}, 10}
	};

	for(const auto* vi : v){
        std::cout<<*vi<<" "<<"\n";
    }

	std::cout << "The largest radius is: " << getLargestRadius(downcastVector(v)) << '\n'; // write this function

	v.clear();

	return 0;
}