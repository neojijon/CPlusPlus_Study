#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include "Array.hpp"    // Array

int main () {
    Array<int> myArray;
    for (int i = 0; i < 10; ++i) myArray.push_back(i);

    typedef Array<int>::iterator  iter_type;

    std::reverse_iterator<iter_type> revfrom(myArray.end());
    std::reverse_iterator<iter_type> revuntil(myArray.begin());

    std::cout << "myArray:";
    while (revfrom != revuntil)
        std::cout << ' ' << *revfrom++;
    std::cout << std::endl;
    return 0;
}