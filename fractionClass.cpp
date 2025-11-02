#include <iostream>

class Fractions{
    int numerator{};
    int denominator{};

    public:
        explicit Fractions(int m_numerator = 0, int m_denominator = 1)
        : numerator{m_numerator}
        , denominator{m_denominator}
        {

        }

        void getFractions(){
            std::cout<<"Enter a value for numerator: ";
            std::cin>>numerator;
            std::cout<<"Enter a value for denominator: ";
            std::cin>>denominator;
        }

        Fractions multiply(const Fractions& f) const {
            return Fractions{numerator * f.numerator, denominator * f.denominator}; 
        }

        void printFractions() const {
            std::cout << numerator << '/' << denominator << '\n';
        }
};



int main(){
    Fractions f1{};
    f1.getFractions();
    Fractions f2{};
    f2.getFractions();
    std::cout<<"Your Fractions are: ";
    f1.multiply(f2).printFractions();
}