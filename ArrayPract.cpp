#include<iostream>
#include<vector>
#include<iterator>
#include<functional>
#include<algorithm>

std::size_t setSize(){
    std::cout<<"Enter how many: ";
    std::size_t size{0};
    std::cin>>size;
    return size;
}


bool compareAscending(const int& a, const int& b){
    return a < b;
}

bool compareDescending(const int& a, const int& b){
    return a > b;
}

using comparison = std::function<bool(int,int)>;

comparison getComparison(char c){
    switch(c){
        case 'a' : return &compareAscending;
        case 'b' : return &compareDescending;
        default: return nullptr;
    }
}

void setVector(std::vector<int>& arr){
    for(std::size_t i = 0; i < arr.size(); i++){
        std::cout<<"Enter the number for index "<<i+1<<": ";
        std::cin>>arr[i];
    }

    std::cout<<"Enter if you want to sort the array < a for ascending and b for descesnding > : ";
    char choice{'?'};
    std::cin>>choice;

    std::sort(arr.begin(),arr.end(),getComparison(choice));

    for(auto e : arr){
        std::cout<<e<<" ";
    }
}

int binarySearch(const std::vector<int>& array, int target)
{
    int min = 0;
    int max = static_cast<int>(array.size()) - 1;
    int mid{0};
    while(min <= max){
        mid = min + (max - min) / 2;
        if(array[mid] == target){
            return mid;
        }
        else if(target < array[mid]){
            max = mid - 1;
        }
        else if(target > array[mid]){
            min = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    std::size_t size{setSize()};
    std::vector<int> arr(size);
    setVector(arr);
    int target{0};
    std::cout<<"Enter your target to search: ";
    std::cin>>target;
    int found{binarySearch(arr,target)};
    std::cout<<"Number found: "<<arr[found]<<" at index "<<found;
}