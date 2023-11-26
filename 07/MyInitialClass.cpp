#include <iostream>
#include <initializer_list>

struct MyClass {
	MyClass(int, int);
	MyClass(std::initializer_list<int>);
private:
	int size;
	int *mem;
};

int main() {
	MyClass bar(10, 20);  // MyClass (int,int) 생성자가 호출된다.
	MyClass foo{ 10, 20 };  // MyClass (initializer_list<int>) 생성자를 호출한다.
}

MyClass::MyClass(int a, int b) {
	size = 2;
	mem = new int[2]();
	mem[0] = a;
	mem[1] = b;
	std::cout << "MyClass(int, int) :" << mem[0] << ' ' << mem[1] << std::endl;
}

MyClass::MyClass(std::initializer_list<int> a) {
	size = a.size();
	std::cout << "MyClass(std::initializer_list<int>) : ";
	mem = new int[size]();
	for (int i = 0; i < size; ++i) {
		mem[i] = *(a.begin() + i);
		std::cout << mem[i] << ' ';
	}
	std::cout << std::endl;
}
