#include <iostream> 

class Box {
public: 
    Box(int width = 0, int length = 0, int height = 0) 
        : width(width), length(length), height(height) {};
    inline int Volume() {return width * length * height; }

private:
    int width;
    int length;
    int height;
};

class WoodBox: public Box {
public:
    WoodBox(int w, int l, int h) : Box(w, l, h) {}
};

int main(){
    WoodBox *b = new WoodBox(5, 10, 3);
    std::cout << "나무 상자의 크기 = " << b->Volume() << std::endl;
    delete b;
}
