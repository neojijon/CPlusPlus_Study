#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <regex>

int main() {
    const std::string text = "안녕하세요! 이순신 장군입니다.";
    const std::regex ws_re("\\s+|\\.$");

    std::sregex_token_iterator begin(text.begin(), text.end(), ws_re, -1);
    std::sregex_token_iterator end;

    std::vector<std::string> vec{ begin, end };
    for (auto i : vec) std::cout << i << std::endl;
    std::cout << std::endl;

    const std::string html = R"(<p><a href="http://google.com">google</a> )"
        R"(< a HREF ="http://cppreference.com">cppreference</a>\n</p>)";
    
    const std::regex url_re(R"!!(<\s*A\s+[^>]*href\s*=\s*"([^"]*)")!!", std::regex::icase);
    std::sregex_token_iterator it(html.begin(), html.end(), url_re, 1);
    
    while (it != end) {
        std::sregex_token_iterator::value_type m = *it++;
        std::cout << m.str() << std::endl;
    }
    return 0;
}