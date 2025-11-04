#include<iostream>
#include<vector>
#include<string_view>

template <typename T>
bool getList(std::vector<std::string_view>& arr, T data){
    for(std::string_view Name : arr){
        if(data == Name){
            return true;
            break;
        }
    }
    return false;
}
int main(){
    std::vector<std::string_view> monster{"Goblin", "Ogre", "Troll", "Zombie", "Dragon"};
    std::string name{};
    std::cout<<"Enter your monster: ";
    std::cin>>name;
    bool list{getList(monster,name)};

    if(list){
        std::cout<<name<<" monster is on the list!";
    }
    else{
        std::cout<<name<<" is not on the list\n";
        std::cout<<"Monsters on the list: "<<"\n";
        for(std::string_view mon : monster){
            std::cout<<mon<<" ";
        }
        std::cout<<"\n";
    }
}