#include <iostream>
#include <string>

class Shape {
public:
    Shape(std::string n) : name(n){}

    void GetArea(){ 
        std::cout << "Shape->도형 이름 : " << GetName() 
                << ",\t 도형 크기 : " << Area() << std::endl; 
    }
    
    double Area() { return 0; } 
    
    std::string& GetName() {
        return name;
    }
        
private:
    std::string name;
};

class Rectangle : public Shape {
public:
    Rectangle(std::string n, float w = 0, float h = 0) 
             : Shape(n), width(w), height(h) {}

    double Area() const {
        return (width * height);
    }

    void GetArea() {
        std::cout << "Rectangle->도형 이름 : " << GetName()
            << " , 도형 크기 : " << Area() << std::endl;
    }
    
protected:
    float width;
    float height;
};

int main() {
    Shape *s= new Rectangle ("직사작형", 10, 5);
    s->GetArea();
    
    // Rectangle *r = static_cast<Rectangle *>(s);
    Rectangle *r = (Rectangle *)s;
    r->GetArea();
    delete s;
    return 0;
}
