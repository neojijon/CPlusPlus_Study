#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

std::condition_variable cv;
std::mutex cv_m;
int i = 5;
bool done = false;

void waits(){
    std::unique_lock<std::mutex> lk(cv_m);
    std::cout << "Waiting... \n";

    cv.wait(lk, [] {return i == 0; });
    std::cout << "...finished waiting. i == 0\n";
    done = true;
}

void signals(){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Notifying falsely...\n";
    cv.notify_one(); 

    std::unique_lock<std::mutex> lk(cv_m);
    while (!done){
        std::cout << i << ". Notifying true change...\n";
        lk.unlock();
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        lk.lock();
        if (i--) continue;
    }
}

int main(){
    std::thread t1(waits), t2(signals);
    t1.join();
    t2.join();
}