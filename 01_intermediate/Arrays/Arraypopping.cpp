#include<iostream>
#include<vector>

void printVect(std::vector<int>& num){
    std::cout<<"\tStack: (";
    for(auto elemen : num){
        std::cout<<elemen<<" ";
    }
    std::cout<<")";
    std::cout<<"\n";
}

void pop(std::vector<int>& num){
    num.pop_back();
    std::cout<<"Popped:\n";
}

void push(std::vector<int>& num, int val){
    num.push_back(val);
    std::cout<<"Push "<<val<<"\n";
}

int main(){
    std::vector<int> num;
    int val = 0;
    for(int i = 4; i<=6; i++){
        push(num,i);
    }

    printVect(num);
}