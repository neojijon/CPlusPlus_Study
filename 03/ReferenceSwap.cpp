#include <iostream>

// 인수를 참조로 선언하였다.
void swapref ( int& a, int& b ){
    int c(a); a = b; b = c;
}

void modify( int p, const int& q, const int& r) {
    p = 27;  // passed by value
    q = 27;  // passed by reference
    r = 27;  // passed by reference
}

int main() {
    int x=10, y=20; 
    swapref(x, y);
    std::cout << "x : " << x << ", y : " << y << std::endl;
    
    int a = 1, b = 1 , c = 1;
    modify(a, b, c); 
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    
    return 0;
}
