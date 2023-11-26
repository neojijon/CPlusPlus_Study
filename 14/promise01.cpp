#include <iostream>
#include <future>
#include <thread>
#include <numeric>
#include <vector>
#include <functional>

void accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last,
                std::promise<int>&& accumulate_promise){
    int sum = std::accumulate(first, last, 0);
    accumulate_promise.set_value(sum);
}

std::future<int> launch_promise(std::vector<int>::iterator first,
                                std::vector<int>::iterator last) {
    std::promise<int> accumulate_promise;
    std::future<int> result = accumulate_promise.get_future();
    std::thread work_thread(accumulate, first, last, std::move(accumulate_promise));
    work_thread.detach();
    return result;
}

int main(){
    int total = 0;
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    std::future<int> s[2];
    s[0] = launch_promise(numbers.begin(), numbers.begin() + 6 );
    s[1] = launch_promise(numbers.begin() + 6, numbers.end() );

    for (int i = 0; i < 2; ++i) {
        int w = s[i].get();
        std::cout << "promise-" << i << " : " << w << std::endl;
        total += w; 
    }
    std::cout << "합계 : " << total << std::endl;
}