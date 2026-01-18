#include<iostream>
#include <numeric>

class Fraction{
    int m_nominator{0};
    int m_denominator{1};
    public:
        explicit Fraction(int nominator = 0, int denominator = 1)
        : m_nominator{nominator}, m_denominator{denominator}
        {
          
        };

        explicit operator int() const {
            return static_cast<int>(
                static_cast<double>(m_nominator) / m_denominator
            );
        }
        int getNominator() const {return m_nominator;};
        int getDenominator() const {return m_denominator;};

        void reduce(){
           int gcd{ std::gcd(m_nominator,m_denominator)};
           if(gcd){
            m_nominator /= gcd;
            m_denominator /= gcd;
           }
        }

        friend std::istream& operator>>(std::istream& in, Fraction& m);
        Fraction& operator++();
        Fraction& operator--();
        Fraction operator++(int);
        Fraction operator--(int);
        Fraction operator+=(const Fraction& m1){
            m_nominator += m1.m_nominator;
            m_denominator += m1.m_denominator;
            return *this;
        };
        Fraction operator+=(const int i){
            m_nominator += i;
            m_denominator += i;
            return *this;
        }
        Fraction operator-=(const Fraction& m1){
            m_nominator -= m1.m_nominator;
            m_denominator -= m1.m_denominator;
            return *this;
        }

        void print() const {
            std::cout<<m_nominator<<"/"<<m_denominator<<"\n";
        }

};

class DoubleFraction{
    int d_nominator{0};
    int d_denominator{0};
    public:
        explicit DoubleFraction(int nominator = 0, int denominator = 1)
        : d_nominator{nominator}, d_denominator{denominator}
        {}

        operator Fraction() const {return Fraction{d_nominator * 10, d_denominator * 10};}
};

std::ostream& operator<<(std::ostream& out, const Fraction& m){
    out << m.getNominator() << " / " << m.getDenominator() <<"\n";
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& m){
    int x{};
    int y{};
    in >> x >> y;
    if(y == 0){
        in.setstate(std::ios_base::failbit);
    }

    if(in){
        m = Fraction{x,y};
    }
    
    return in;
}

Fraction operator*(const Fraction& m1, const Fraction& m2){
    return Fraction{m1.getNominator() * m2.getNominator(), m1.getDenominator() * m2.getDenominator()};
}

Fraction operator*(const Fraction& m1, int value){
    return Fraction{m1.getNominator() * value, m1.getDenominator()};
}

Fraction operator*(int value, const Fraction& m1){
    return Fraction{value * m1.getNominator(), m1.getDenominator()};
}

bool operator==(const Fraction& m1, const Fraction& m2){
    return (m1.getNominator() == m2.getNominator() && m1.getDenominator() == m2.getDenominator());
}

bool operator!=(const Fraction& m1, const Fraction& m2){
    return (m1.getNominator() != m2.getNominator() && m1.getDenominator() != m2.getDenominator());
}

bool operator>(const Fraction& m1, const Fraction& m2){
    return ( m1.getNominator() > m2.getNominator() && m1.getDenominator() > m2.getDenominator());
}

bool operator<(const Fraction& m1, const Fraction& m2){
    return ( m1.getNominator() < m2.getNominator() && m1.getDenominator() < m2.getDenominator());
}

bool operator>=(const Fraction& m1, const Fraction& m2){
    return ( m1.getNominator() >= m2.getNominator() && m1.getDenominator() >= m2.getDenominator());
    
}

bool operator<=(const Fraction& m1, const Fraction& m2){
    return ( m1.getNominator() <= m2.getNominator() && m1.getDenominator() <= m2.getDenominator());
}

Fraction& Fraction:: operator++(){
    ++m_nominator;
    ++m_denominator;
    return *this;
}

Fraction& Fraction::operator--(){
    --m_nominator;
    --m_denominator;
    return *this;
}

Fraction Fraction::operator++(int){
    Fraction temp{*this};
    ++(*this);
    return temp;
}

Fraction Fraction::operator--(int){
    Fraction temp{*this};
    --(*this);
    return temp;
}


template <typename T>
const T& max(T& m1, T& m2){
    return (m1 < m2) ? m1 : m2;
}

void PrintFraction(Fraction f){
    std::cout<<f;
}

int main()
{
    Fraction m1{23,34};
    Fraction m2{23,55};
    m1 += m2;
    m1 += m2;
    m1 += 9;
    m1 -= m2;
    std::cout<<m1;   
	return 0;
}