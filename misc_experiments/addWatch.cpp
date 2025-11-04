#include<iostream>

struct Revenue{
    double adWatched{};
    double userClicks{};
    double earnings{};
};

void printRevenue(const Revenue& rev){
    std::cout<<"Ads watched: "<<rev.adWatched<<"\n";
    std::cout<<"User clicked: "<<rev.userClicks<<"\n";
    std::cout<<"Earnings: "<<rev.earnings<<"\n";
    std::cout<<"Overall earnings: "<<(rev.adWatched* rev.earnings * rev.userClicks/100)<<"\n";
}

Revenue getProfits(){
    Revenue f1{};
    std::cout<<"Enter the amounts of Ads watched (percentage): ";
    std::cin>>f1.adWatched;
    std::cout<<"Enter the amounts of User clicked: ";
    std::cin>>f1.userClicks;
    std::cout<<"Enter the amounts of Earnings: ";
    std::cin>>f1.earnings;
    return f1;
}


int main(){
    Revenue f1{getProfits()};
    printRevenue(f1);
}