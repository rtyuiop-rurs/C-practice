#include<iostream>

double add(){
    int num_of_scores = 0;
    double pass = 0.0;
    int num_of_pass = 0;
    double fail = 0.0;
    int num_of_fails = 0;
    double score = 0.0;
    double sum = 0.0;
    while(true){
        std::cout<<"enter score: ";
        std::cin>>score;
        if(score == -1){
            break;
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
    std::cout<<sum<<"\n"<<num_of_pass<<"\n"<<num_of_fails<<"\n"<<average<<"\n"<<average_pass<<"\n"<<average_fail;
    return sum;
}


int main(){
    add();
}