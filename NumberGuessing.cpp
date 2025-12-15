#include<iostream>
#include "Random.h"
#include<algorithm>
#include<cmath>
#include<vector>

int getStartPoint(){
    int start_point{0};
    std::cout<<"Start Where?: ";
    std::cin>>start_point;
    return start_point;
}

int getEndPoint(){
    int end_point{0};
    std::cout<<"How many?: ";
    std::cin>>end_point;
    return end_point;
}

int ArrayMult(int start, int end, std::vector <int>& arr_num){
    for(std::size_t i = 0; i < arr_num.size(); i++){
        int current = start + static_cast<int>(i);
        arr_num[i] = current * current;
    }
    int mult{Random::get(2,4)};
    for(std::size_t i = 0; i < arr_num.size(); i++){
        arr_num[i] *= mult;
    }

    return mult;
}

int getClosest(std::vector <int>& arr_num, int answer){
    return *std::min_element(arr_num.begin(),arr_num.end(),
                            [=](int a, int b){
                                return std::abs(a - answer) < std::abs(b - answer);
                            });
}

void game(int mult, std::vector <int>& arr_num){
    int answer{0};
    std::cout<<"I've generated the numbers multiplied by "<<mult<<"\n";
    std::cout<<"Do you know the each number?\n";
    while(!arr_num.empty()){
        std::cout<<">";
        std::cin>>answer;
        auto found{std::find(arr_num.begin(),arr_num.end(),answer)};
        if(found != arr_num.end()){
                std::cout<<"You found the number!\n";
                arr_num.erase(found);
                std::cout<<"number(s) left: "<<arr_num.size()<<"\n";
        }
        else{
            std::cout<<answer<<" is wrong! try "<<getClosest(arr_num,answer)<<" next time\n";
            break;
        }
    }

    if(arr_num.size() < 1){
        std::cout<<"You've found all the numbers!";
    };
}




int main(){
    int start_point{getStartPoint()};
    int end_point{getEndPoint()};
    std::vector <int> arr_num(end_point);
    int mult{ArrayMult(start_point,end_point,arr_num)};
    game(mult,arr_num);
}