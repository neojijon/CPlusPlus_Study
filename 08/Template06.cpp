#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>

template<typename T, size_t size>
constexpr size_t GetArrLength(T (&)[size]){
    return size;
}

template<class T, int N>
void LinkedList(T (&arr) [N]) {
    for( int i(0); i < N; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

template<const int* pci, size_t size> 
struct Array {
    void Print() {
    for( int i(0); i < size; ++i)
        std::cout << pci[i] << ' ';
    std::cout << std::endl;
}
};
int ai[10];

int main() {
   int a[] = { 4, 6, 8, 32, 19 } ;
   std::cout << "배열의 크기 : " << GetArrLength(a) << std::endl;
   LinkedList<int> ( a );
   
   for ( int i = 0; i < 10; ++i) ai[i] = a[i%5];
   Array<ai, 10> xi;
   xi.Print();
}
