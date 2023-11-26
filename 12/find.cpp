#include <iostream>
#include <algorithm>
#include <iterator>
#include "Array.hpp"

template<class T>
struct MyComp {
     explicit MyComp(T i) : n(i) { }
     inline bool operator()(const T m) const { return m == n; }
private:
     T n;
};

bool IsOdd (int i) {
  return ((i%2)==1);
}
 
int main(){
    const int n1 = 3;
 
    Array<int> v{0, 1, 2, 3, 4};
    auto result1 = std::find(std::begin(v), std::end(v), n1);
 
    if (result1 != std::end(v)) 
        std::cout << "v 배열은 " << n1 << "을 갖고 있다.\n";
    else 
        std::cout << "v 배열은 " << n1 << "을 갖고 있지 않다.\n";
    
    Array<int>::iterator it = std::find_if(v.begin(), v.end(), IsOdd);
    std::cout << "처음 나오는 홀수는 " << *it << "이다.\n";
    
    MyComp<int> m(4);
    Array<int>::iterator it2 = std::find_if(v.begin(), v.end(), m);
    std::cout << "데이터의 위치는 " << (it2 - v.begin()) << "이다.\n";
}