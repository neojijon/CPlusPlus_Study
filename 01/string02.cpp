#include <iostream>
#include <string>

main() {
   const char *cc = "���ڿ��� �Է��մϴ�. This is a string";
   std::string str = "";   // ���ڿ� �������̴�.
 
   str = cc;
   std::cout << "str= " << str << ", ���ڿ��� ũ��� " << str.length() << std::endl;
   
   str = "Ŭ���� ���ο��� ������ ��´�.";
   str += " ���� ���� �޸� ������ ���� �ʾƵ� ����� �����ϴ�.";
   std::cout << "str= " << str << ", ���ڿ��� ũ��� " << str.length() << std::endl;
}
