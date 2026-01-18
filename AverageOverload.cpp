#include<iostream>
#include<cstdint>

class Average{
    std::int32_t m_num1{0};
    int m_count{0};
    public:
        Average(std::int32_t num1 = 0, int count = 0)
        : m_num1{num1}, m_count{count}
        {}

        Average& operator+=(int value){
            m_num1 += value;
            m_count++;`e
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& out, const Average& m1){
            out <<static_cast<double>(m1.m_num1) / m1.m_count;
            return out;
        }

        std::int32_t getSUM() const {return m_num1;};
        int getCOUNT() const {return m_count;};
};

int main()
{
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}
