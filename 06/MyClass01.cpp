#include <iostream>

class MyClass {
  public:
    MyClass(int i, int j) {
       x = i;
       y = j;
    }

    void ShowXY() {
      std::cout << "The field values are " << x << " & " << y << std::endl; 
    }

  private:
    int x;
    int y;
};

int main() {
        MyClass ms1(10, 20);
        MyClass ms2(30, 50);
        ms1.ShowXY();
        ms2.ShowXY();
}
