#include<iostream>

class Engine{
    std::string Engine_type{};
    public:
        Engine() = default;
        void setEngine(char ch){
            if(ch == 'G'){
                Engine_type = "Gasoline or petrol";
            }
            if(ch == 'E'){
                Engine_type = "Electric";
            }
        };
        std::string_view getEngine() const {return Engine_type;};
};

class car{
    std::string m_model;
    int m_year;
    Engine m_engine;
    public:
        car() = default;

        void setCar(){
            std::string model{};
            int year{};
            char engine{};

            std::cout<<"Enter the car model: ";
            std::cin>>model;
            m_model = model;

            std::cout<<"Enter the car year: ";
            std::cin>>year;
            m_year = year;

            std::cout<<"Enter the car engine: ";
            std::cin>>engine;
            m_engine.setEngine(engine);
        }

        friend std::ostream& operator<<(std::ostream& out, const car& c1){
            out << c1.m_model <<" "<<c1.m_year<<" "<<c1.m_engine.getEngine();
            return out;
        }
};

int main(){
    car c1{};
    c1.setCar();
    std::cout<<c1;
}