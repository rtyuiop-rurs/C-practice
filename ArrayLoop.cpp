#include <iostream>
#include <vector>
#include<limits>

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getInput(){
    int choice {};
    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> choice;
        if (!std::cin)
            std::cin.clear(); 

        ignoreLine(); 

    } while (choice < 1 || choice > 9);

    return choice;
}


template <typename T>
void searchArray(const std::vector<T>& arr, T choice){
    std::size_t length{arr.size()};
    bool found;
    std::size_t foundIndex{};
    for(std::size_t index{0}; index < length; index++){
        if(arr[index] == choice){
            found = true;
            foundIndex = index;
            break;
        }
    }

    if(found){
        std::cout<<"The number "<<choice<<" has index "<<foundIndex<<"\n";
    }
    else{
        std::cout<<"Number was not found";
    }
}

template <typename T>
void printArray(const std::vector<T>& arr){
    for(int index : arr)
        std::cout<<index<<" ";
    std::cout<<" ";

}


int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    int choice{getInput()};
    searchArray(arr, choice);
    printArray(arr);
    return 0;
}