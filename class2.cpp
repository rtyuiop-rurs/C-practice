#include<iostream>
#include<cmath>

class Point2d{
    double m_x{0.0};
    double m_y{0.0};
    public:
    Point2d(double x = 0.0, double y = 0.0)
    : m_x{x}
    , m_y{y}
    {

    }

    double distanceTo(Point2d& p){
        return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
    }

    void print(){
        std::cout<<"Point2d("<<m_x<<","<<m_y<<")\n";
    }
};

int main(){
    Point2d first{};
    first.print();
    Point2d second{3.0,4.0};
    second.print();

    std::cout<<"Distance between two points: "<<first.distanceTo(second);

}