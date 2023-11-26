#include <iostream>
#include <string>
#include "door.hpp"

int main(){
	mynamespace::Door d;
	
	d.Open();
	d.ShowState();

	myGlobal = 1;
	std::cout << myGlobal << std::endl;
	return 0;
}