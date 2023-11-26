#include <iostream>
#include <numeric>
#include <vector>
#include <future>

int accumulate_block_worker(int* data, size_t count) {
    return std::accumulate(data, data + count, 0);
}

using int_futures = std::vector<std::future<int>>;

int_futures launch_split_workers(std::vector<int>& v) {
    int_futures futures;
    futures.push_back(std::async(std::launch::async, accumulate_block_worker,
                               v.data(), v.size() / 2));
    futures.push_back(std::async(std::launch::async, accumulate_block_worker,
                               v.data() + v.size() / 2, v.size() / 2));
    return futures;
}

int main(){
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int_futures futures = launch_split_workers(v);
    
    int result0 = futures[0].get();
    int result1 = futures[1].get();
    std::cout << "각각 배열의 합은 " << result0 << " 과 " << result1 << std::endl;
    std::cout << "두개 배열의 합은 " << result0 + result1 << std::endl;
    return 0;
}