#include <iostream>

template <class T> 
class Form {
    T* _t;
public:
    Form(T* t) : _t(t) { }
    void print(){
        std::cout << *_t << std::endl;
    }
};

template<> 
class Form<char *> {
    char* _t;
public:
    Form(char* t) : _t(t) { }
    void print(){
        std::cout << "Form<char *> : " << _t << std::endl;
    }
};

int main(){
    int i = 157;
    Form<int> form1(&i);

    char c[10] = "string1";
    Form<char*> form2(c);

    form1.print(); 
    form2.print(); 
}
