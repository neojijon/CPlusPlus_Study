#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string target = "Hello C++ World!";
    std::smatch m;
    std::regex pattern("World");

    std::cout << "대상 문자열 : " << target << std::endl;

    if (std::regex_search(target, m, pattern)) {
        for (auto x : m) std::cout << x << " ";
        std::cout << std::endl;
    }
    return 0;
}