#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int(*FuncType)(int,int) ; 
                                  
int add(int a, int b) { return a + b; }
int substract(int a, int b) { return a - b; }

FuncType functionFactory(char c) {
    FuncType function = (c == '+')? &add : &substract;
    return function;
}

int main() {
    char op = 0;
    printf("데이터 입력 '+' 또는 '-' ");
    scanf("%c", &op);

    FuncType function = (op == '+')? &add : &substract;
    printf("4 %c 5 = %d \n", op, function(4, 5));
    
    int sum = functionFactory(op)(6, 6); 
    printf("%d = functionFactory('%c')(6,6);\n", sum, op);
}
