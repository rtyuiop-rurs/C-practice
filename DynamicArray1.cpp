#include <algorithm> // std::sort
#include <cstddef>
#include <iostream>
#include <string>


std::size_t returnLen(){
  std::cout<<"Enter the amount of names: ";
  std::size_t len{};
  std::cin>>len;
  return len; 
}

void getName(std::string* name, int len){
  for(std::size_t i = 0; i < len; i++){
    std::cout<<"Enter the names #"<<i+1<<" :";
    std:getline(std::cin>>std::ws, name[i]);
  }
}

void printName(std::string* name, int len){
  for(std::size_t i = 0; i < len; i++){
    std::cout<<"Names # "<<i+1<<" "<<name[i]<<"\n";
  }
}


int main(){
  std::size_t len{returnLen()};
  std::string* arr =  new std::string[len];
  getName(arr,len);
  std::sort(arr,arr+len);
  printName(arr,len);
  delete[] arr;
}