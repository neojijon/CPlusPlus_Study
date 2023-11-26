#include <iostream>
#include <string>
#include <cstring>

class MyString {
public: 
    MyString(const char *n);
    MyString(const MyString &other); 
    ~MyString();

    void SetString(const char* n);
    const char* GetString() const;
    int GetLength() const;
    
private:
    void Release();
    char* data;
    int length;
};

MyString::MyString(const char *n) : data(nullptr), length(0){
    SetString(n); 
    printf("MyString::MyString(const char '%s')\n", n);
}

MyString::MyString(const MyString &other) : data(nullptr), length(0){
    SetString(other.GetString());
    printf("MyString::MyString(const MyString& '%s')\n",data);
}

MyString::~MyString(){
    printf("MyString::MyString('%s') 소멸자 호출\n", data);
    Release();
}

void MyString::SetString(const char* n){
    if (nullptr == n) {
        std::cout << "nullptr" << std::endl;
        return;
    }

    int mLength = strlen(n);
    if (0 == mLength) {
        std::cout << "" << std::endl;
        return;
    }

    data = new char[mLength + 1];
    std::strcpy(data, n);
    length = mLength;
}

void MyString::Release(){
    if (data != nullptr) {
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

void display(MyString other){
   std::cout << other.GetString() << std::endl;
}

int main() {
    MyString s1("Hello World"), s2 = "복사 생성자";
    display(s1);
    return 0;
}

