#include <thread>
#include <iostream>

thread_local int local;
int global; 
#define MAX_THREADS 2

void function(int func, int loops) {
    local = global;
    for (int i = 0; i < loops; ++i) { 
        ++local; 
        if ((i % 10) == 0) std::this_thread::yield();        
    }
    
    global += local;
    printf("%d. global = %d\n", func, global);
}

int main() {
    std::thread t[MAX_THREADS];
    global = 0;  
    for (int i = 0; i < MAX_THREADS; ++i) {
         t[i] = std::thread(function, i, 10000);
    }
    
    for (int i = 0; i < MAX_THREADS; ++i) {
        t[i].join();
    }
  
    printf("global = %d\n", global);
}
