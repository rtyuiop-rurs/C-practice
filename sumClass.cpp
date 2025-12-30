#include<iostream>
#include<cstdint>

class Average{
    std::int32_t m_num{0};
    double m_total{0};
    public:
        Average()
        {
        }

        friend std::ostream& operator<<(std::ostream& out, const Average& a){
            if(a.m_num == 0){
                out << 0;
                return out;
            }

            out << static_cast<double>(a.m_total) / a.m_num;
            return out;
        }

        Average& operator+=(std::int32_t num){
            m_total += num;
            ++m_num;
            return *this;
        }
};

int main()
{
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n';

	avg += 8;
	std::cout << avg << '\n';

	avg += 24;
	std::cout << avg << '\n';

	avg += -10;
	std::cout << avg << '\n';

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n';

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}