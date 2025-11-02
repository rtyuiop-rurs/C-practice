#include<iostream>
#include<cmath>

class Point2d{
    double m_x{0.0};
    double m_y{0.0};
    public:
        Point2d() = default;
        Point2d(double m, double y)
        :m_x{m}
        ,m_y{y}
        {
        }

        void print(){
            std::cout<<"Point2d("<<m_x<<","<<m_y<<")\n";
        }

        double distanceTo(Point2d& y){
            return std::sqrt((m_x - y.m_y) * (m_x - y.m_y) + (m_y - y.m_x) * (m_y - y.m_x));
        }
};

int main(){
    
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}