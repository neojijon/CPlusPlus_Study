#include <iostream>

template<class T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    int tmp01 = 10;
    int tmp02 = 20;
    int *a = &tmp01, *b = &tmp02;
    std::cout << "1. 최소값 : " << min(*a, *b) << std::endl;
    std::cout << "2. 최소값 : " << min<int *>(a, b) << std::endl;
}
