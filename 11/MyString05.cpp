#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include <cassert>
#define  NDEBUG

class MyString {
public:
    MyString(const char *n);
    MyString(const MyString &my) = default;
    ~MyString();

    const char* GetString() const;
    int GetLength() const;
    
private:
    std::shared_ptr<char> data;
    int length;
};

template<typename T> 
std::shared_ptr<T> make_shared_array(size_t size){
   return std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
}

MyString::MyString(const char *n) : data(nullptr), length(0){
    if (nullptr == n) return;
    
    int mLength = strlen(n);
    if (0 == mLength) return;
    
    data = make_shared_array<char>(mLength + 1);
    std::strcpy(data.get(), n);
    length = mLength;
    
    printf("MyString::MyString(const char '%s')\n", n);
}

MyString::~MyString(){
    if (nullptr != data) {
        printf("MyString::MyString('%s') : %d 소멸자 호출\n", 
               data.get(), data.use_count());
        data.reset();
        assert (data == nullptr && data.get() == nullptr);
        length = 0;
    }
}

const char* MyString::GetString() const {
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