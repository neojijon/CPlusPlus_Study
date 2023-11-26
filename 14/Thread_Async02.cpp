#include <iostream>
#include <future>

int main(){
    auto f = []() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "작업 종료" << std::endl;
    };

    auto handle = std::async(f);
    std::cout << "비동기함수 호출" << std::endl;
    handle.wait();
}
