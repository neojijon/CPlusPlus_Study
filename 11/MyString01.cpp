#include <iostream>
#include <string>
#include <cstring>
#include <memory>

class MyString {
public:
    MyString(const char *n);
    MyString(const MyString &my);
    ~MyString();

    MyString& operator= (const MyString& other);
    void SetString(const char* n);
    const char* GetString() const;
    int GetLength() const;
    
private:
    std::unique_ptr<char> data;
    int length;
};

MyString::MyString(const char *n) : data(nullptr), length(0){
    SetString(n);
    printf("MyString::MyString(const char '%s')\n", n);
}

MyString::MyString(const MyString &other) : data(nullptr), length(0){
    SetString(other.GetString());
    printf("MyString::MyString(const MyString& '%s')\n", data.get());
}

MyString::~MyString(){
    if (nullptr != data) {
        printf("MyString::MyString('%s') 소멸자 호출\n", data.get());
        data.reset(nullptr);
        length = 0;
    }
}

MyString& MyString::operator= (const MyString& other){
    if (this != &other) { // 자기 자신을 대입하는 것은 무의미한 작업이다.
        data.reset(nullptr);
        SetString(other.GetString());
    }
    printf("MyString& MyString::operator = (Mystring& '%s')\n", this->data.get());
    return *this;
}

void MyString::SetString(const char* n){
    if (n == nullptr) return;

    int mLength = strlen(n);
    if (mLength == 0) return;

    data = std::make_unique<char>(mLength + 1);
    std::strcpy(data.get(), n);
    length = mLength;    
}

const char* MyString::GetString() const {
//    char *temp = new char[length + 1];
//    std::strcpy(temp, data.get());
    return data.get();
}

int MyString::GetLength() const {
    return length;
}

void display(MyString& obj){
   std::cout << obj.GetString() << std::endl;
}
 
int main() {
    MyString s1("Hello World");
    display(s1);
    MyString obj = s1;
  
    return 0;
}