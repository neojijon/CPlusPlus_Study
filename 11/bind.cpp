#include <string>
#include <iostream>

double my_divide (double x, double y) {return x/y;}
 
void goodbye(const std::string& s) {
    std::cout << "Goodbye " << s << std::endl;
}

class Object {
public:
    void hello(const std::string& s) {
        std::cout << "Hello " << s << std::endl;
    }
};

int main(int argc, char* argv[]) {
    Object instance;
    std::string str("World");

    auto f1 = std::bind(&Object::hello, &instance, str);
    f1(); 

    std::cout << std::bind(my_divide, 10, 2)() << std::endl;
    auto f2 = std::bind(&goodbye, str);
    f2();
    return 0;
}
