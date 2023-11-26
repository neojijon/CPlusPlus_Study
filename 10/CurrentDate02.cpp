#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

int main( ){
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    std::time_t epoch = std::chrono::system_clock::to_time_t(now);
    std::cout << "1970년 1월 1일 00:00:00 이후 진행된 시간(초) : " << epoch << std::endl;

    std::cout << "현재 시간 : " << std::put_time(std::localtime(&epoch), "%c") << std::endl;
   
    std::time_t now_c = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
    std::cout << "어제 시간 : "
              << std::put_time(std::localtime(&now_c), "%F %T") << '\n';
}