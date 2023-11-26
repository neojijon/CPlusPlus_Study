#include <iostream>
#include <iomanip> 

int main (int argc, char *argv[] , char *const envp[] ) { 
    for (int i = 0; i < argc ; ++i)
        std::cout << i << " : " << argv[ i ] << '\n';
    
    while(*envp)
        std::cout << *envp++ << std::endl;    
	return 0;
}