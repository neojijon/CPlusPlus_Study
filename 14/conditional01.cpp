#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

std::mutex mtx;
std::condition_variable cv;
static int ranking = 1;

void print(int id) {
  std::unique_lock<std::mutex> umtx(mtx);
  cv.wait(umtx);
  std::cout << ranking++ << ". thread " << id << '\n';
}

int main (){
  std::thread threads[10];

  for (int i=0; i<10; ++i)
    threads[i] = std::thread(print, i);

  std::cout << "10개의 스레드가 레이스 경쟁을 펼친다.\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  {
      std::unique_lock<std::mutex> umtx(mtx);
      cv.notify_all();
  }

  for (auto& th : threads) th.join();
  return 0;
}