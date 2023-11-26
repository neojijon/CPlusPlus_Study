#include <iostream>
#include <vector>

int main() {
    std::vector<int> myvector( 5 );
    int* p = myvector.data();

    *p = 10;
    for (int i = 1; i < myvector.size(); ++i)
        p[i] = p[i- 1] * i;
    *(++p) += 20;

    std::cout << "myvector의 데이터 : ";
    for (int i = 0; i < myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl;

    std::vector<std::string> mystring( 5 );
    std::string* s = mystring.data();

    *s = "Hello World";
    *(s + 1) = "개와 사람";
    *(s + 2) = "늑대와 사람";
    *(s + 3) = "늑대와 개";
    *(s + 4) = "사람과 사람";
    
    std::cout << "mystring의 데이터 : ";
    for (auto& a : mystring)
        std::cout << a.c_str() << ", ";
    std::cout << std::endl;

    return 0;
}
