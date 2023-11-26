#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int(*FuncType)(int,int) ; 
                                  
int add(int a, int b) { return a + b; }
int substract(int a, int b) { return a - b; }

int functionFactory(char c, int a, int b) {
    if (c == '+')
          return add(a, b);
    else  return substract(a, b);
}

int main() {
    char op = 0;
    printf("데이터 입력 '+' 또는 '-' ");
    scanf("%c", &op);

    if (op == '+')
          printf("4 + 5 = %d \n", add(4, 5));
    else  printf("4 - 5 = %d \n", substract(4, 5));
    
    int sum = functionFactory(op, 6, 6); 
    printf("%d = functionFactory('%c')( 6, 6);\n", sum, op);
}
