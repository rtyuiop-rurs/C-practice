#include<iostream>
#include<vector>
#include<string_view>
void fizzbuzz(int x){
    std::vector<int> div{3,5,7,11,13,17,19};
    std::vector<std::string_view> answer{"fizz","buzz","pop","bang","jazz","pow","boom"};
    for(int i{1}; i<= x; i++){
        bool printed{false};
        if( i % div[0] == 0){
            std::cout<<answer[0];
            printed = true;
        }
        if( i % div[1] == 0){
            std::cout<<answer[1];
            printed = true;
        }
        if( i % div[2] == 0){
            std::cout<<answer[2];
            printed = true;
        }
        if(i % div[3] == 0){
            std::cout<<answer[3];
            printed = true;
        }
        if(i % div[4] == 0){
            std::cout<<answer[4];
            printed = true;
        }
        if(i % div[5] == 0){
            std::cout<<answer[5];
            printed = true;
        }
        if(i % div[6] == 0){
            std::cout<<answer[6];
            printed = true;
        }
        if(!printed){
            std::cout<<i;
        }

        std::cout<<"\n";
    }
}

int main(){
    fizzbuzz(150);
    return 0;
}