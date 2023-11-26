#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include "Array.hpp"
 
int main() {
    std::string v1[] = {"하늘", "흙", "바람", "불", "안개"};
    Array<std::string> v2 = {"air","water","fire","earth"};
    Array<std::string> meg(9);

    std::sort(begin(v1), end(v1));
    std::sort(v2.begin(), v2.end());
    
    std::merge(begin(v1), end(v1), v2.begin(), v2.end(), meg.begin());
    std::cout << "v1 요소 :";
    for (std::string& x : v1) std::cout << " [" << x << "]";
    std::cout << "\nv2 요소 :";
    for (std::string& x : v2) std::cout << " [" << x << "]";
    std::cout << "\nmeg 요소:";
    for (std::string& x : meg) std::cout << " [" << x << "]";
    std::cout << std::endl;
    
    return 0;
}