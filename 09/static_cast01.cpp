#include <iostream>
#include <vector>
                   
int main () {
   int n = 100;
   void* nv = &n;
   long* n01 = static_cast<long *>(nv);
   int* n02 = static_cast<int*>(&n);
   long* n03 = static_cast<long *>(&n);

   // 간접 참조를 사용하여 데이터를 출력시킨다.
   std::cout << "n = "    << n
             << ", *n01 = " << *n01
             << ", *n02 = " << *n02 << '\n';

   std::vector<long> e = { 1, 23, 10};
   void* voidp = &e;
   std::vector<int> *vec = static_cast<std::vector<int>*>(voidp);
   std::vector<int> vr = *vec; 
   for ( int a : vr)
       std::cout << a << ' '; 
   std::cout << std::endl;
}