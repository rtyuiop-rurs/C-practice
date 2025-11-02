#include<iostream>
#include<string>
#include<vector>

void passArray(std::vector<char>& hello){
    for(int i=0; i<= 9; i++){
        std::cout<<hello[i];
    }
}

int main(){
    std::vector<char> hello(10);
    std::cout<<"The array have "<<std::size(hello)<<" elements\n";
    for(int i=0; i<= 9; i++){
        std::cout<<"Enter 10 letters: letter"<<i<<": ";
        std::cin>>hello[i];
    }
    passArray(hello);

}