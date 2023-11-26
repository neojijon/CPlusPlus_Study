#include <iostream>
#include <string>
#include <cstring>

class MyString {
public:
    MyString(const char *n);
    MyString(const MyString &my) = default; // 복사 생성자
    ~MyString();

    const char* GetString() const;
    int GetLength() const;
    
private:
    char* data;
    int length;
};

// 일반 생성자이다.
MyString::MyString(const char *n){
    if (nullptr == n){
        data = nullptr;
        length = 0;
        return;
    }
    
    int mLength = strlen(n);
    if (0 == mLength) {
        data = nullptr;
        length = 0;
        return;
    }
    
    char *temp = new char[mLength + 1];
    std::strcpy(temp, n);
    data = temp;
    length = mLength;
    
    printf("MyString::MyString(const char '%s')\n", n);
}

MyString::~MyString(){
    printf("MyString::MyString('%s') 소멸자 호출\n", data);
    if (nullptr != data) {
        delete[] data;

        data = nullptr;
        length = 0;
    }
}

const char* MyString::GetString() const {
    return data;
}

int MyString::GetLength() const {
    return length;
}

void display(const MyString& other) {
   std::cout << other.GetString() << std::endl;
}

int main() {
    MyString s1("Hello World");
    display(s1);
    MyString obj = s1;
    return 0;
}