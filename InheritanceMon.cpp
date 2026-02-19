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

    virtual const std::string& getName() const {return m_name;};
    virtual int getNOL() const {return m_nol;};
    
    virtual std::ostream& print(std::ostream& out) const {
        out << "Monster ";
        return out;
    }

    friend std::ostream& operator<<(std::ostream& out, const Monster& m1){
        return m1.print(out);
    }
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

    friend std::ostream& operator<<(std::ostream& out, const Spider& s1){
        out << "Spider named: "<< s1.getName() <<" eyes: "<<s1.m_eyes<<" fangs: "<<s1.m_fangs<<" legs: "<<s1.getNOL();
        return out;
    }
};

class Centipede : public Spider{
    int body_section{};
    public:
    Centipede(std::string_view name = "none", int eyes = 0, int fangs = 0, int legs = 0, int body = 0)
    : Spider{eyes,fangs,legs,name}, body_section{body}
    {
        std::cout<<"Centipede Initialized!\n";
    }

    friend std::ostream& operator<<(std::ostream& out, const Centipede& c1){
        out << "Centipede named: "<<c1.getName()<<" legs:  "<<c1.getNOL()<<" body parts: "<<c1.body_section;
        return out;
    }

};

class Print : public Monster{
    Spider s1{};
    Centipede c1{};

    public:

    Print(const Spider& ss1, const Centipede& cc1)
    : s1{ss1}, c1{cc1}
    {}

    std::ostream& print(std::ostream& out) const override{
        out << s1 <<"\n";
        out << c1 <<"\n";
        return out;
    }
};

int main(){
    Monster m{};
    std::cout<<m;

    Print Monsters{Spider{8,2,8,"John"},Centipede{"Jim",2,2,100,50} };
    std::cout<<Monsters<<"\n";

    Monster& ms1{Monsters};
    std::cout<<ms1;
}
