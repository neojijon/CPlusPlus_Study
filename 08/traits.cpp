#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <type_traits>

template<class T>
typename std::enable_if<!std::is_lvalue_reference<T>(), T&>::type
min(T& a, T& b) {
    std::cout << "변  수 ";
    return (a < b) ? a : b;
}

template<class T>
typename std::enable_if<std::is_lvalue_reference<T>::value, T>::type
min(T a, T b) {
    std::cout << "참  조 ";
    return (a < b) ? a : b;
}

template<class T>
T min(T* a, T* b) {
    std::cout << "포인터 ";
    return (*a < *b) ? *a : *b;
}

class Shape {
public:
    Shape(std::string n) : name(n) {}
    void GetArea() {
        std::cout << "도형 이름 : " << GetName()
            << ",\t 도형 크기 : " << Area() << std::endl;
    }

    // 함수를 가상 함수로 선언한다.
    virtual double Area() { return 0; }
    std::string GetName() {
        return name;
    }
private:
    std::string name;
};

class Rectangle : public Shape {
public:
    Rectangle(std::string n, double w = 0, double h = 0) : Shape(n), width(w), height(h) {}

    // 아래 함수는 상위 클래스 내 Area() 함수를 구현하였다.
    double Area() {
        return (width * height);
    }

protected:
    double width;
    double height;
};

const double PI = 3.14159;

class Circle : public Shape {
public:
    Circle(double r = 0) : Shape("원"), radius(r) {}
    double Area() override { return (PI * (radius * radius)); }

protected:
    double radius;
};

bool operator<(Shape& a, Shape& b) {
    return a.Area() < b.Area();
}
bool operator>(Shape& a, Shape& b) {
    return a.Area() < b.Area();
}

int main() {
    int tmp01 = 10;
    int tmp02 = 20;
    int& tmp03 = tmp01;
    int& tmp04 = tmp02;
    int* a = &tmp01, * b = &tmp02;
    std::cout << "1. 최소값 : " << min<int>(*a, *b) << std::endl;
    std::cout << "2. 최소값 : " << min<int&>(tmp03, tmp04) << std::endl;
    std::cout << "3. 최소값 : " << min(a, b) << std::endl;

    Rectangle shape01 = Rectangle("직사작형", 10, 5);
    Circle shape02 = Circle(10);
    std::cout << "4. 최소값 : ";
    Shape& s1 = min<Shape&>(shape01, shape02);
    s1.GetArea();

    std::cout << "5. 최소값 : ";
    Shape& s2 = min<Shape>(shape01, shape02);
    s2.GetArea();
}