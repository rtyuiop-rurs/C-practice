#include<iostream>

class EmployeePay{
    double m_rh{40};
    double m_ot{24.35};
    double m_bp{18.50};
    double m_th;
    public:

        double getTotalWage(){
            std::cout<<"Enter your total hours worked: ";
            std::cin>>m_th;
            double ot_time;
            if(m_th > 40){
                ot_time = m_th - m_rh;
            }
            else if(ot_time == 0){
                m_rh = m_th;
            }
            
            double reg_wage = m_bp * m_rh;
            double ot_wage  = m_ot * ot_time;
            double t_wage   = reg_wage + ot_wage;

            return t_wage;
        }
    
};

void print(EmployeePay& m){
    double total_wage{m.getTotalWage()};
    std::cout<<"your total wage is: "<<total_wage;
}

int main(){
    EmployeePay m;
    print(m);
}