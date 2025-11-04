#include<iostream>

int getSelection(){
    int x{};
    do{
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> x;
    }while(x < 1 || x > 4);
    
    return x;
}

int getResults(int y){
    double result1{};
    double result2{};
    std::cout<<"Enter two numbers for operation: ";
    std::cin>>result1>>result2;

    switch(y){
        case 1:
            return result1 + result2;
            break;
        case 2:
            return result1 - result2;
            break;
        case 3:
            return result1 * result2;
            break;
        case 4:
            return result1 / result2;
            break;
        default:
            std::cout<<"Enter a proper value";
            return 0;
        }
}

int main(){
    int choice{getSelection()};
    int result{getResults(choice)};
    std::cout<<result;

}

