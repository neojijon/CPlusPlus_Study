#include <iostream>

int main() {
    int x = 23 , n = 1 ;
    int y = x << n ;
    std::cout << x << " << " << n << " = " << y << std::endl; 
    
    y = x >> n ;
    std::cout << x << " >> " << n << " = " << y << std::endl; 
    
    x = -105 ;
    y = x << n ;
    std::cout << x << " << " << n << " = " << y << std::endl; 
     
    y = x >> n ;
    std::cout << x << " >> " << n << " = " << y << std::endl;
    return 0;
}
