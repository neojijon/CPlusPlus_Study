#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

class MyString {
public:
    MyString(const char *n = nullptr);
    MyString(const MyString &other);
    MyString(MyString&& other) noexcept; 
    ~MyString();

    MyString& operator= (const MyString& other);
    MyString& operator= (MyString&& other) noexcept;
    void SetString(const char* n);
    const char* GetString() const;
    int GetLength() const;
    
private:
    char* data;
    int length;
};

MyString::MyString(const char *n) : data(nullptr), length(0){
    SetString(n);
    printf("MyString::MyString(const char '%s')\n", n);
}

MyString::MyString(const MyString &other) : data(nullptr), length(0){
    SetString(other.GetString());
    printf("MyString::MyString(const MyString& '%s')\n", data);
}

MyString::MyString(MyString&& other) noexcept 
         : data(other.data), length(other.length){
    printf("MyString::MyString(MyString&& '%s')\n", data);
    other.data = nullptr;
    other.length = 0;
}
    
MyString::~MyString(){
    printf("MyString::MyString('%s') 소멸자 호출\n", data);
    if (data != nullptr) {
        delete[] data;
    }
}

MyString& MyString::operator= (const MyString& other){
    if (this != &other) { 
        delete[] data;
        SetString(other.GetString());
    }
    printf("MyString& MyString::operator = (Mystring& '%s')\n", this->data);
    return *this;
}

MyString& MyString::operator= (MyString&& other) noexcept {
    if (this != &other) {
         char* mData = this->data;
        int mLength = this->length;

        data = other.data;
        length = other.length;
        other.data = mData;
        other.length = mLength;
    }
    printf("MyString& MyString::operator = (Mystring&& '%s')\n", 
            this->data);
    return *this;
}

void MyString::SetString(const char* n){
    if (n == nullptr) return;

    int mLength = strlen(n);
    if (mLength == 0) return;

    data = new char[mLength + 1];
    std::strcpy(data, n);
    length = mLength;
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
    s2 = s1;

    std::cout << "vector---------------------------------------" << std::endl;
    std::vector<MyString> vec;
    vec.push_back(s1);
    vec.push_back(MyString("이동 생성자"));
    vec.push_back(MyString("이동 대입 연산자"));
    s2 = std::move(vec[2]);
    return 0;
}