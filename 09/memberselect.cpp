#include <iostream> 

struct client{ int a; };

class proxy {
public:    
    proxy(client *ptr) : target(ptr) { }
        
    client *operator->() const { 
        return target; 
    }
private:
    client *target;    
};

int main() { 
    client x = { 3 };
    proxy y(&x);

    std::cout << x.a << ", " << y->a << std::endl;
    return 0; 
}
