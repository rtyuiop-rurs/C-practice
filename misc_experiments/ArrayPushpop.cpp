#include<iostream>
#include<vector>

void printStack(const std::vector<int>& arr){
    std::cout<<"\tStack:(";
    if(arr.empty()){
        std::cout<<"Empty";
    }
    for(auto elemen : arr)
        std::cout<<elemen<<"  ";

    std::cout<<")";
    std::cout<<"\n";

}

void pushPrint(std::vector<int>& arr, int val){
    arr.push_back(val);
    std::cout<<"push: "<<val;
}

void popPrint(std::vector<int>& arr){
    arr.pop_back();
    std::cout<<"pop ";

}


int main(){
    std::vector<int> arr{};
    printStack(arr);
    pushPrint(arr, 1);
    printStack(arr);
    pushPrint(arr, 2);
    printStack(arr);
    pushPrint(arr, 3);
    printStack(arr);
    popPrint(arr);
    printStack(arr);
    pushPrint(arr, 4);
    printStack(arr);
    popPrint(arr);
    printStack(arr);
    popPrint(arr);
    printStack(arr);
    popPrint(arr);
    printStack(arr);

}