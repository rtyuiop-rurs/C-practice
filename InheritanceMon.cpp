#include<iostream>

class Monster{
    std::string m_name{};
    int m_nol{};
    public:

    Monster(std::string_view name = "none", int nol = 0 )
    : m_name{name}, m_nol{nol}
    {
        std::cout<<"Monster initialized\n";
    }

    const std::string& getName() const {return m_name;};
    int getNOL() const {return m_nol;};
    
};

class Spider : public Monster{
    int m_eyes{};
    int m_fangs{};
    public:

    Spider(int eyes = 0, int fangs = 0, int legs = 0, std::string_view name = "")
    : m_eyes{eyes}, m_fangs{fangs}, Monster{name,legs}
    {
        std::cout<<"Spider initialized\n";
    }

    friend std::ostream& operator<<(std::ostream& out, Spider j1){
        out <<" Name: "
        << j1.getName() <<"\n"<<" Legs: "
        << j1.getNOL() <<"\n"<< " Eyes: "
        << j1.m_eyes <<"\n"<<" Fangs: "
        << j1.m_fangs <<"\n";
        return out;
    }

    int getEyes() const {return m_eyes;};
    int getFangs() const {return m_fangs;}; 
};

class Centipede : public Spider{
    int body_section{};
    public:
    Centipede(std::string_view name = "none", int eyes = 0, int fangs = 0, int legs = 0, int body = 0)
    : Spider{eyes,fangs,legs,name}, body_section{body}
    {
        std::cout<<"Centipede Initialized!\n";
    }

    friend std::ostream& operator<<(std::ostream& out,  Centipede j1){
        out <<" Name: "
        << j1.getName() <<"\n"<<" Legs: "
        << j1.getNOL() <<"\n"<< " Eyes: "
        << j1.getEyes() <<"\n"<<" Fangs: "
        << j1.getFangs() <<"\n"<<" Body Part: "
        << j1.body_section <<"\n";
        return out;
    }
};


int main(){
    Spider joe{8,2,8,"Joe"};
    Centipede Malina{"Malina",2,2,100,50};
    std::cout<<joe;
    std::cout<<Malina;
}