#include<iostream>
#include<string>
#include<cassert>

class MyString{
    std::string m_name{"none"};
    public:
    MyString(std::string name)
     : m_name{name}
    {}

    friend std::ostream& operator<<(std::ostream& out, const MyString& a);
    std::string_view operator() (int start, int end){
        assert(start >= 0);
        std::string_view sub = m_name.substr(static_cast<std::string_view::size_type>(start),static_cast<std::string_view::size_type>(end));
        return sub;
    }

};

std::ostream& operator<<(std::ostream& out, const MyString& a){
    out<<a.m_name;
    return out;
}


int main(){
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    MyString f{"Goodbye World"};
    std::cout<< f(0,7) <<"\n";

    return 0;
}