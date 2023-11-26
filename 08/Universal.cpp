#include <iostream>
#include <type_traits>
#include <utility>
#include <typeinfo>
#include <string>

int i = 0;

template<typename T>
void ParamCheck (T&& s) {
    if (std::is_reference<T&&>::value) {
        if (std::is_lvalue_reference<T&&>::value)
           std::cout << ++i << ". " << s << " 인수는 'T&' 타입이다.\n";
        else 
           std::cout << ++i << ". " << s << " 인수는 'T&&' 타입이다.\n";
    } else std::cout << ++i << ". " << s << " 인수는 'T' 타입이다.\n";
}

int main(int argc, char **argv) {
    ParamCheck("리터럴"); 
    ParamCheck(std::string{"무명변수"}); 

    std::string s3{"일반변수"};
    ParamCheck(s3); 

    const std::string& s4{"const 상수"};
    ParamCheck(s4); 

    std::string ss = std::string("std::move(") + s3 + std::string(")");
    std::string& s5{ss};
    ParamCheck(std::move(s5)); 
   
    std::string&& s6 = std::string("대입연산자와 무명변수"); 
    ParamCheck(s6); 
    std::cout << std::endl;
    return 0;
}
