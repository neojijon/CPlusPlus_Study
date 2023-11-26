#include <iostream>
#include <string>

struct Person {
public:
    Person(std::string n) : name(n){}

    std::string& GetName() {
        return name;
    }

private:
    std::string name;
};

class Student : public Person {
public:
    Student(std::string n, std::string i) : Person(n), id(i) {}

    std::string& GetID() {
        return id;
    }

private:
    std::string id;
};

int main() {
    Student s1("홍길동", "16-31-001");
    std::cout << "이름 : " << s1.GetName() << ", 학번 : " << s1.GetID() << std::endl;
    return 0;
}
