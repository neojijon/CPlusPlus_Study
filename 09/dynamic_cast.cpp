#include <iostream>
#include <typeinfo> 

class Base { 
    int state;
public:
    Base() : state(0) {}
    Base(int i) : state(i) {}
    virtual int dummy() {
        std::cout  << "Base dummy() 호출.\n";
        return state;
    }    
};

class Derived : public Base { 
public:
    Derived(int i) : Base(i) {}
    void SetNumber(int i) {
        number = i;
    }    
    int number; 
};

int main () {
    Derived *pd;             
    Base * pba = new Derived(23);

    pd = dynamic_cast<Derived *>(pba);
    if (nullptr == pd) std::cout << "첫 번째 pba 객체의 변환이 실패하였습니다.\n";
    pd->SetNumber(10);
    std::cout << pd->number << std::endl;
    std::cout << pd->dummy() << std::endl;
    delete pba;
    
    Base * pbb = new Base(568);
   
    pd = dynamic_cast<Derived*>(pbb);
    if (nullptr == pd) std::cout << "두 번째 pbb 객체의 변환이 실패하였습니다.\n";
   
    pd = static_cast<Derived*>(pbb);
    pd->SetNumber(110);
    std::cout << pd->number << std::endl;
    std::cout << pd->dummy() << std::endl;
    delete pbb;
    return 0;
}
