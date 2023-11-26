#include <iostream>
#include <mutex>  // For std::unique_lock
#include <shared_mutex>
#include <thread>

#define MAX_THREADS 3

class ThreadSafeCounter {
public:
    ThreadSafeCounter() = default;

    unsigned int get() const {
        std::shared_lock lock(mutex);
        return value;
    }

    void increment() {
        std::unique_lock lock(mutex);
        value++;
    }

private:
    mutable std::shared_mutex mutex;
    unsigned int value = 0;
};

int main() {
    std::shared_mutex guard;
    ThreadSafeCounter counter;
    std::thread t[MAX_THREADS];

    auto increment_and_print = [&]() {
        for (int i = 0; i < 3; i++) {
            counter.increment();
            unsigned int c = counter.get();

            guard.lock(); 
            std::cout << std::this_thread::get_id() << ", " << c << std::endl; 
            guard.unlock(); 
        }
    };

    for (int i = 0; i < MAX_THREADS; ++i) {
        t[i] = std::thread(increment_and_print);
    }

    for (int i = 0; i < MAX_THREADS; ++i) {
        t[i].join();
    }
}
