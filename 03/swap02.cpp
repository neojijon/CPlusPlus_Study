#include <iostream>     // std::cout

void swapref ( int *a, int *b ){
  int c(*a); *a = *b; *b = c;
}

int main () {
    int x=10, y=20; 
    swapref(&x,&y);  // x:20 y:10
    std::cout << "x : " << x << ", y : " << y << std::endl;
    return 0;
}