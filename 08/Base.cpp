#include <iostream>
#include <string>

template<class T>
class Base {
public: 
    void set(const T& val) {
        data = val;
    }

    T get() {
        return data;
    }
private:
    T data;
};

template<class T, class U>
class Derived : public Base<T>  {
public:
    Derived(U& val) : derived (val) {
    }

    U get() {
        return derived;
    }
private:
    U derived;
};

int main() {
    std::string str("안녕하세요!");
    Derived < int, std::string > d(str);
    d.set(10);
    std::cout << d.get() << ", " << d.Base<int>::get() << std::endl;
}
