#include <iostream>

namespace sample{
void SampleMethod() {
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
    return 0;
}
