#include <cstring> 
#include <cstdlib> 
#include <iostream>

main() {
   const char *cc = "문자열을 입력합니다. This is a string";
   char cb[100];
   char  *str; 

   memcpy(cb, cc, 38); // strcpy(cb, cc); 
   
   str = (char *) malloc(strlen(cc) + 1); 
   strcpy(str,cc);
 
   std::cout << "cc = " << cc << "   문자열의 크기는 " << strlen(cc) << std::endl;
   std::cout << "cb = " << cb  << ", 문자열의 크기는 " << strlen(cb) << std::endl;
   std::cout << "str= " << str << ", 문자열의 크기는 " << strlen(str) << std::endl;
   free(str);
}
