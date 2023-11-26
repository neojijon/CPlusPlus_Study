#include <iostream>
#include <vector>

int i = 0;

void ParamCheck (int& s) {
    std::cout << ++i << ". " << s << " 인수는 'int&' 타입이다.\n";
}

void ParamCheck (const int& s) {
    std::cout << ++i << ". " << s << " 인수는 'const int&' 타입이다.\n";
}

void ParamCheck (int&& s) {
    std::cout << ++i  << ". " << s <<" 인수는 'int&&' 타입이다.\n";    
}

int main() {
    int s =10;
    ParamCheck(s);
    const int& cs = s;
    ParamCheck(cs);
    ParamCheck(static_cast<int &&>(s));
    ParamCheck((int&&) 100);
}
