#include <iostream>
#include <cstring>

#define None    1
#define Integer 2
#define Float   3
#define String  4
// enum DataType { None, Integer, Float, String };

union DataValue {
    int v_int;
    float v_float;
    char *v_string;
};

struct DataNode {
    int type;
    DataValue value;
	
    void read_some_input(){
        char *p;
        char s[100];
        std::cout << "문자나 정수 그리고 실수 입력을 부탁합니다. ";
        std::cin >> s;
    
        // 일반적으로 cin 변수를 사용한다면 NULL이 입력되지 않는다.
        // if (s == nullptr) type = None;
    
        long l = strtol(s, &p, 10);
        if (*p == 0) { 
            type = Integer; 
            value.v_int = l; 
            return;
        }
    
        float f = strtof(s, &p);
        if (*p == 0) { 
            type = Float; 
            value.v_float = f;       
            return;
        }
    
        type = String;
        value.v_string = (char *) malloc(strlen(s) + 1);
        strcpy(value.v_string, s);    
    }  
    
    void free_string(){
       if (String == type) {
           free(value.v_string);
       }
    }
};
    
int main() {
    DataNode inputData;
    inputData.read_some_input();

    switch(inputData.type){
       case Integer: 
            std::cout << "Integer : " << inputData.value.v_int << std::endl; break;
       case Float:
            std::cout << "Float : " << inputData.value.v_float << std::endl; break;       
       case String:  
            std::cout << "String : " << inputData.value.v_string << std::endl; break;       
    }
    inputData.free_string();
}
