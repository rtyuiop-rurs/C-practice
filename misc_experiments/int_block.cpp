#include<iostream>

int main(){
    std::cout<<"Enter an integer: ";
    int smaller{};
    std::cin>>smaller;
    std::cout<<"Enter a larger integer: ";
    int larger{};
    std::cin>>larger;
    {
        int z{}; //z intialized here
        if(smaller > larger){
            std::cout<<"swapping the values\n";
            z = larger; 
            larger = smaller;
            smaller = z;  //z dies here//
        }
    }

    std::cout<<"The smaller value is: "<<smaller<<"\n";
    std::cout<<"The larger value is: "<<larger;
    return 0;

}