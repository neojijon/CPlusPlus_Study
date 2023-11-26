#include <thread>
#include <iostream>
#include <atomic>

// std::atomic<int> global = ATOMIC_VAR_INIT(0);
std::atomic<int> global;
#define MAX_THREADS 2

void function(int func, int loops) {
    for (int i = 0; i < loops; ++i) { 
        atomic_fetch_add(&global, 1);
        if ((i % 10) == 0) std::this_thread::yield();        
    }
    
    printf("%d. global = %d\n", func, atomic_load(&global));
}

int main() {
    std::thread t[MAX_THREADS];
    atomic_store(&global,0);  
    for (int i = 0; i < MAX_THREADS; ++i) {
         t[i] = std::thread(function, i, 10000);
    }
    
    for (int i = 0; i < MAX_THREADS; ++i) {
        t[i].join();
    }
  
    printf("global = %d\n", atomic_load(&global));
}
