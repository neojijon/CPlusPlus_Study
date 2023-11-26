#include <iostream>
#include <vector>
#include <thread>

using Chrono = std::chrono::steady_clock;
using  int_futures = std::vector<std::thread>;
int main() {
    auto sleep = [](int s) {
        std::this_thread::sleep_for(std::chrono::milliseconds(s));
        return s;
    };

    int_futures  futures;
    Chrono::time_point start = Chrono::now();
    for (int i = 0; i < 10000; ++i) {
        futures.push_back(std::thread(sleep, 100));
    }
    for (int i = 0; i < 10000; ++i) {
        if ((i % 100) == 0)
            std::cout << '.';
        futures[i].join();
    }
    std::cout << std::endl;

    Chrono::time_point end = Chrono::now();
    std::chrono::milliseconds sec =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "실행 시간 : " << sec.count() << " 밀리초" << std::endl;
}
