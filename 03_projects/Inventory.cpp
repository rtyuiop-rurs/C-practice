#include<iostream>

double product(){
    std::cout<<"=== Inventory Management System ==="<<"\n";
    double p1{}, p2{}, p3{};
    int q1{}, q2{}, q3{};

    std::cout<<"Enter quantity for Product 1: ";
    std::cin>>q1;
    std::cout<<"Enter price for Product 1: ";
    std::cin>>p1;
    std::cout<<"Enter quantity for Product 2: ";
    std::cin>>q2;
    std::cout<<"Enter price for Product 2: ";
    std::cin>>p2;
    std::cout<<"Enter quantity for Product 3: ";
    std::cin>>q3;
    std::cout<<"Enter price for Product 3: ";
    std::cin>>p3;

    std::cout<<"=== Receipt ==="<<"\n";
    std::cout<<"product 1: "<<p1*q1<<"\n";
    std::cout<<"product 2: "<<p2*q2<<"\n";
    std::cout<<"product 3: "<<p3*q3<<"\n";

    return p1*q1+p2*q2+p3*q3;
}

void calcDiscount(double total){

    std::cout<<"----------------"<<"\n";
    std::cout<<"Subtotal : "<<total<<"\n";
    double rate = 0.0;
    if(total < 100){
        std::cout<<"Discount : "<<"No discount"<<"\n";
        
    }
    else if(total >= 100 && total <= 500){
        rate = 0.05;
        std::cout<<"Discount : "<<"%"<<rate<<"\n";
    }
    else if(total > 500){
        rate = 0.1;
        std::cout<<"Discount : "<<"%"<<rate<<"\n";
    }

    double discount{total * rate};
    std::cout<<"Final Total: "<<total - discount;

}

int main(){
    double total{product()};
    calcDiscount(total);
}