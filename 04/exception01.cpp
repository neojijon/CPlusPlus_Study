#include <stdexcept>
#include <iostream>

void CopyObject(const char *original) {
    if (nullptr == original) {
        throw -1;
    }
    std::cout << original << std::endl;
}

int main() {
    try {
        char *name = nullptr;
        CopyObject(name);
    } catch(int e) {
        std::cerr << e << std::endl;
    }
    std::cout << "프로그램 종료!" << std::endl;
    return 0;
}
