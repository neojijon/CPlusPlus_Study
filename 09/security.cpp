#include <iostream> 

class Person {
public:
    Person(const char* n, int a) {
      name = n; 
      age = a;
    }

    bool Compare(Person& p) {
      if (this->age < p.age) return false;
        return true;
    }

    const char *GetName() {
        return name.c_str();
    }    
private:
    std::string name;
    int age;
};

int main() { 
    Person hong("홍길동", 23);
    Person lee("이순신", 53);
    
    if (hong.Compare(lee)) {
        std::cout << hong.GetName() << "의 나이가 " 
                  << lee.GetName() << "보다 많다." << std::endl;
    } else {
        std::cout << lee.GetName() << "의 나이가 " 
                  << hong.GetName() << "보다 많다." << std::endl;   
    }
    return 0; 
}
