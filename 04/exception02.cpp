#include <stdexcept>
#include <iostream>

void CopyObject(const char *original) {
    if (nullptr == original) {
       throw  std::runtime_error("매개변수가 NULL이다.");
    }
    std::cout << original << std::endl;
}

int main() {
   char *name = nullptr; 
   try {
      CopyObject(name);
   } catch(std::runtime_error& e) {
      std::cerr << e.what() << std::endl;
   } catch(int e) {
      std::cerr << e << std::endl;
   } catch(...) { 
      std::cerr << "모든 exception 처리." << std::endl;
   }
   return 0;
}

