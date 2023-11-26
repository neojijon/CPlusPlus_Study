#include <vector>
#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
 
int main() {
    std::vector<int> vec{1,2,3,4,5};
    std::set<int> v{-1,-2,-3};
    
//    std::copy(v.begin(), v.end(), std::insert_iterator<std::vector<int>>(vec, vec.end())); 
    std::copy(v.begin(), v.end(), std::inserter(vec, vec.end()));
    for (int n : vec)
        std::cout << n << ' ';
    std::cout << std::endl;
}