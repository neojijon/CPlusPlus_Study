#include <cstdio>
#include <iostream>
#include <string>

class Box {
public:
    Box(int width = 0, int length = 0, int height = 0) 
        : m_width(width), m_length(length), m_height(height){
        printf("Box(%d, %d, %d) 생성자가 호출되었습니다.\n", 
                width, length, height);
    }
  
//    virtual ~Box() {
    ~Box() {
        std::cout << "Box 소멸자가 호출되었습니다." << std::endl;
    }
    
    int operator()() {return m_width * m_length * m_height; }
    int operator()(int h) {return m_width * m_length * h; }
private:
    int m_width;
    int m_length;
    int m_height;
};

int main(){
    Box sb(10 , 20, 20);
    std::cout << "박스(10 , 20, 20)의 크기 = " << sb() << std::endl;
    std::cout << "박스(10 , 20, 2)의 크기 = " << sb(2) << std::endl;
}