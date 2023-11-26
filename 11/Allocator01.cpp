#include <iostream> 
#include <memory> 

#define SIZE   5

int main() {
    std::allocator<int> myAllocator;
    int* arr = myAllocator.allocate(SIZE);
    for (size_t i = 0; i < SIZE; ++i) arr[i] = 0;
	
    arr[0] = 100;
    arr[3] = 10;

    for (size_t i = 0; i < SIZE; ++i)
        std::cout << arr[i] << ' ';

    std::cout << std::endl;
    myAllocator.deallocate(arr, SIZE);
    return 0;
}