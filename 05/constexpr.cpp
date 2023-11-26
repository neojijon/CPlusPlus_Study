#include <iostream>

struct complex {   
    constexpr complex(double r, double i) : re(r), im(i) { } 
    constexpr double real() const { return re; }
    constexpr double imag() const { return im; }

private:
    double re;
    double im;
};

constexpr double square(double x) { return x * x; }
 
int main(){
    constexpr complex comp(0.0, 1.0); 
    double x = 1.0;
    complex cx1(x, 10);
    std::cout << "실수 : " << cx1.real() << ", 허수 : " << cx1.imag() << std::endl;
    
    const complex cx2(x, 1);
    constexpr double cr = comp.real();
    constexpr double ci = comp.imag();
    std::cout << "실수 : " << cr << ", 허수 : " << ci << std::endl;
    complex cx3(2, 4.6);    
    
    const int dmv = 17;
    int var = 17;
    constexpr double max1 = 1.4 * square(dmv);
    double max2 = 1.4 * square(var);
    const double max3 = 1.4 * square(var);
    std::cout << "제곱 : " << max3 << std::endl;
}
