#include<array>
#include<iterator>
#include<utility>
#include<iostream>


void bubbleSort(int array [], int array_size){
    for(int index = 0; index < array_size-1; index++){
        int end_of_array {array_size - index};
        bool swap{false};
        for(int current_index{0}; current_index < end_of_array - 1; ++current_index){
            if(array[current_index] > array[current_index+1]){
                std::swap(array[current_index],array[current_index+1]);
                swap = true;
            }
        }

        if(!swap){
            std::cout<<"Early termination at "<<index+1<<"\n";
            break;
        }

    }

    for(int index{0}; index < array_size; index++){
        std::cout<<array[index];
    }
}

void PrintArrayDecrement(int array [4], int array_size){
    for(int index = 0; index < array_size -1; index++){
        int biggest_index{index};
        for(int current_index{index+1}; current_index < array_size; current_index++){
            if(array[current_index] > array[biggest_index]){
                biggest_index = current_index;
            }
        }
        std::swap(array[index],array[biggest_index]);
    }

    for(int index{0}; index < array_size; index++){
        std::cout<<array[index];
    }
    
}

void PrintArrayIncrement(int array [4], int array_size){
    for(int index = 0; index < array_size - 1; index++){
        int smallest_index{index};
        for(int current_index {smallest_index + 1}; current_index < array_size; current_index++){
            if(array[current_index] < array[smallest_index]){
                smallest_index = current_index;
            }
        }

        std::swap(array[index],array[smallest_index]);
    }

    for(int index{0}; index < array_size; index++){
        std::cout<<array[index];
    }
}
int main(){
    int array [] {30, 50, 20, 10, 40};
    int array2[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8};
    constexpr int array_size{static_cast<int>(std::size(array))};
    constexpr int array_size2{static_cast<int>(std::size(array2))};


    PrintArrayDecrement(array,array_size);
    std::cout<<"\n";
    PrintArrayIncrement(array,array_size);
    std::cout<<"\n";
    bubbleSort(array2,array_size2);
}