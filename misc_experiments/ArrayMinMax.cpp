#include<iostream>
#include<vector>

template <typename T>
std::pair<std::size_t,std::size_t> minMax(const std::vector<T>& arr){
    std::size_t min{0};
    std::size_t max{0};
    for(std::size_t i = 1; i < arr.size(); i++){
        if(arr[i] < arr[min])
            min = i;
        if(arr[i] > arr[max])
            max = i;
    }
    return {min, max};
}

template <typename T>
void printArr(const std::vector<T>& arr){
    std::cout<<"Array: ";
    for(auto& e : arr){
        std::cout<<e<<" ";
    }
    std::cout<<"\n";
}

int main(){
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

    std::vector<int> push{};
    int data{0};
    while(true){
        std::cout<<"Enter numbers to add (use -1 to stop): ";
        std::cin>>data;
        if(data == -1){
            break;
        }
        push.push_back(data);
    }
    printArr(push);

    auto[min,max] = minMax(push);
    std::cout<<"The min elemen has index: "<<min<<" and value "<<push[min]<<"\n";
    std::cout<<"The max elemen has index: "<<max<<" and value "<<push[max]<<"\n";
}