#include <iostream>
#include <string>
#include <cstring>

class MyString {
public:
    MyString(const char *n);
    ~MyString();

    const char* GetString() const;
    int GetLength() const;
    
private:
    std::string data;
};

MyString::MyString(const char *n) : data(n){
    printf("MyString::MyString(const char '%s')\n", n);
}

MyString::~MyString(){
    printf("MyString::MyString('%s') 소멸자 호출\n", data.c_str());
}

const char* MyString::GetString() const {
    return data.c_str();;
}

int MyString::GetLength() const {
    return data.length();
}

void display(MyString other){
   std::cout << other.GetString() << std::endl;
}

int main() {
    MyString s1("Hello World"), s2 = "복사 생성자";
    display(s1);
    s2 = s1;
    display(s2);
    return 0;
}