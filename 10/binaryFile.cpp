#include<iostream>
#include<fstream>

int main (int argc, char *argv[]){
    if (argc < 3) {
        std::cout << "파일명을 입력하시기 바랍니다." << std::endl;
        return 1;
    }
    
    std::ifstream input;
    input.open(argv[1], std::ios::binary | std::ios::in);

    std::ofstream output;
    output.open(argv[2],std::ios::binary | std::ios::out);

    input.seekg (0, input.end);
    int length = input.tellg();
    input.seekg (0, input.beg);
  
    char * buffer = new char [length];
    input.read (buffer, length);
    output.write(buffer, length);
    delete buffer;
    
    if (input.good())
          std::cout << "파일의 전체 크기 : " << length << std::endl;
    else {
          std::cout << "파일의 전체 크기 : " << length 
                    << ", error: only " << input.gcount() << "만 읽음." << std::endl;
    }       
 
    input.close();
    output.close();
  return 0;
}