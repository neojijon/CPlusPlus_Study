#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <initializer_list>
#include "Array.hpp"

int main() {
    Array<double> array = { 2.3, 3.2, 4.3 };
    for (Array<double>::iterator i = array.begin(); i != array.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    array.push_back(10.23);
    std::cout << "마지막 위치 : " << array.pop_back() << std::endl;
    std::cout << "배열의 크기 : " << array.size() << std::endl;

    Array<double>::iterator a = array.begin() + 2;
    std::cout << "array.begin() + 2 : " << *a << std::endl;
    size_t l = array.size();
    for (size_t i = 0; i < l; ++i)
        std::cout << array.pop_back() << " ";
  
    std::cout << std::endl;
    return 0;
}