#include <iostream>
 
class Distance {
private:
    int meters;             // 0 to infinite
    int centimeters;        // 0 to 100

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
    
    friend std::ostream &operator<<( std::ostream &output, const Distance &d ) { 
        output << d.meters << "m " << ",\t" << d.centimeters<< "cm";
        return output;            
    }

    friend std::istream &operator>>( std::istream  &input, Distance &d ) { 
        int m, cm; 
        std::cout << "미터 : ";
        input >> m;
        std::cout << "센티미터 : "; 
        input >> cm;
        d.SetDistance(m, cm);
        return input;            
    }
};

int main(){
   Distance d1(8, 10), d2(6, 11), d3;

   std::cin >> d3;
   std::cout << "첫 번째 시도 넓이 뛰기 거리 : " << d1 << std::endl;
   std::cout << "두 번째 시도 넓이 뛰기 거리 : " << d2 << std::endl;
   std::cout << "세 번째 시도 넓이 뛰기 거리 : " << d3 << std::endl;
   return 0;
}