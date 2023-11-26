#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <algorithm>    // std::sort
#include <tuple>        // std::tuple 
#include <iostream>     // std::cout
#include <complex>
#include "Array.hpp"    // Array

typedef  std::pair <std::string,double> myPair;
bool Compare(const myPair& i, const myPair& j){
    return i.second < j.second;
}

int main () {
    myPair product1;
    myPair product2 ("tomatoes",2.30);
    myPair product3 (product2); 
    myPair product4;
  
    product1 = std::make_pair(std::string("lightbulbs"),5.99);

    product4.first = "shoes"; 
    product4.second = 39.90;  

    Array<myPair> product(5);
    product[0] = product1;
    product[1] = product2;
    product[2] = product3;
    product[3] = product4;
    product[4] = std::make_pair<std::string,double> ("apple",3.10);
    std::sort(product.begin(), product.end(), Compare);

    for (int i = 0; i < 5; ++i) { 
        std::cout << i << ". " 
                  << product[i].first << "의 가격은 $ " 
                  << product[i].second << "이다." << std::endl;
    } 
    return 0;
}