#include<iostream>

double getMarks(){
    double a, b, c, d, e;
    std::cout<<"Enter marks for Math: ";
    std::cin>>a;
    std::cout<<"Enter marks for Science: ";
    std::cin>>b;
    std::cout<<"Enter marks for English: ";
    std::cin>>c;
    std::cout<<"Enter marks for History: ";
    std::cin>>d;
    std::cout<<"Enter marks for Art: ";
    std::cin>>e;

    std::cout<<"Total Marks: "<<a+b+c+d+e<<"\n";
    return a+b+c+d+e;
};

double sumPercentage(double x){
    std::cout<<"Percentage Marks : "<<(x/500)*100<<"\n";
    return (x/500)*100;
}

void percentageMark(double x){
    if (x >= 90){
        std::cout<<"Grade A";
    }
    else if(x >= 80){
        std::cout<<"Grade B";
    }
    else if(x >= 70){
        std::cout<<"Grade C";
    }
    else if(x >= 60){
        std::cout<<"Grade D";
    }
    else if(x < 50){
        std::cout<<"Grade F";
    }
}

int main(){
    double x{getMarks()};
    double y{sumPercentage(x)};
    percentageMark(y);
}