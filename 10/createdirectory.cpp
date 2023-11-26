#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    fs::path p = fs::current_path();
    std::cout << "Current path is " << p << std::endl;
 
    std::filesystem::create_directories("hello");
    for (const fs::directory_entry& p : fs::directory_iterator(p)) {
        std::cout << p.path().generic_string();
        if (p.is_directory()) std::cout << " 디렉토리"; 
        else
        if (p.is_regular_file()) std::cout << " 파일";
        else std::cout << " 기타";
        std::cout << std::endl;
    }
    fs::remove("hello");
    //    std::filesystem::path dir = std::filesystem::temp_directory_path();
    return 0;
}
