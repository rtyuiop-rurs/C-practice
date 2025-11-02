#include<iostream>

int calculateFactorial(int num) {
    int factorial{1};
    
    if(num < 0){
        std::cout << "Error! Factorial of a negative number doesn't exist.";
        return -1; // Error indicator
    }
    else{
        for(int i{1}; i <= num; i++){
            factorial *= i;
        }
    }
    
    std::cout << factorial; // Moved before return
    return factorial;
}

int main(){
    int result = calculateFactorial(12);
    // Or simply: calculateFactorial(5);
    return 0;
}