#include <iostream>

int calcConstant() {
    int foo = 0;
    std::cout << "초기값을 입력하시기 바랍니다.";
    std::cin >> foo;
    return foo;
}

int main(){
    const int x = calcConstant();
    std::cout << x  <<  std::endl;
    return 0;
}
