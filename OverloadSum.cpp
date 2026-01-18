#include<iostream>

class Num{
    int m_x{0};
    int m_y{0};
    public:
        Num(int x = 0, int y = 0)
        : m_x{x}, m_y{y}
        {}

        int getX() const {return m_x;};
        int getY() const {return m_y;};

        void print(){
            std::cout<< m_x << " + " << m_y;
        } 
};

std::ostream& operator<<(std::ostream& out, const Num& m1){
    out << m1.getX() <<" + "<<m1.getY();
    return out;
}

Num& operator+=(const Num& m1, int value){
    m1 = m1.getX() += value;
    
}
