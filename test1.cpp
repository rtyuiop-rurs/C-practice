#include<iostream>
#include<iomanip>

void add(){
    int num_of_scores = 0;
    double pass = 0.0;
    int num_of_pass = 0;
    double fail = 0.0;
    int num_of_fails = 0;
    double score = 0.0;
    double sum = 0.0;
    while(true){
        std::cout<<"enter score <-1 to exit>: ";
        std::cin>>score;
        if(score == -1){
            break;
        }
        if(score != -1 && score < 0){
            continue;
        }
        if(score > 50){
            num_of_pass++;
            pass += score;
        }
        if(score < 50){
            num_of_fails++;
            fail += score;
        }

        num_of_scores++;
        sum += score;
    }
    double average = sum / num_of_scores;
    double average_pass = pass / num_of_pass;
    double average_fail = fail / num_of_fails;
    double pass_percantage = (static_cast<double>(num_of_pass) / num_of_scores) * 100;
    std::cout<<std::fixed<<std::setprecision(1);
    std::cout<<"Point average(all) : "<<average<<"\n";
    if(average_pass > 0){
        std::cout<<"Point average(pass): "<<average_pass<<"\n";
    }
    std::cout<<"Pass percantage: "<<pass_percantage<<"\n";
    if(average_fail > 0){
        std::cout<<"Point average(fail): "<<average_fail<<"\n";
    }
}



int main(){
    add();
}