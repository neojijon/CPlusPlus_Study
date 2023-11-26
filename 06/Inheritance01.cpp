#include <iostream>
#include <string>

class Person {
public:
    Person(std::string n) : name(n){}

    std::string GetName() {
        return name;
    }

private:
    std::string name;
};

class Student {
public:
    Student(std::string i, std::string n) : id(i) {
        person = new Person(n);
    }

    ~Student() {
        delete person;
    }
    std::string GetID() {
        return id;
    } 
    
    Person *person;
private:
    std::string id;
};

class Professor {
public:
    Professor(std::string i, std::string n) : id(i) {
        person = new Person(n);
    }

    ~Professor() {
        delete person;
    }
    std::string GetID() {
        return id;
    } 
    
    Person *person;
private:
    std::string id;
};

int main() {
    Student s1("16-31-001", "홍길동" );
    std::cout << "학생 ID : " << s1.GetID() 
              << ", 이름 : " <<  s1.person->GetName() << std::endl;
    return 0;
}

