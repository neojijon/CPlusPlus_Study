#include <stdio.h>
#include <iostream>
#include <string>
#include "door.hpp"

int myGlobal = 0;

namespace mynamespace {
const int OPEN = 1;
const int CLOSE = 0;

void Door::Open() {
    State(OPEN);
}
 
void Door::Close(){
	State(CLOSE);
}

void Door::ShowState() const {
	printf("현재 문의 상태 : ");
	std::cout << ((state==OPEN)? "OPEN" : "CLOSE") << std::endl;	
}

void Door::SetName(std::string s){
    name = s;
}    
    
std::string Door::GetName() const{
    return name;
}    
}