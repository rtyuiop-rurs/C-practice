#include<iostream>

int main(){
    char n{'a'};
    while(n <= 'z'){
        std::cout<<n<<" ASCII : "<<static_cast<int>(n)<<" "<<"\n";
        n++;
    }
}