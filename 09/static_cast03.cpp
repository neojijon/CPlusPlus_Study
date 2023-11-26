#include <iostream>

class Base { 
public:
    virtual void dummy() {
        std::cout  << "Base dummy() 호출.\n";
    } 
};
class Derived : public Base { 
public:
    void SetNumber(int i) {
        number = i;
    }    
    int number; 
};

int main () {
    Derived d;
    Base& br = d;
    Derived & another_d = static_cast< Derived &>(br);
    printf("d = %p, br = %p, another_d = %p\n", &d, &br, &another_d);
	
    Derived a[10];
    Base* dp = static_cast<Base*>(a);
    printf("a = %p, dp = %p\n", a, dp);
}  