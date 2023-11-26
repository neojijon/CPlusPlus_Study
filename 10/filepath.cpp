#define  _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>

using path=std::filesystem::path;

int main(int argc, char* argv[]) {
    path filePath("D:/Sources/C++/Chapter01/HelloWorld/output.txt");
    
    int i = 0;
    std::cout << "파일 경로 : " << filePath << std::endl;
    for (path::iterator itr = filePath.begin(); itr != filePath.end(); ++itr){
        std::cout << "path 부분 : " << i++ << " = " << *itr << std::endl;
    }

    std::cout << "root_name() = " << filePath.root_name() << std::endl
        << "root_path() = " << filePath.root_path() << std::endl
        << "relative_path() = " << filePath.relative_path() << std::endl
        << "parent_path() = " << filePath.parent_path() << std::endl
        << "filename() = " << filePath.filename() << std::endl
        << "stem() = " << filePath.stem() << std::endl
        << "extension() = " << filePath.extension() << std::endl;

    if (std::filesystem::exists(filePath)&& 
        std::filesystem::is_regular_file(filePath)) {
        std::cout << "파일을 읽고 화면에 파일의 내용을 출력한 결과.........." << std::endl;
        std::ifstream readFile;
        std::string line;
        readFile.open(filePath);
        while (readFile.good()) {
            getline(readFile, line);
            std::cout << line << std::endl;
        }
        readFile.close();
    } 
    return 0;
}
