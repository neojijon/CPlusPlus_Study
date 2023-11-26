#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Rec {
    char account[20];
    char name[20];  
    int balance;     

    void (*Deposit)();
    void (*Withdraw)();
    void (*Print)();
};

typedef struct Rec Account;

void Deposit(Account *this, int money){
    this->balance += money;
}

void Withdraw(Account *this, int money){
    this->balance -= money;
}

void Print(Account *this) {
    printf("계 좌 : %s , 소유자 : %s", 
          this->account, this->name);
    printf(", 잔 액 : %i\n", this->balance);
}

void OpenAcct(Account *this,
              const char *id,
              const char *nm,
              int bal){
    strcpy(this->account, id);
    strcpy(this->name, nm);
    this->balance = bal;
    // 함수 포인터에 전역 함수를 넣는다.
    this->Deposit = &Deposit;
    this->Withdraw = &Withdraw;
    this->Print = &Print;
}

int main() {
    Account hong;
    OpenAcct(&hong, "120-345-129099",
             "홍길동", 60000);
    hong.Withdraw(&hong, 10000);
    hong.Print(&hong);
    return 0;
}
