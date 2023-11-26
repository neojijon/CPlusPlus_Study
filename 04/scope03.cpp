#include <iostream>

struct st {
    int i;
};

void fn (struct st, struct st f);
int n = 3;
int fint(st f,  int y = n); 

int a;
void f( int a, int b ); 

int main(){
    struct st s = { 0 }, b = {10};
    fn(s,b);
    fint(s, 100);
    fint(b);
}

void fn(struct st a, struct st b){
    std::cout << "st : " << a.i << ", st : " << b.i << "\n";
}

int fint(struct st f, int y){
    std::cout << "st : " << f.i << ", int : " << y << "\n";
}
