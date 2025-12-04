#include<iostream>
#include<algorithm>
#include<array>


void getArrayinput(std::array <int,5>& arr){
    for(int i = 0; i < 5; i++){
        std::cout<<"Enter the elemen of array "<<i<<" : ";
        std::cin>>arr[i];
    }

    for(auto e : arr){
        std::cout<<e<<" ";
    }
}

void EditArray(std::array <int,5>& arr){
    std::cout<<"Enter a value to search for and replace for: ";
    int search{0};
    int replace{0};
    std::cin>>search>>replace;

    auto found{std::find(arr.begin(),arr.end(),search)};

    if(found == arr.end()){
        std::cout<<"The element " <<search<< "coulnd't be found\n";
    }
    else{
        *found = replace;
    }
    for(int i : arr){
        std::cout<<i<<" ";
    }
}

int getNum(int num, std::array <int,5>& arr ){
    for(int i = 0; i < 5; i++){
        if(num == arr[i]){
            return arr[i];
        }
    }
    return 0;
}

void findCustomNum(int num,std::array <int,5>& arr){
    auto found{std::find(arr.begin(),arr.end(),getNum(num,arr))};
    if(found == arr.end()){
        std::cout<<"No "<<num<< "found\n"; 
    }
    else{
        std::cout<<"Found "<<*found;
    }
}

int main(){
    std::array <int,5> arr{};
    getArrayinput(arr);
    std::cout<<"Do you want to edit the array? : <Y yes || N no || S for search>: ";
    char choice{'/'};
    std::cin>>choice;
    if(choice == 'Y'){
        EditArray(arr);
    }
    else if(choice == 'S'){
        int num{0};
        std::cout<<"Enter the number to search: ";
        std::cin>>num;
        findCustomNum(num,arr);
    }

}