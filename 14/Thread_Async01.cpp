#include <iostream>
#include <future>
#include <vector>

int accumulate_block_worker_ret(int* data, size_t count) {
    int result = 0;
    for (int i = 0; i < count; ++i)
        result += *(data + i);
    return result;
}
 
int main(){
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::future<int> fut = std::async(
        std::launch::async, accumulate_block_worker_ret, v.data(), v.size());

    std::cout << "배열의 합은 " << fut.get() << std::endl;
    return 0;
}