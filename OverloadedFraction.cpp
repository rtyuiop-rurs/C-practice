#include<iostream>
#include<cstdint>

class FixedPoint2{
    std::int16_t m_num1{0};
    std::int8_t m_num2{0};
    public:
        FixedPoint2(std::int16_t num1, std::int8_t num2)
        : m_num1{num1}, m_num2{num2}
        {
            if(m_num1 < 0 || m_num2 < 0){
                if(m_num1 > 0)
                    m_num1 = -m_num1;
                if(m_num2 > 0)
                    m_num2 = -m_num2;
            }
        }

        explicit operator double() const{
            return m_num1 + static_cast<double>(m_num2) / 100;
        }

        friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& m1){
            out << static_cast<double>(m1);
            return out;
        }
};

#include <cassert>
#include <iostream>

int main()
{
	FixedPoint2 a{ 34, 56 };
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 34.56);

	FixedPoint2 b{ -2, 8 };
	assert(static_cast<double>(b) == -2.08);

	FixedPoint2 c{ 2, -8 };
	assert(static_cast<double>(c) == -2.08);

	FixedPoint2 d{ -2, -8 };
	assert(static_cast<double>(d) == -2.08);

	FixedPoint2 e{ 0, -5 };
	assert(static_cast<double>(e) == -0.05);

	FixedPoint2 f{ 0, 10 };
	assert(static_cast<double>(f) == 0.1);

	return 0;
}