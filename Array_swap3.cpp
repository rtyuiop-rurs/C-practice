#include<iostream>
#include<utility>
#include<iterator>
#include<array>


void SelectionsortAsc(int arr[], int arr_size){
    for(int index{0}; index < arr_size; index++){
        int biggest_index{index};
        for(int index2{index+1}; index2 < arr_size -1; index2++){
            if(arr[biggest_index] < arr[index2]){
                biggest_index = index2;
            }
        }
        std::swap(arr[biggest_index],arr[index]);
    }

    for(int i = 0; i < arr_size; i++){
        std::cout<<arr[i];
    }
}

void Bubblesort(int arr[], int arr_size){
    for(int index{0}; index < arr_size - 1; index++){
        for(int index_2{0}; index_2 < arr_size - 1; index_2++){
            if(arr[index_2] < arr[index_2+1]){
                std::swap(arr[index_2],arr[index_2+1]);
            }
        }
    }
    for(int i = 0; i < arr_size; i++){
        std::cout<<arr[i]<<" ";
    }

}

int main(){
    int arr[] {12,45,23,77,88,67,10};
    constexpr static int arr_size{std::size(arr)};

    Bubblesort(arr,arr_size);
}

