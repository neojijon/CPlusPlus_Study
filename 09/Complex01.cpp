#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include <cmath>
#include <iomanip>

struct Complex {
public:
    constexpr Complex( double real );
    constexpr Complex( double real, double imaginary);
    
    Complex& operator +();
    Complex  operator -();

    Complex& operator ++();
    Complex  operator ++( int );
    Complex& operator --();
    Complex  operator --( int );
    
inline Complex  operator +( const Complex& c ) const;
    // Complex  operator +( const Complex& c ) const;
    Complex  operator -( const Complex& c ) const;
    Complex  operator *( const Complex& c ) const;
    Complex  operator /( const Complex& c ) const;

    Complex& operator =( const Complex& c );
    Complex& operator +=( const Complex& c );
    Complex& operator -=( const Complex& c );

    bool operator ==( const Complex& c );
    bool operator !=( const Complex& c );

    operator char *() const;
//    friend std::ostream& operator<<( std::ostream& os, const Complex& c );
    
    double Real() const {
        return real;
    }
    double Imaginary() const {
        return imaginary;
    }

private:
    double real;
    double imaginary;
};

inline Complex operator+( const Complex &c, const double d ) {
    Complex complex( c.Real() + d, c.Imaginary() );
    return complex;
}

inline Complex operator+( const double d, const Complex &c ) {
    Complex complex( c.Real() + d, c.Imaginary() );
    return complex;
}

Complex operator ""_i( unsigned long long int i ) {
    return Complex( 0, static_cast<double>(i) );
}

Complex operator ""_i(long double d ) {
    return Complex( 0, d );
}

int main() {
    // std::cout.precision(2); std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision( 2 ) << std::fixed;

    Complex num1( 2, 3 );
    Complex *num2 = new Complex( 3, 4 );
    std::cout << "첫 번째 복소수 " << num1;
    std::cout << ", 두 번째 복소수 " << *num2 << std::endl;

    std::cout << "\n단항 연산자 오버로딩 --------" << std::endl;
    std::cout << '-' << num1 << "는 ";
    std::cout << -num1 << "이다." << std::endl;

    Complex num3( 30, 20 );
    std::cout << "세 번째 복소수   : " << num3 << std::endl;
    std::cout << "세 번째 ++복소수 : " << ++num3 << std::endl;
    std::cout << "세 번째 복소수++ : " << num3++ << std::endl;
    std::cout << "세 번째 --복소수 : " << --num3 << std::endl;
    std::cout << "세 번째 복소수-- : " << num3-- << std::endl;

    Complex num4 = 10.0 + 30.0_i;
    std::cout << "네 번째 복소수   : " << num4 << std::endl;

    std::cout << "\n이항 연산자 오버로딩 --------" << std::endl;
    Complex sum = num1 + *num2;
    std::cout << sum << " = " << num1 << " + " << *num2 << std::endl;
    sum = num1 - *num2;
    std::cout << sum << " = " << num1 << " - " << *num2 << std::endl;

    sum = num3 * num1;
    std::cout << sum << " = " << num3 << " * " << num1 << std::endl;
    sum = num3 / num1;
    std::cout << sum << " = " << num3 << " / " << num1 << std::endl;

    sum += num3;
    std::cout << sum << "(" << sum.Real() << ',' << sum.Imaginary() << ')'
        << " += " << num3 << std::endl;

    std::cout << "\n비교 연산자 오버로딩 --------" << std::endl;
    std::cout << std::boolalpha;
    bool b = num1 == *num2;
    std::cout << num1 << " == " << *num2 << "는 " << b << "이다." << std::endl;
    b = num1 != *num2;
    std::cout << num1 << " != " << *num2 << "는 " << b << "이다." << std::endl;
    
    Complex d1 = 10;
    Complex d2 = d1 + static_cast<Complex>(10.1);
    std::cout << d2 << " = " << d1 << " + " << 10.1 << std::endl;
    Complex d3 = 20.1 + num3;
    std::cout << d3 << " = " << 20.1 << " + " << num3 << std::endl;
    delete num2;

    return 0;
}

constexpr Complex::Complex(double real) : real(real), imaginary(0.0){ }

constexpr Complex::Complex( double real, double imaginary ) 
            : real(real), imaginary(imaginary) { }

Complex& Complex::operator +() {
    //    std::cout << "Complex operator +()" << std::endl;
    return *this;
}

Complex Complex::operator -() {
    //    std::cout << "Complex operator -()" << std::endl;
    Complex complex( -this->real, -this->imaginary );
    return complex;
}

Complex& Complex::operator ++() {
    ++this->real;
    ++this->imaginary;
    return *this;
}

Complex Complex::operator ++( int ) {
    Complex complex( this->real, this->imaginary );
    ++this->real;
    ++this->imaginary;
    return complex;
}

Complex& Complex::operator --() {
    --this->real;
    --this->imaginary;
    return *this;
}

Complex Complex::operator --( int ) {
    Complex complex( this->real, this->imaginary );
    --this->real;
    --this->imaginary;
    return complex;
}

inline Complex Complex::operator +( const Complex& c ) const {
    //        std::cout << "Complex operator +(const Complex& c)" << std::endl;
    return Complex( this->real + c.real, this->imaginary + c.imaginary );
}

Complex Complex::operator -( const Complex& c ) const {
    //        std::cout << "Complex operator -(const Complex& c)" << std::endl;
    return Complex( this->real - c.real, this->imaginary - c.imaginary );
}

Complex Complex::operator *( const Complex& c ) const {
    return Complex(
        (this->real * c.real) - (this->imaginary * c.imaginary),
        (this->real * c.imaginary) + (this->imaginary * c.real) );
}

Complex Complex::operator /( const Complex& c ) const {
    double r = ((this->real * c.real) + (this->imaginary * c.imaginary)) /
        ((c.real * c.real) + (c.imaginary * c.imaginary));
    double i = ((this->imaginary * c.real) - (this->real * c.imaginary)) /
        ((c.real * c.real) + (c.imaginary * c.imaginary));
    return Complex( r, i );
}

Complex& Complex::operator =( const Complex& c ) {
    if (this == &c)
        return *this;

    this->real = c.real;
    this->imaginary = c.imaginary;
    return *this;
}

Complex& Complex::operator +=( const Complex& c ) {
    this->real += c.real;
    this->imaginary += c.imaginary;
    return *this;
}

Complex& Complex::operator -=( const Complex& c ) {
    this->real -= c.real;
    this->imaginary -= c.imaginary;
    return *this;
}

bool Complex::operator ==( const Complex& c ) {
    if (this->real == c.real && this->imaginary == c.imaginary)
        return true;
    else return false;
}

bool Complex::operator !=( const Complex& c ) {
    return !operator==( c );
}

Complex::operator char *() const {
    char *buffer = new char[20];
    snprintf(buffer, 20, "(%.2f + %.2fi)", real, imaginary);
    return buffer;
}
/*    
std::ostream& operator<<( std::ostream& os, const Complex& c ) {
    os << '(' << c.real << " + " << c.imaginary << "i" << ')';
    return os;
}
*/