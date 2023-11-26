#include <cstdlib> // qsort() 함수
#include <random>  // std::random_device 클래스
#include <iostream>

int main(){
    int array[10];
    int i;

    std::random_device rd;
    srand((unsigned)rd());
    for ( i = 0; i < 10; ++i ) {
        array[i] = std::rand() % 1000; 
    }
    
    std::cout << "sort 전 : ";
    for ( i = 0; i < 10; ++i ){
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    auto sorter = [] (const void *first, const void *second ) -> int {
        return( *(int *)first - *(int *)second);
    };
    
    qsort( array, 10 , sizeof( int ), sorter );

    std::cout << "sort 후 : ";
    for ( i = 0; i < 10; ++i ){
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}
