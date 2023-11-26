// g++ -std=c++11 -fno-elide-constructors CopyElision.cpp    
#include <iostream>  
#include <string>
#include <algorithm>

int count = 0;  

class MyString {  
    std::string data;

public:  
    MyString(const char *ptr = nullptr) : data(ptr) { 
        std::cout<< "Constructor : " << ptr << std::endl; 
    }  
    MyString(const MyString  &obj) : data(obj.data) { 
        std::cout<<"copy constructor : " << data.c_str() << std::endl;
        ++count;
    }  
    MyString(MyString&& obj) { 
        std::swap(this->data, obj.data);
        std::cout<<"Move constructor : " << data.c_str() << std::endl; 
        ++count;
    } 
    
    // MyString(const MyString& ) = delete;
    // MyString(const MyString&& ) = delete;
    
    ~MyString() { 
        std::cout<<"Destructor  : " << data.c_str() <<std::endl; 
    }

    MyString& operator= (const MyString & other){
        if (this != &other) {
            data = other.data;
        }
        printf("MyString& MyString::operator = (Mystring& '%s')\n", this->data);
        ++count;
        return *this;
    }

    MyString& operator= (MyString&& other) noexcept {
        if (this != &other) {
            std::swap(this->data, other.data);
        }
        printf("MyString& MyString::operator = (Mystring&& '%s')\n", this->data);
        ++count;
        return *this;
    }    
};

MyString fun123(const char *ptr = nullptr) { 
    MyString obj(ptr); 
    return obj; 
}  

MyString xyz123(const char *ptr = nullptr) {  
    return MyString{ptr}; 
}  

void foo(const char *ptr = nullptr) {  
  throw MyString(ptr);
}

int main() {  
    MyString abc = {"abc"};
   
    MyString obj1(fun123("fun123()"));
    MyString obj2(xyz123("xyz123()"));  
    
    MyString xyz = "Return Value Optimization";
    try {
      foo("throw MyString");
    } catch(MyString& c) {  
    }             
    std::cout<< "호출 횟수 : " << count << std::endl; 
    return 0;  
}
