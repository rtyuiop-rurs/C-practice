#include<array>
#include<iterator>
#include<utility>
#include<iostream>

void SortArray(int arr[], int arr_size, char choice){
    for(int i = 0; i < arr_size - 1; i++){
        int target{i};
        for(int p{i + 1}; p < arr_size; p++){
            if(arr[p] > arr[target] && choice == 'B'){
                target = p;
            }
            if(arr[p] < arr[target] && choice == 'S'){
                target = p;
            }
        }
        std::swap(arr[i],arr[target]);
    }

    for(int index = 0; index < arr_size; index++){
        std::cout<<arr[index];
    }
}

void BubbleSort(int arr[], int arr_size){
    for(int i = 0; i < arr_size - 1; i++){
        bool get{false};
        int end_index{arr_size - i};
        for(int p{0}; p < end_index - 1; p++){
            if(arr[p] > arr[p+1]){
                std::swap(arr[p],arr[p+1]);
                get = true;
            }
        }
        if(!get){
            std::cout<<"Early termination at "<<i+1<<"\n";
            break;
        }
    }
    
    for(int index = 0; index < arr_size; index++){
        std::cout<<arr[index];
    }
}

int main(){
    int arr[] {1,3,5,6,2,8};
    constexpr int arr_size{std::size(arr)};
   
    BubbleSort(arr,arr_size);
}