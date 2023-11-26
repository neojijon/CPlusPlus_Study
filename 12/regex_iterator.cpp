#include <stdio.h>
#include <string>
#include <regex>

int main() {
    std::string s = "1024 356 71589";
    std::regex number("[[:digit:]]+");

    std::sregex_iterator it(s.begin(), s.end(), number);
    std::sregex_iterator end;

    std::cout << std::distance(it, end) << " 단어" << std::endl;
			  
    while (it != end) {
        std::smatch m = *it++;
        printf("%s\n", m.str(0).c_str());
    }
    return 0;
}