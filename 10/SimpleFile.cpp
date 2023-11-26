#include <iostream>
#include <fstream>
#include <string>
#include <locale>

int MakeFile(const char *input, const char *output) {
    std::ifstream input_file(input); 
    if (!input_file.is_open()) { 
        std::cout << input << "파일을 열수 없습니다." << std::endl;
        return 1;
    }
    
    std::ofstream output_file(output); 
    if (!output_file.is_open()) { 
        std::cout << output << "파일을 열수 없습니다." << std::endl;
        return 1;
    }
    
    char data[100];
    while ( input_file.getline(data, 100) ) {
        output_file << data << std::endl;
    }
 
    input_file.close();
    output_file.close();
    return 0;
}

int ReadFile(const char *input) {
    std::ifstream input_file(input);
    if (!input_file.is_open()) {
        std::cout << input << "파일을 열수 없습니다." << std::endl;
        return 1;
    }
    
    std::string data;
//    while ( std::getline (input_file, data) ) 
//        std::cout << data.c_str() << std::endl; 
    
    char c;
    while (input_file.get(c))
       std::cout << c;
   
    input_file.close();       
    return 0;
}
    
int main (int argc, char *argv[]){
    if (argc < 2) {
        std::cout << "파일명을 입력하시기 바랍니다." << std::endl;
        return 1;
    }
    
    const char *file = "output.txt";
    if (MakeFile(argv[1], file)) {
        std::cout << argv[1] << "파일 작업 시 에러가 발생하였습니다." << std::endl;
        return 1;
    }
    
    if (ReadFile(file)) {
        std::cout << file << " 파일 작업 시 에러가 발생하였습니다." << std::endl;
        return 1;
    }    
    
    return 0;
}