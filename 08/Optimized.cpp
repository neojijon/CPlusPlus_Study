##include <iostream>
#include <string>

template< class T >
struct Base {
    typedef T type;
    virtual void Display() = 0;
};

template< class T >
class Optimized : public Base<T> {
    typename  Base<T>::type  data;
public:
    Optimized(typename Base<T>::type c) : data(c) {}

    typename  Base<T>::type  GetData() {
        return data;
    }
    virtual void Display() final;
};

class Derived : public Base<int> {
    typename  Base::type  data;
public:
    Derived(typename Base::type c) : data(c) {}

    typename  Base::type  GetData() {
        return data;
    }
    virtual void Display() final;
};

int main() {
    Optimized<int> e(100);
    Base<std::string>::type s = "문자열 입력";
    std::cout << "Optimized의 data : " << e.GetData() << std::endl;
    e.Display();
    std::cout << s << std::endl;

    Derived d(1200);
    std::cout << "Derived의 data : " << d.GetData() << std::endl;
    d.Display();
}

template< class T >
void Optimized<T>::Display() {
    std::cout << "Optimized : " << data << std::endl;
}

void Derived::Display() {
    std::cout << "Derived : " << data << std::endl;
}