#include <iostream>

namespace {
void SampleMethod() {
    std::cout << "무명 네임스페이스 내 SampleMethod 함수입니다." << std::endl;
}
}

namespace sample{
void SampleMethod() {
    ::SampleMethod();
    std::cout << "> sample 네임스페이스 내 SampleMethod 함수입니다." << std::endl;
}

namespace nested {
    void SampleMethod()  {
        std::cout << ">> nested 네임스페이스 내 SampleMethod 함수입니다." << std::endl;
    }
}
}

int main() { 
    sample::SampleMethod();
    sample::nested::SampleMethod();
    SampleMethod();
    ::SampleMethod();
    return 0;
}
