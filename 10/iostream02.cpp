#include <iostream>
#include <cstdlib>
 
class Distance {
private:
    int meters;       
    int centimeters;  

public:
    Distance(int f = 0, int i = 0) {
        SetDistance(f,i);
    }

    void SetDistance(int f = 0, int i = 0) {
        if (i >= 100) {
            centimeters = i % 100;
            meters = (i / 100) + f;
        } else {
            meters = f;
            centimeters = i;
        }    
    }
    int GetMeters() const {
        return meters;
    }    
    int GetCentiMeters() const {
        return centimeters;
    }    
};

int main(){
   char buffer[100];
   
   std::cout << "미터 : ";
   std::cin.getline(buffer, 100);
   int m = strtol(buffer,0,10);
   
   std::cout << "센티미터 : "; 
   std::cin.getline(buffer, 100);
   int cm = strtol(buffer,0,10);

   Distance d1(8, 10), d2(6, 11), d3(m,cm); 
   
   int size = sprintf(buffer, "첫 번째 시도 넓이 뛰기 거리 : %dm,\t%dcm\n", 
                      d1.GetMeters(), d1.GetCentiMeters());
   std::cout.write(buffer, size);

   size = sprintf(buffer, "두 번째 시도 넓이 뛰기 거리 : %dm,\t%dcm\n", 
                      d2.GetMeters(), d2.GetCentiMeters());
   std::cout.write(buffer, size);
   
   size = sprintf(buffer, "세 번째 시도 넓이 뛰기 거리 : %dm,\t%dcm\n", 
                      d3.GetMeters(), d3.GetCentiMeters());
   std::cout.write(buffer, size);
   return 0;
}