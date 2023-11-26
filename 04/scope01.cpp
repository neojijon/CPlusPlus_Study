#include <iostream>

int main(){
    int a = 0; 
    ++a;
    { 
        int x = 1;
        x = 42;  
        int a = 0; 
    } 

    { 
        int x = 56;
     }

    std::cout << a << std::endl;
} 

// int b = a; 
