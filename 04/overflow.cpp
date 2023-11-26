#include <stdexcept>
#include <iostream>

void MyFunc(char c) {
    std::cout << "c = " << (int) c << std::endl;
}

int main() {
    try {
        char x = 1;
        MyFunc(x + 127); 
    } catch (std::overflow_error& e) {
        std::cerr << e.what() << std::endl;
    } catch(...) { 
        std::cerr << "모든 exception 처리." << std::endl;
   }
    return 0;
}
