#include <iostream>

int main() {
    unsigned char x = 60, y = 11;
    // x = 0011 1100
    // y = 0000 1011
    std::cout << (int) x << " & " << (int) y << " = " << (int)(x & y) << std::endl; 
    std::cout << (int) x << " | " << (int) y << " = " << (int)(x | y) << std::endl; 
    std::cout << (int) x << " ^ " << (int) y << " = " << (int)(x ^ y) << std::endl;

    std::cout << x << " & " << y << " = " << (x & y) << std::endl; 
    
    bool a = true, b = false;
    std::cout << std::boolalpha; 
    std::cout << a << " & " << b << " = " << (bool)(a & b) << std::endl; 
    std::cout << a << " | " << b << " = " << (bool)(a | b) << std::endl; 
    std::cout << a << " ^ " << b << " = " << (bool)(a ^ b) << std::endl;
    
    return 0;
}
