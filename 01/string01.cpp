#include <cstring> 
#include <cstdlib> 
#include <iostream>

main() {
   const char *cc = "���ڿ��� �Է��մϴ�. This is a string";
   char cb[100];
   char  *str; 

   memcpy(cb, cc, 38); // strcpy(cb, cc); 
   
   str = (char *) malloc(strlen(cc) + 1); 
   strcpy(str,cc);
 
   std::cout << "cc = " << cc << "   ���ڿ��� ũ��� " << strlen(cc) << std::endl;
   std::cout << "cb = " << cb  << ", ���ڿ��� ũ��� " << strlen(cb) << std::endl;
   std::cout << "str= " << str << ", ���ڿ��� ũ��� " << strlen(str) << std::endl;
   free(str);
}
