#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

class Box {
public:
    Box(int width, int length, int height) : width(width), length(length), height(height) {
        printf("Box(%d, %d, %d) 생성자가 호출되었습니다.\n", width, length, height);
    }
    
    ~Box() {
        std::cout << "Box 소멸자가 호출되었습니다." << std::endl;
    }
    int Volume() {return width * length * height; }
private:
    int width;
    int length;
    int height;
};

class StorageBox : public Box {
public:
    StorageBox(const char *name, int width, int length, int height)
                              : Box(width, length, height) {
        size_t l = strlen(name) + 1;
        this->name = new char[l];
        strcpy_s(this->name, l, name);
        printf("StorageBox(%s, %d, %d, %d) 생성자가 호출되었습니다.\n", 
                name, width, length, height);
    }

    ~StorageBox() {
        delete name;
        std::cout << "StorageBox 소멸자가 호출되었습니다." << std::endl;
    }

private:
    char *name;
};

int main(){
    { 
        Box *sb2 = new StorageBox("포인터 객체", 10 , 20, 20);
        delete sb2;
    }
    std::cout << "정상적인 경우 -----------------" << std::endl;
    { 
       StorageBox sb("일반 변수", 10 , 20, 20);
       Box& rb = sb; // 참조를 만든다.
    }
}
