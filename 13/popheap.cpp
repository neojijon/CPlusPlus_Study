#include <iostream>
#include <algorithm>
#include <queue>          // std::queue, std::priority_queue
#include <vector>
 
int main(){
    std::vector<int> myqueue { 100, 36, 19, 25, 1, 2, 17, 3, 7};
    std::priority_queue<int> mypq;
 
    std::cout << "초기 입력값 : " << std::endl;
    for (auto i : myqueue) {
        std::cout << i << ' ';
        mypq.push(i);    
    }    
    std::cout << std::endl;

    std::cout << "힙 " << std::setfill('-') << std::setw(20) << '-' << std::endl; 
    std::make_heap(myqueue.begin(), myqueue.end());
    while (!myqueue.empty()){
        for (auto i : myqueue) std::cout << i << ' ';
        std::cout << std::endl;  
        std::pop_heap(myqueue.begin(), myqueue.end());
        myqueue.pop_back();
    }
    
    std::cout << "priority queue contains: ";
    while (!mypq.empty()){
       std::cout << ' ' << mypq.top();
       mypq.pop();// priority_queue객체에서 데이터를 삭제시킨다.
    }
    std::cout << std::endl;
}