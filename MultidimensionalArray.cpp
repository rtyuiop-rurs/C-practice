#include<iostream>
#include<array>

template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T,Col>, Row>;

template <typename T, std::size_t Row, std::size_t Col>
void printArray(const Array2d<T, Row,Col>& arr){
    for(const auto& arow : arr){
        for(const auto& e : arow){
            std::cout<<e<<" ";
        }
        std::cout<<"\n";
    }
}

int main(){
    Array2d<int, 3,4> arr{{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    }};
    
    printArray(arr);
    
    
}