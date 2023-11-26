#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

int main( ){
   time_t now = time(0);
   std::cout << "1970년 1월 1일 00:00:00 이후 진행된 시간 :" << now << std::endl;

   char* dt = ctime(&now);
   std::cout << "현재 시간 : " << dt << std::endl;

   tm *localtm = localtime(&now);
   std::cout << "현재 시간 : " << asctime(localtm)  << std::endl;
}