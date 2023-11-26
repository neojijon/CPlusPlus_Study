#include <iostream>   // std::cout
#include <iterator>   // std::move_iterator
#include <vector>     // Array
#include <string>     // std::string
#include <algorithm>  // std::copy
#include "Array.hpp"

int main () {
  Array<std::string> foo (3);
  Array<std::string> bar {"one","two","three"};

  typedef Array<std::string>::iterator Iter;

  std::copy ( std::move_iterator<Iter>(bar.begin()),
              std::move_iterator<Iter>(bar.end()),
              foo.begin() );

  std::cout << "bar :";
  for (std::string& x : bar) std::cout << ' ' << x;
  std::cout << std::endl;
  
  std::cout << "foo :";
  for (std::string& x : foo) std::cout << ' ' << x;
  std::cout << std::endl;
  return 0;
}

