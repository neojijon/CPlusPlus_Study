#include <thread>
#include <atomic>

std::atomic<int> global;
#define MAX_THREADS 2

/* 스레드에서 호출되는 함수이다.   */
void function(int func, int loops) {
    for (int i = 0; i < loops; ++i) { 
        ++global;
        if ((i % 10) == 0) std::this_thread::yield();        
    }
    printf("%d. global = %d\n", func, global.load());
}

int main() {
    std::thread t[MAX_THREADS];
    global.store(0,std::memory_order_relaxed);  

    for (int i = 0; i < MAX_THREADS; ++i) {
         t[i] = std::thread(function, i, 10000);
    }
    
    for (int i = 0; i < MAX_THREADS; ++i) {
        t[i].join();
    }
  
    printf("global = %d\n", global.load());
}
