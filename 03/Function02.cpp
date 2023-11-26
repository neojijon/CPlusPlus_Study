#include <iostream>
#include <cstdio>

void temp(int, double, const char *);
void temp(int i = 4, double f = 3.141592, const char *c = "");
void m();

int main(void){
   m();
   temp(600); 
   return 0;
}

void m() {
    void temp(int, double = 1.0, const char * = "안녕하세요!");
    temp(4, 6.1, "Hello Default Argument!"); 
    temp(64); // temp(64, 1.0, "안녕하세요!"); 로 변경되어 호출된다.
 
}

void temp(int i, double f, const char *c) {
    printf("정수 : %d, 실수 : %.4f, 문자 : %s\n", i, f, c);
}
