#include<iostream>
#include<array>

template <typename T, std::size_t N>
void printArray(const std::array<T, N>& arr){
    constexpr std::size_t length{std::size(arr)};
    auto seperator{" "};
    std::cout<<"The array: (";
    for(auto &e : arr){
        std::cout<<seperator<<e;
        seperator = ",";
    }
    std::cout<<") ";
    std::cout<<"has length: "<<length;
}

int main()
{
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);
    std::cout<<"\n";
    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}