#include <cstddef>
#include <iostream>
 
void f(int* pi) {
   std::cout << "정수를 가리킨다.\n";
}
void f(double* pd){
   std::cout << "실수를 가리킨다.\n";
}
void f(std::nullptr_t nullp){
   std::cout << "null 포인트이다.\n";
}
 
int main() {
    int* pi; double* pd;
 
    f(pi);
    f(pd);
    f(nullptr); 
  // f(NULL);  

    delete pi; 
    delete pd;
}
