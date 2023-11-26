#include <iostream> 

struct Something {
    static int s_value;
    static int getSValue() { return s_value; }

    int value;
    int getValue() { return value; }
};
 
int Something::s_value = 1;
 
int main(){
    std::cout << Something::getSValue() << std::endl;
    
    Something s = {100};
    std::cout << s.getSValue() << " , " << s.getValue() << std::endl;
}