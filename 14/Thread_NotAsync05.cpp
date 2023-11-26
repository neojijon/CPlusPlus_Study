#include <thread>
#include <iostream>
#include <chrono>
#include <numeric>
#include <vector>

void accumulate_block_worker(int* data, size_t count, int* result) {
    *result = std::accumulate(data, data + count, 0);
}

std::vector<std::thread> launch_workers(std::vector<int>& v,
                                     std::vector<int>* results) {
    std::vector<std::thread> threads;
       size_t length = v.size() / 2;
    threads.emplace_back(accumulate_block_worker, v.data(),          length, &((*results)[0]));
    threads.emplace_back(accumulate_block_worker, v.data() + length, length, &((*results)[1]));
    return threads;
}

int main(){
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int> results(2, 0);
    std::vector<std::thread> threads = launch_workers(v, &results);
    for (auto& t : threads) {
        t.join();
    }
    std::cout << "각 각 배열의 합은 " << results[0] << " 과 " << results[1] << std::endl;
    std::cout << "두 개 배열의 합은 " << results[0] + results[1] << std::endl;
    return 0;
}