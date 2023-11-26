#include <thread>
#include <iostream>
#include <mutex>
#include <atomic>

std::mutex mtx_lock;
int global = 0; 
#define MAX_THREADS 2
void function(int func, int loops) {
   for (int i = 0; i < loops; ++i) { 
        mtx_lock.lock();
        ++global; 
         mtx_lock.unlock();
        if ((i % 10) == 0) std::this_thread::yield();     
    }
    printf("%d. global = %d\n", func, global);
}

int main() {
    std::thread t[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; ++i) {
         t[i] = std::thread(function, i, 10000);
    }
    
    for (int i = 0; i < MAX_THREADS; ++i) {
        t[i].join();
    }
  
    printf("global = %d\n", global);
}
