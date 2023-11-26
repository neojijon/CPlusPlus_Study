#include <iostream>

class SimpleClass {
  public:
    int xval;
};

int main() {
    SimpleClass ss;
    ss.xval = 5;
    std::cout << "객체에 저장된 값은 " << ss.xval << "이다.\n";
}
