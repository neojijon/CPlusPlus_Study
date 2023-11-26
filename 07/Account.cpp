#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib> 

struct Account {
    char *account;   // 계좌 번호 
    char *name;     // 이  름
    int balance;     // 잔  액 
    Account(const char *id, const char *name, int bal){
        this->account = new char[strlen(id) + 1];
        strcpy(this->account, id);

        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->balance = bal;
        std::cout << "Account 생성자가 호출되었습니다." << std::endl;
    }

    ~Account() {
        std::cout << "Account 소멸자가 호출되었습니다." << std::endl;
        delete[] account;
        delete[] name;
    }

    void Print() {
        printf("계 좌 : %s , 소유자 : %s", account, name);
        printf(", 잔 액 : %i\n", balance);
    }
    
    void Deposit(int money){
        balance += money;
    }
    
    void Withdraw(int money){
        balance -= money;
    }  
};
    
int main() {
    Account *hong = new Account("120-345-129099", "홍길동", 60000);
    if (NULL == hong) 
        return -1;
    
    {  
        Account kim("129-345-929100", "김홍도", 0);
        hong->Withdraw(2000);
        kim.Deposit(2000);
        hong->Print();
        kim.Print();
    }

    delete hong;
    return 0;
}
