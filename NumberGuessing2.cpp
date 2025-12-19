#include<iostream>
#include<algorithm>
#include "Random.h"
#include<cmath>
#include<vector>

int getStart(){
    std::cout<<"Start where? : ";
    int start{0};
    std::cin>>start;
    return start;
}

int getEnd(){
    std::cout<<"How many? :";
    int end{0};
    std::cin>>end;
    return end;
}

int MultArray(std::vector<int>& arr_num, int start, int end){
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

int getClosest(int answer, std::vector<int>& arr_num){
    return *std::min_element(arr_num.begin(),arr_num.end(),
                            [=](int a, int b){
                                return std::abs(a - answer) <  std::abs(b - answer);
                            });
}

void Play(std::vector<int>& arr_num, int start, int end, int mult){
    std::cout<<"I generated "<<end<<" square numbers. Do you know what each number is after multiplying it by "<<mult<<"\n";
    int answer{0};
    while(!arr_num.empty()){
        std::cout<<">";
        std::cin>>answer;
        int closest{getClosest(answer,arr_num)};
        auto found{std::find(arr_num.begin(),arr_num.end(),answer)};
        if(found != arr_num.end()){
            arr_num.erase(found);
            std::cout<<"Nice! "<<arr_num.size()<<" numbers left!\n";
        }
        else{
            std::cout<<answer<<" is wrong! try "<<closest;
            break;
        }
    }
}


int main(){
    int start{getStart()};
    int end{getEnd()};
    std::vector<int> arr_num(end);
    int mult{MultArray(arr_num,start,end)};
    Play(arr_num,start,end,mult);
}
