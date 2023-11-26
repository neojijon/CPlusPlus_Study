#include <thread>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>

void accumulate_block_worker(int* data, size_t count, int* result) {
    for (int i = 0; i < count; ++i)
        *result += *(data + i);
}

int main(){
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result = 0;
    std::thread worker(accumulate_block_worker,
                     v.data(), v.size(), &result);
    worker.join();
    std::cout << "배열의 합은 " << result << std::endl;
    return 0;
}