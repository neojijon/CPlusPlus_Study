#include <iostream>

int i = 7; 

int main( int argc, char *argv[] ) {
    int i = 5;
    std::cout << "i 지역 변수의 값은 " << i << "\n";
    std::cout << "i 전역 변수의 값은 " << ::i << "\n";
}
