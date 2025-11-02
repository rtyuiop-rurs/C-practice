#include<iostream>
#include<vector>


template<typename T>
T findMax(const std::vector<T>& data){
    T max{data[0]};
    std::size_t length{data.size()};
     if (length == 0){
        return T{};
    }
    for(std::size_t index{1}; index < length; index++){
        if(data[index] > max){
            max = data[index];
        }
    }
    return max;
}

int main()
{
    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3 { };
    std::cout << findMax(data3) << '\n';

    return 0;
}