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
    std::cout<<"Popped:";
}

void push(std::vector<int>& num, int val){
    num.push_back(val);
    std::cout<<"Push "<<val;
}

int main(){
    std::vector<int> num;
    push(num, 10);
    printVect(num);
    push(num, 20);
    printVect(num);
    push(num, 30);
    printVect(num);
    push(num, 40);
    printVect(num);
    pop(num);
    printVect(num);
    push(num, 35);
    printVect(num);

}