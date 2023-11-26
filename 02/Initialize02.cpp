#include <iostream>
#include <cstdio>
#include <cstring>

struct Data {
	// 멤버 변수 선언
	int age;
	char name[100];
    int balance;
    Data() {
        age = 0; 
        memset(name, 0, 100);
        balance = 0;
    }
    Data(int a, const char *n, int b) {
        age = a; 
        strcpy(name, n);
        balance = b;
    }
};

void Print(Data user){
	std::cout << user.age << ", " << user.name 
              << ", 잔 액 : " << user.balance << std::endl;
}

int main (){
       Data user02(33, "이순신", 20000);
    Data user04 = Data(45, "이성계", 60000);
    Data *user05 = new Data( 60, "연개소문", 50000);
    Data user08;

    Print(user02);
    Print(user04);
    Print(*user05);
    Print(user08);

}
