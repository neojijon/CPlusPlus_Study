#include <iostream>
#include <cstring>
#include <cstdlib> 

struct Account {
    Account(const char *id, const char *name, int bal)
           : account(new char[strlen(id) + 1]), 
             name(new char[strlen(name) + 1]),
             balance(bal) {
        strcpy(this->account, id);
        strcpy(this->name, name);
        std::cout << "Account 생성자가 호출되었습니다." << std::endl;
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
private:
    char *account; 
    char *name;    
    int balance;   
};
    
int main() {
    char id[] = "120-345-129099";
    char name[] = "홍길동";
    Account hong = Account(id, name, 60000);
    hong.Withdraw(10000);
    hong.Print();

    printf("계 좌 : %s , 소유자 : %s", hong.account, hong.name);
    printf(", 잔 액 : %i\n", hong.balance);
  
    return 0;
}
