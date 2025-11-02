#include<iostream>

struct Point{
    double x;
    double y;
};

struct Triangle{
    Point* a{};
    Point* b{};
    Point* c{};
};

int main(){
    Point a{2.3,6.1};
    Point b{5.5,7.5};
    Point c{7.5,4.5};
    
    Triangle tri{&a, &b, &c};
    Triangle* ptr{&tri};
    
    std::cout<<ptr->c->y<<"\n";
    std::cout<<ptr->b->y<<"\n";
    