#include <iostream>
#include <type_traits>
#include <typeinfo>

template<typename T1, typename T2>
typename std::enable_if<std::is_same<T1, T2>::value, bool>::type 
check_type(const T1& t1, const T2& t2) { 
    std::cout << t1 << "과 " << t2
              << "는 같은 타입이다."  << std::endl;
    return true;
} 

template<typename T1, typename T2>
typename std::enable_if<!std::is_same<T1, T2>::value, bool>::type 
check_type(const T1& t1, const T2& t2) { 
    std::cout << t1 << "과 " << t2
              << "는 서로 다른 타입이다."  << std::endl;
    return false;
} 

int main() {    
    check_type(10, 40);
    check_type(10, 40.56);
    check_type(10, "Test 타입");
}   