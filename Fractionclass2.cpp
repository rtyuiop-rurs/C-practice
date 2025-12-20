#include<iostream>
#include <numeric>

class Fraction{
    int m_nominator{0};
    int m_denominator{0};
    public:
        Fraction(int nominator=0, int denominator=1)
                : m_nominator{nominator}, m_denominator{denominator}
        { }

        void print() const{
            std::cout<<m_nominator<<'/'<<m_denominator;
            std::cout<<"\n";
        }

        friend Fraction operator*(const Fraction& a, int value);
        friend Fraction operator*(const Fraction& a, const Fraction& b);
        friend Fraction operator*(int value, Fraction& a);
        friend std::ostream& operator<<(std::ostream& out, const Fraction& a);
        friend std::istream& operator>>(std::istream& in, Fraction& a);
        
        friend bool operator== (const Fraction& c1, const Fraction& c2);
        friend bool operator!= (const Fraction& c1, const Fraction& c2);
        friend bool operator< (const Fraction& c1, const Fraction& c2); 
        friend bool operator> (const Fraction& c1, const Fraction& c2);
        friend bool operator<= (const Fraction& c1, const Fraction& c2);        
        friend bool operator>= (const Fraction& c1, const Fraction& c2);


        void reduce(){
            int gcd{std::gcd(m_nominator,m_denominator)};
            if(gcd){
                m_nominator /= gcd;
                m_denominator /= gcd;
            }
        }
};


Fraction operator*(const Fraction& a, int value){
    return Fraction(
        a.m_nominator * value,
        a.m_denominator * value
    );
}

Fraction operator*(const Fraction& a, const Fraction& b){
    return Fraction(
        a.m_nominator * b.m_nominator,
        a.m_denominator * b.m_denominator
    );
}

Fraction operator*(int value, Fraction& a){
    return Fraction(
        a.m_nominator * value,
        a.m_denominator * value
    );
};

std::ostream& operator<<(std::ostream& out, const Fraction& a){
    out<<a.m_nominator<<" / "<<a.m_denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& a){
    in >> a.m_nominator >> a.m_denominator;
    if(a.m_denominator < 1){
        in.setstate(std::ios_base::failbit);
    }
    if(in){
        a = Fraction{a.m_nominator,a.m_denominator};
    }
    return in;
}

bool operator== (const Fraction& c1, const Fraction& c2){
    return(
        c1.m_nominator == c2.m_nominator &&
        c1.m_denominator == c2.m_denominator
    );
};

bool operator!= (const Fraction& c1, const Fraction& c2){
    return !operator==(c1,c2);
};

bool operator< (const Fraction& c1, const Fraction& c2){
    return(
        c1.m_nominator * c2.m_nominator <
        c1.m_denominator * c2.m_denominator
    );
};

bool operator> (const Fraction& c1, const Fraction& c2){
    return operator<(c1,c2);
};

bool operator<= (const Fraction& c1, const Fraction& c2){
    return !(operator>(c1,c2));
};        

bool operator>= (const Fraction& c1, const Fraction& c2){
    return !(operator<(c1,c2));
};

int main()
{
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
	return 0;
}