#include<iostream>
#include<vector>


template<typename T>
T findMax(const std::vector<T>& data){
    std::size_t length{data.size()};
    T max{data[0]};
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

template<typename T>
T finMin(const std::vector<T>& data){
    std::size_t lenght{data.size()};
    T min{data[0]};
    if(lenght == 0){
        return T{};
    }

    for(std::size_t index{1}; index < data.size(); index++){
        if(data[index] < min){
            min = data[index];
        }
    }
    return min;
}

int main()
{
    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector data3 {4,5,6,1,2,5,9,4};
    std::cout<<finMin(data3);

    return 0;
}