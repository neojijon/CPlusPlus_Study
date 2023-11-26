#include <iostream>
#include <cstring>

union DataValue01 {
    int    v_int;
    float  v_float;
    char  v_string[4];
};

struct DataValue02 {
    int    v_int;
    float  v_float;
    char  v_string[4];
};

int main(){
   std::cout << "공용체의 크기 = " << sizeof(DataValue01) << std::endl;
   std::cout << "구조체의 크기 = " << sizeof(DataValue02) << std::endl; 
}