#include <cstdlib>
#include <iostream>
#include <string>
#include <new>

void *operator new( size_t sz) {
    std::cout << "new called. 크기 : " << sz << std::endl ;
    return std::malloc( sz );
}

void operator delete( void *ptr ) noexcept { 
    std::cout << "delete called.\n";
    std::free( ptr );
}

class MyString {
    char *mData;
    size_t mDataLength;
};

class MyString {
    char *mData;
    size_t mDataLength;
};

int main() {
     int* p1 = new int;
     delete p1;
 
     int* p2 = new int[10];
     delete[] p2;
     
     MyString* p3 = new MyString();
     delete p3;
}
