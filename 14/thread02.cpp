#include <iostream>
#include <chrono>
#include <thread>
   
void independentThread() {
    std::cout << "independentThread()\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "종료 independentThread()\n";
}
 
void Caller() {
    std::cout << "caller()함수 호출.\n";
    std::thread thread(independentThread);
    thread.detach();
//    thread.join();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    if( thread.joinable()){ 
        thread.join();
    }
    std::cout << "caller()함수 종료.\n";
}

int main() {
    std::thread(Caller).detach();
    std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();
    std::chrono::seconds dura_sec(3);
    std::this_thread::sleep_until( StartTime + dura_sec ); 

    std::cout << "메인 스레드 종료...\n";
}