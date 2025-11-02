#include<vector>
#include<iostream>

int main(){
    std::vector<int> integral(3);
    std::cout<<"Enter 3 integers: ";
    for(int i=0; i <= 2; i++){
        std::cin>>integral[i];
    }
    std::cout<<"the sum is: "<<integral[0] + integral [1] + integral [2]<<"\n";
    std::cout<<"the product is: "<<integral[0] * integral [1] * integral [2]<<"\n";
}