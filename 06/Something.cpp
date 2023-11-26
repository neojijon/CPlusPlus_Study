#include <iostream>

class Something {
private:
    static int s_value; 
    static const int c_value; 
public:
    static int getValue() { return s_value; } 
    static const int getConst() { return c_value; } 
};
 
int Something::s_value = 1; // 정적 변수를 초기화한다.
const int Something::c_value = 10; // 정적 상수를 초기화한다.

int main() {
    std::cout << "Something::getValue() = " << Something::getValue() << std::endl;
    std::cout << "Something::getConst() = " << Something::getConst() << std::endl;
}
