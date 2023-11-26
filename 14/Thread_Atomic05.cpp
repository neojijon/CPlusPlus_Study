#include <thread>
#include <atomic>
#include <cassert>
#include <string>
#include <iostream>

std::atomic<std::string*> ptr;
int data;
 
void producer(){
    std::string* p  = new std::string("Hello");
    data = 42;
    std::atomic_store_explicit(&ptr, p, std::memory_order_release);
}
 
void consumer(){
    std::string* p2 = nullptr;
    while (!(p2 = std::atomic_load_explicit(&ptr, std::memory_order_acquire))) {
        std::this_thread::yield(); 
    };
    std::cout << *p2 << std::endl;
    assert(*p2 == "Hello"); 
    assert(data == 42); 
}
 
int main(){
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join(); 
    t2.join();
}