#include <string>
#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    std::filesystem::path p = std::filesystem::current_path();
    std::cout << "Current path is " << p << std::endl;
    std::filesystem::create_directories("hello");

    std::filesystem::current_path("hello");
    p = std::filesystem::current_path();
    std::cout << "Current path is " << p << std::endl;
    return 0;
}
