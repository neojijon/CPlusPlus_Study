#include <iostream>
#include <string>

class Shape {
    public:
       virtual void Draw(){};
       static Shape* create(std::string type);
};

class Circle : public Shape {
    public:
       void Draw() { std::cout << "원입니다." << std::endl; }
};

class Square : public Shape {
    public:
       void Draw() { std::cout << "정사각형입니다." << std::endl; }
};

Shape* Shape::create(std::string type) {
    if ( type == "circle" ) return new Circle();
    if ( type == "square" ) return new Square();
    return NULL;
}

int main(){
   Shape* obj1 = Shape::create("circle");
   Shape* obj2 = Shape::create("square");

   obj1->Draw();
   obj2->Draw();
}
