#include <cstring>
#include <iostream>
#include <cstdio>

template <int i> 
class A {
   int array[i];
   const int length = i;
public:
   A() { memset(array, 0, i*sizeof(int)); }
   
   void print() {
        std::cout << "size of " << i << std::endl;
        for (auto l : array) { std::cout << l << " "; }
        std::cout << std::endl;
    }
};

int i = 10;

int main() {
    A<i> a;
}
