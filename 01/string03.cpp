#include <iostream>
#include <string>

main() {
  std::string s0 ("Initial string");
  std::string s1;
  std::string s2 (s0);
  std::string s3 (s0, 8, 3);
  std::string s4 (s0, 6);
  std::string s5 (10, 'x');

  std::cout << "s1 : " << s1 << std::endl;
  std::cout << "s2 : " << s2 << std::endl; 
  std::cout << "s3 : " << s3 << std::endl;
  std::cout << "s4 : " << s4 << std::endl;
  std::cout << "s5 : " << s5 << std::endl;
  return 0;
}
