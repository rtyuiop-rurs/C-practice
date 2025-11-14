#include<iostream>
#include<vector>
#include<utility>

template <typename T>
std::pair<T,T> minmax(std::vector<T>& arr){
    T min{0};
    T max{0};
    for(std::size_t i = 0; i < arr.size(); i++){
        if(arr[i] < arr[min]){
            min = i;
        }
        if(arr[i] > arr[max]){
            max = i;
        }
    }
    return {max,min};
}

template<typename T>
void printVect(std::vector<T>& arr){
    std::cout<<"With array (";
    for(auto e : arr){
        std::cout<<e<<" ";
    }
    std::cout<<")";
    std::cout<<"\n";
}

template <typename T>
void getInputArr(std::vector<T>& arr){
    while(true){
        std::cout<<"Enter numbers to add (use -1 to stop): ";
        T input;
        std::cin>>input;
        arr.push_back(input);
        if(input == -1){
            arr.pop_back();
            break;
        }
    }
}

 
int main(){
    std::vector<int> v1{};
    getInputArr(v1);
    printVect(v1);
    auto[max,min] = minmax(v1);
    std::cout<<"The min elemen have index: "<<min<<" and value "<<v1[min]<<"\n";
    std::cout<<"The max elemen have index: "<<max<<" and value "<<v1[max]<<"\n";

}