#include <iostream>
#include <string>
#include <regex>
#include <iterator>

int main() {
    std::string s = "Hello World!";
    std::cout << std::regex_replace(s, std::regex("[eo]"), "0") << std::endl;

    s = "there is a subsequence in the string\n";
    std::regex e("\\b(sub)([^ ]*)");
    std::smatch m;

    while (std::regex_search(s, m, e)) {
         std::cout << "prefix : " << m.prefix() << std::endl;
         std::cout << m[1].str() << '-';
         std::cout << m[2].str() << std::endl;
         std::cout << "suffix : " << m.suffix() << std::endl;
         s = m.suffix().str();
    }
    
    s = "there is a subsequence in the string\n";
    std::cout << std::regex_replace(s, e, "$1-$2");
    std::cout << std::regex_replace(s, e, "$1 and $2", std::regex_constants::format_no_copy);
    std::cout << std::endl;
    return 0;
}
