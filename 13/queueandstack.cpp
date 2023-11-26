#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue
#include <stack>          // std::stack

int main (){
  std::queue<int> myqueue;
  std::stack<int> mystack;
  std::priority_queue<int> mypq;
  int myint;
 
  myqueue.push (30);
  myqueue.push (50);
  myqueue.push (99);
  myqueue.push (100);
  myqueue.push (30);
  
  std::cout << "queue contains: ";
  while (!myqueue.empty()) {
    myint = myqueue.front();
    mypq.push(myint);
    mystack.push(myint);
    std::cout << ' ' << myint;
    myqueue.pop();
  }
  std::cout << std::endl;

  std::cout << "stack contains: ";
  while (!mystack.empty()){
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << std::endl;

  std::cout << "priority queue contains: ";
  while (!mypq.empty()){
     std::cout << ' ' << mypq.top();
     mypq.pop();
  }
  std::cout << std::endl;
  return 0;
}