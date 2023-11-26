#include <iostream>
#include <cstring>

class MyClass {
  public:
    MyClass(const char *label, int id) : label(label), id(id) { }
    MyClass() = default;
    
    void DisplayX() {
        std::cout << "클래스 내 label은 " << label << "이고 id는 " << id << "이다.\n";
    }

private:
    std::string label;
    const int id = 3;
};

int main() {
    MyClass s;
    s.DisplayX();
    
    MyClass x("인사성이 밝다.", 33);
    x.DisplayX();
}
