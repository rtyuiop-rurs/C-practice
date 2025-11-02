#include<iostream>

void printIceCream(){
    std::cout<<"Welcome to YummyIceCream!\n";
    std::cout<<"****** Ice-cream Flavour: ******\n";
    std::cout<<"[C] chocolate\n";
    std::cout<<"[V] vanilla\n";
    std::cout<<"[S] strawberry\n";
}

void getInput(){
    std::string name;
    char flavour, choice;
    int quantity;
    double price, total_price;
   do{
    printIceCream();
    std::cout<<"Enter order name: ";
    std::cin>>name;
    std::cout<<"Enter flavour: ";
    std::cin>>flavour;
    while(flavour != 'C' && flavour != 'V' && flavour != 'S'){
        std::cout<<"incorrect choice!; reenter choice: ";
        std::cin>>flavour;
    }
    std::cout<<"Enter quantity: ";
    std::cin>>quantity;

    switch(flavour){
        case 'C' : price = 3.50;
        break;
        case 'V' : price = 3.00;
        break;
        case 'S' : price = 2.50;
        break;
        default : price = 0.0;
    }

    std::cout<<"Do you wanna buy more? <Y - yes N - no>";
    std::cin>>choice;

    price = price * quantity;
    total_price += price;

   }while(choice == 'Y' || choice == 'y');

   std::cout<<"***RECEIPT***\n";
   std::cout<<"Order Name: "<<name<<"\n";
   std::cout<<"total price: "<<total_price<<"\n";
    
}

int main(){
    getInput();
}