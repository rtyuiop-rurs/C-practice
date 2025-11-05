#include<iostream>

class Fractions{
    int numerator{0};
    int denominator{0};
    public:
        Fractions(int n = 0, int d = 0)
        : numerator{n}
        , denominator{d}
        {

        }

        void getfractions(){
            std::cout << "Enter a value for numerator: ";
            std::cin >> numerator;
            std::cout << "Enter a value for denominator: ";
            std::cin >> denominator;
            std::cout << '\n';
        }

        int getNumerator() const {return numerator;};
        int getDenominator() const {return denominator;};
};

Fractions multiply(Fractions& f1, Fractions& f2){
    return { f1.getNumerator() * f2.getNumerator(), f1.getDenominator() * f2.getDenominator() };
}

void printFractions(Fractions& ff){
    std::cout<<ff.getNumerator()<<" / "<<ff.getDenominator()<<"\n";
}

int main(){
    Fractions f1;
    f1.getfractions();
    printFractions(f1);
    Fractions f2;
    f2.getfractions();
    printFractions(f2);
    Fractions f3{multiply(f1,f2)};
    printFractions(f3);
}