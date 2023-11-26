#include <iostream>

int func(int n ){
    { 
        if (2 == n) 
           goto label;
        ++n;
        {
        label:
            int n = 20; 
            ++n; 
            std::cout << "내부 n : " << n << std::endl;
        } 
    } 

    int a = n; 
    std::cout << "외부 n : " << n << std::endl;
    return a;
}

int main(){
    int a = 0;
    ++a;
    int x = func(a);
    std::cout << "a : " << a << ", x : " << x << std::endl;
}
