#include<iostream>
#include <array>

int main(){
    const int arr[] { 9, 8, 7, 6, 5 };
    const int* begin{arr};
    const int* end{arr + std::size(arr)};

    for(;begin != end; begin++){
        std::cout<< *begin <<" ";
    }

    return 0;
}