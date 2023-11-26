#include <iostream>

class Object {
public:
    virtual bool Equals(Object& other) { 
        std::cout << "Object->Equals()" << std::endl; 
        return this == &other;
    }

    std::string name;        
};

class Rectangle : virtual public Object {
public:
    Rectangle() : Object() { } 
    
    virtual bool Equals(Rectangle& other) { 
        std::cout << "Rectangle->Equals()" << std::endl; 
        return this == &other;
    }
};

class Clickable : virtual public Object {
public:
    Clickable() : Object(){ } 
    
    virtual bool Equals(Clickable& other) { 
        std::cout<<"Clickable->Equals()"<<std::endl; 
        return this == &other;
    }
};

class Button : public Rectangle, public Clickable {
public:
    Button() : Rectangle(), Clickable(){ }
};

int main(void){
    Button button;
    button.name = "Button";
    std::cout << std::boolalpha;
    std::cout << "button.Equals(button) = " << button.Equals(button) << std::endl;
    Button b2;
    std::cout << "button.Equals(b2) = " << button.Equals(b2) << std::endl;
    return 0;
}