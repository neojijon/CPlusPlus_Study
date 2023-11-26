#include <iostream>

int main() {
    int x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // x 배열에 대해 범위 기반 for 문을 적용한다.
    for( int y : x ) { 
        std::cout << y << " ";
    }
    std::cout << std::endl;

    for(int n: { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 })
        std::cout << n << ' ';
    std::cout << std::endl;
} 
