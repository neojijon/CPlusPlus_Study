#include <iostream>

int main() {
    int a = 1, b = 1, c = 1;
    auto m1 = [a, &b, &c]() mutable {
        a = 3; b = 3; c = 3;
    };
    std::cout << a << ' ' << b << ' ' << c << '\n';
    
    a = 2; b = 2; c = 2;

    auto m2 = [=]() mutable {
        a = 4; b = 4; c = 4;
    };

    m1();
    std::cout << a << ' ' << b << ' ' << c << '\n';

    c = [&i = a, a = a + 5]() -> int {
        i += 2;
        std::cout << "&i = " << i << " a = " << a << std::endl;
        return a + 2;
    }();

    m2();
    std::cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}
