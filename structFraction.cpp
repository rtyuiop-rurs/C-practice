#include<iostream>

struct structFraction{
    int numerator{};
    int denominator{};
};

structFraction getFractions(){
    structFraction f1{};
    std::cout<<"Enter a value for the numerator: ";
    std::cin>>f1.numerator;
    std::cout<<"Enter a value for the denominator: ";
    std::cin>>f1.denominator;
    return f1;
}

constexpr structFraction getResultsMultiply( const structFraction& f1, const structFraction& f2){
    return {f1.numerator * f2.numerator, f1.denominator * f2.denominator};
}

void printFractions(const structFraction& f){
    std::cout<<"Your fractions multiplied together: "<<f.numerator<<"/"<<f.denominator;
}

int main(){
    structFraction f1{getFractions()};
    structFraction f2{getFractions()};
    std::cout << "Your fractions multiplied together: ";
    printFractions(getResultsMultiply(f1, f2));
}