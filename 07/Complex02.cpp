#include <iostream>
#include <cstdio>

struct Complex {
public:    
    explicit Complex(double x) : real(x), imaginary(0) {
      printf( "Complex(double %.2f) 호출\n", x);
    }
    explicit Complex(double x, double y) : real(x), imaginary(y){ 
       printf( "Complex(double %.2f, double %.2f) 호출\n", x, y);
    }

private:
    double real;
    double imaginary;
};

int main(){
//    Complex b1 = 1;   
    Complex b2(2);    
    Complex b3 {4, 5}; 
//  Complex b4 = {4, 5};
    Complex b5 = (Complex)1; 
    Complex *b6 = new Complex( 4, 5);
    delete b6;
}