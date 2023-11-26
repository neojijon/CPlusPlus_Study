#include <iostream>
#include <cstring>
#include <cstdlib> 

struct Account {
    char *account;
    char *name;  
    int balance; 
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

Account * OpenAcct(const char *id, const char *name, int bal){
    Account *temp = new Account();
    if (nullptr == temp)
        return nullptr;
    
    char *newid = new char[strlen(id) + 1];
    if (nullptr == newid) return nullptr;
    strcpy(newid, id);
    temp->account = newid;

    char *newname = new char[strlen(name) + 1];
    if (nullptr == newname) return nullptr;

    strcpy(newname, name);
    temp->name = newname;
    temp->balance = bal;
    std::cout << "Account 객체를 생성하였습니다." << std::endl;
    return temp;
}

int CloseAcct(Account *acct) {
    std::cout << "Account 객체를 삭제하였습니다." << std::endl;
    delete[] acct->account;
    delete[] acct->name;
    delete acct;
    return 1;
}

int main() {
    Account *hong = OpenAcct("120-345-129099", "홍길동", 60000);
    if (nullptr == hong) 
        return -1;
    
    Account *kim = OpenAcct("129-345-929100", "김홍도", 0);
    if (nullptr == kim) 
        return -1;
    
    hong->Withdraw(2000);
    kim->Deposit(2000);
    hong->Print();
    kim->Print();
    
    CloseAcct(hong);
    CloseAcct(kim);
    return 0;
}