#include <iostream>
#include <memory>

int main () {
   const volatile int i = 3;
   const_cast<int&>(i) = 4; 
   std::cout << "i = " << i << '\n';

   const volatile int j = 3;
   int* pj = const_cast<int*>(&j); 
   *pj = 8; 
   std::cout << "*pj = " << *pj << ", j = " << j << '\n';
   std::cout << "pj = " << pj << ", &j = " << &j << '\n';

}