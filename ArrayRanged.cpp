#include<iostream>
#include<vector>
#include<string_view>
#include<string>

template <typename T>
bool isValueinArray(std::vector<T>& arr, T value){
    for(const auto& Name : arr){
        if(Name == value){
            return true;
            break;
        }
    }
    return false;
}

int main(){
    std::vector<std::string_view> names{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::string name{};
    std::cout<<"Enter a name: ";
    std::cin>>name;
    bool found{isValueinArray<std::string_view>(names,name)};

    if(found){
        std::cout<<name<<" is found!";
    }
    else{
        std::cout<<name<<" is not found!";
    }
}