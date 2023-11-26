#include <functional>
#include <iostream>

void print(int i) {
    std::cout << i << '\n';
}

int main() {
    int i = 10;
    std::reference_wrapper<int> y(i);
    
    auto f1 = std::bind(print, i);
    auto f2 = std::bind(print, y);
    auto f3 = std::bind(print, std::ref(i));
    i = 20;

    f1();
    f2();
    f3();
}