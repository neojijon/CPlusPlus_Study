#include <iostream>     // std::cout
#include <algorithm>    // std::generate
#include "Array.hpp"

int init() { return 1; }

struct c_unique {
  int current;
  c_unique() {current=0;}
  int operator()() {return ++current;}
} UniqueNumber;

int main () {
  Array<int> myArray(8);
  std::fill (myArray.begin(),myArray.begin()+4,5);
//  std::generate (myArray.begin()+4, myArray.end(), init);

  std::cout << "myArray의 값은 ";
  for (auto& it : myArray) std::cout << it << ' ';
  std::cout << std::endl;

  std::generate (myArray.begin(), myArray.end(), UniqueNumber);

  std::cout << "myArray의 값은 ";
  for (auto& it : myArray) std::cout << it << ' ';
  std::cout << std::endl;
  return 0;
}