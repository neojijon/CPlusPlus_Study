#include <iostream>
#include <cstdio>

void print(int i) {
    std::cout << "int      : " << i << std::endl;
}
      
void print(double  f) {
    std::cout << "float    : " << f << std::endl;
}

void print(const char* c) {
    std::cout << "const char : " << c << std::endl;
}

void print(char* c) {
    std::cout << "char     : " << c << std::endl;
}

int main(){
   print(5);
   print(500.263);
   print("Hello World");
   return 0;
}
