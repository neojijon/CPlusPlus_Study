#include <iostream>
#include <string>
#include <regex>

int main(){
    std::string s("this subject has a submarine as a subsequence");
    std::smatch m;
    std::regex e(R"(\b(sub)([^ ]*))"); // e("\\b(sub)([^ ]*)");

    std::cout << "Target sequence: " << s << std::endl;
  
    while (std::regex_search(s, m, e)) {
        std::cout << m.str(0).c_str() << std::endl;
        for (auto x : m) std::cout << x << " ";
        std::cout << std::endl;
        s = m.suffix().str();
        std::cout << s.c_str() << std::endl;
    }
    return 0;
}