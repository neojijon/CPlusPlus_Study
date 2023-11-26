#include <iostream>
#include <string>

template <typename T> 
T min( T a, T b ) {
   return ( a < b ) ? a : b;
}

template <class Type>
Type max(Type a, Type b) {
    return a > b ? a : b;
}

int main(){
    std::cout << "최대값 : " << max(3, 7) << std::endl;
    std::cout << "최소값 : " << min(3.5, 7.6) << std::endl;
    
    // std::cout << max(3, 7.0) << std::endl; 
    std::cout << "최소값 : " << min(3.5, 7.6) << std::endl;
    std::cout << "최대값 : " << max<double>(3, 7.0) << std::endl;

    std::cout << "최소값 : " << min('a', 'b') << std::endl;
    std::cout << "최대값 : " << max<std::string>("Helo World", "안녕하세요") << std::endl;
    return 0;
}