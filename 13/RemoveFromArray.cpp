#include <iostream>

template<typename T>
void RemoveFromArray(T *array, int& length, T id) {
    int current = -1;
    for (int i = 0; i < length; ++i) {
        if (array[i] == id) {
            current = i;
            break;
        }
    }
	
    if ( -1 != current) {
        int del = 1;
        for (int i = current + 1; i < length; ++i) {
            if (array[i] != id) {
                array[current++] = std::move(array[i]);
            } else ++del;
        }
        length -= del;
    }
}

int main() {
    int numbers[] = { 11, 32, 4, 99, 2, 4, 12, 90, 1, 56};
    int length = sizeof(numbers) / sizeof(int);

    std::cout << "원본 데이터 : ";
    for (int i = 0; i < length; ++i)
        std::cout << numbers[i] << ' ';
    std::cout << std::endl;
    
    RemoveFromArray( numbers, length, 4);
    std::cout << "수정 데이터 : ";
    for (int i = 0; i < length; ++i)
        std::cout << numbers[i] << ' ';
    std::cout << std::endl;
    return 0;
}