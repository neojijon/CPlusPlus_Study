#include <iostream>
#include <fstream>
#include <string>

int MakeFile(const char *input, const char *output) {
    std::ifstream infile(input); 
    if (infile.fail()) { 
        std::cout << input << "파일을 열수 없습니다." << std::endl;
        return 1;
    }
    
    std::ofstream outfile(output); 
    if (outfile.fail()) { 
        std::cout << output << "파일을 열수 없습니다." << std::endl;
        return 1;
    }
    
    std::filebuf* inbuf  = infile.rdbuf();
    outfile << inbuf;

    infile.close();
    outfile.close();   
    return 0;
}

int main (int argc, char *argv[]){
    if (argc < 3) {
        std::cout << "파일명을 입력하시기 바랍니다." << std::endl;
        return 1;
    }
    
    if (MakeFile(argv[1], argv[2])) {
        std::cout << argv[1] << ", " << argv[2] << "파일 작업 시 에러가 발생하였습니다." << std::endl;
        return 1;
    }
    return 0;
}