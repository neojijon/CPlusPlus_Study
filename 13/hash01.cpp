#include <iostream>
#include <functional>
#include <string>
#include <vector>

int main(){
    std::vector<std::string> names = {"토마토", "전구", "짜장면"};
    std::size_t str_hash;
    std::hash<std::string> hash;
    for(auto& s: names) {
        str_hash = hash(s);
        std::cout << "hash(\'" << s.data() << "\') = " << str_hash << '\n';
    }    
}