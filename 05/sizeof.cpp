#include <iostream>

struct Bit { unsigned char bit: 1; };

size_t size(int * p) { 
    std::cout << "size() 함수 내 배열의 메모리 크기\t: " << sizeof(*p) << std::endl;
    return sizeof(p) / sizeof(*p);
}

int main() {
    Bit bit;
    int arr[20];

    std::cout << "main() 함수 내 Bit 구조체의 크기\t: "   << sizeof(bit) << '\n'
//            << "bit 변수의 비트 크기\t: " << sizeof bit.bit << '\n'  // 에러가 발생
              << "main() 함수 내 배열의 메모리 크기\t: "   << sizeof(arr)  << '\n';
    size_t i = size(arr);
    std::cout << "배열의 크기 : " << (sizeof(arr) / sizeof(arr[0]))
              << ", size() 함수로 반환받은 크기 : " << i << std::endl;
}