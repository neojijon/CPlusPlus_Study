#include <chrono>
#include <iostream>
#include <cmath>
#include <ratio>

constexpr unsigned long fibonacci(unsigned long i) {
  return (i <= 1u) ? i : (fibonacci(i-1) + fibonacci(i-2));
}

using Chrono = std::chrono::steady_clock;

int main(){
    Chrono::time_point start = Chrono::now();
    std::cout << "f(42) = " << fibonacci(42) << '\n';
    Chrono::time_point end = Chrono::now();

    std::chrono::duration<double> defaultTime = end - start;
    std::cout << "피보나치수의 실행 시간 : " << defaultTime.count() << "초(default)" << std::endl;

    std::chrono::nanoseconds nano = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "피보나치수의 실행 시간 : " << nano.count()        << "나노초" << std::endl;

    std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::chrono::minutes min = std::chrono::duration_cast<std::chrono::minutes>(end - start);
    std::cout << "피보나치수의 실행 시간 : " << sec.count() << "초" << std::endl;
    std::cout << "피보나치수의 실행 시간 : " << min.count() << "분" << std::endl;
    
    using minutes = std::chrono::duration<double, std::ratio<60,1>>;
    minutes custom = std::chrono::duration_cast<minutes>(end - start);

    std::cout << "피보나치수의 실행 시간 : " << custom.count() << "분(수정)" << std::endl;
    return 0;
}


