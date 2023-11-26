#include <iostream>
#include <type_traits>
#include <typeinfo>

struct POD {
    int m;
};

class MyClass {
  public:
    MyClass(int i, int j) {
       x = i;
       y = j;
    }
    
  private:
    int x;
    int y;
};

template<typename T>
void check_type(T& t) { 
    if (std::is_fundamental<T>::value) {
        std::cout << t << "는 기본타입이며, ";
        if (std::is_arithmetic<T>::value) {
            if (std::is_integral<T>::value) {
                std::cout << "정수";
            } else if (std::is_floating_point<T>::value) {
                std::cout << "실수";
            }
        }
    }
 
    if (std::is_const<T>::value) {
        std::cout << "이며 const 상수";
    }
    std::cout << "이다." << std::endl;
} 

template<typename T>
void check_class(const char *c, T& t) { 
    std::cout << c;
    if (std::is_class<T>::value) {
         if (std::is_trivial<T>::value) {
             std::cout << "평범한(Trivial Class) ";
         }
         if (std::is_pod<T>::value) {
             std::cout << " POD";
         }
         std::cout << " 클래스";
    } 
    if (std::is_const<T>::value) {
        std::cout << "이며 const 상수";
    }
    std::cout << "이다." << std::endl;
} 

int main() {
    int ct = 100;
    check_type(ct);
    const int cref = ct;
    check_type(cref);
 
    POD pod = {1};
    check_class("pod는 ", pod);
    MyClass mc1(10,20);
    check_class("mc1은 ", mc1);
}   