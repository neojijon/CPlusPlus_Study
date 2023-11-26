#include <string>
#include <algorithm>
#include <iostream>
#include "Array.hpp"    // Array
 
template<typename Container>
bool quote(Container& cont, const std::string& s){
    return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
}

bool mypredicate (int i, int j) {
    return (i == j);
}
 
int main(){
    std::string str = "이제까지 배운 방법 가운데 데이터를 그룹으로 묶어 관리하는 방법으로 배열이 있었다.";
    std::cout << std::boolalpha << quote(str, "배열") << '\n'
                                << quote(str, "벡터")  << '\n';
 
    Array<char> vec(str.begin(), str.end());
    std::cout << quote(vec, "배열") << '\n'
              << quote(vec, "벡터")  << '\n';
                                
    Array<int> stack;
    // stack: 10 20 30 40 50 60 70 80 90
    for (int i = 1; i < 10; ++i) stack.push_back(i*10);

    int needle2[] = {50,60,70};
 
    Array<int>::iterator it = 
                       std::search (stack.begin(), stack.end(), needle2, needle2+3, mypredicate);

    if (it != stack.end())
        std::cout << "{50,60,70}의 시작 위치 " << (it - stack.begin()) << '\n';
    else
        std::cout << "찾을 수 없습니다.\n";    
}