#include<iostream>

int main(){
    int arr[5][5]{
        {12,23,45,12,23},
        {12,23,45,12,23},
        {12,23,45,12,23},
        {12,23,45,12,23},
        {12,23,45,12,23},
    };

    for(std::size_t row{0}; row < std::size(arr); row++){
        for(std::size_t col{0}; col < std::size(arr[0]); ++col){
            std::cout<<arr[row][col]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    for(const auto& arrrow: arr){
        for(const auto&e : arrrow){
            std::cout<<e<<" ";
        }
        std::cout<<"\n";
    }
}
