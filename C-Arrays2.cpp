#include<iostream>
#include<array>

int main(){
    constexpr std::array hello{"h","e","l","l","o"};
    constexpr int lenght{std::size(hello)};
    std::cout<<"The lenght is : "<<lenght<<"\n";
    std::cout<<hello[1];
    std::cout<<std::get<1>(hello);
    std::cout<<hello.at(1);


}