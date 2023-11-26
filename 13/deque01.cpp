#include <iostream>
#include <algorithm>    // std::find
#include <deque>       // std::deque
#include <cstdlib>
 
int main(){
    std::deque<int> que = {7, 5, 16, 8};
    {// 초기화를 수행한다는 의미로 중괄호를 사용한다.
        que.emplace_back(1);  
        que.emplace_back(2);
    }

    std::cout << "deque  size = " << que.size() << " : ";
    for(size_t i = 0; i < que.size(); ++i){
      std::cout << que[i] << ' ';
    }
    std::cout << std::endl;
    
    int *variable = &que[3]; // 4 번째 요소의 위치 포인터를 반환한다.
    std::cout << "variable = " << *variable << std::endl;
    *variable = 156;
    
    // deque 추가
    for(int i = 3; i < 8; ++i)
        que.push_back(i * i);
 
    std::cout << "확장된 quetor size = " << que.size() << " : ";

    std::deque<int>::iterator v = que.begin();
    while( v != que.end()) {
        std::cout << *(v++) << " ";
    }
    std::cout << std::endl;
   
    std::cout << "삭제 예정인 que[2] = " << que[2] << std::endl; 
    que.erase(que.begin() + 2);

    std::deque<int>::iterator it = std::find(que.begin(), que.end(), 5);
    if(it != que.end()) {
        std::cout << "발견한 숫자의 삭제 = " << *it << std::endl; 
        it = que.erase(it);
    }

//     std::cout << "발견한 숫자의 삭제 = " << *it << std::endl; 
    it = que.insert(it, 200); // 중간에 새로운 데이터를 입력한다.
    it = que.insert(it,2,300); 
    it = que.emplace(que.end(), 234); 
     
    int size = que.size();
	int *arr = new int[size];
    if (arr) {
        std::copy(que.begin(), que.end(), arr);
        std::cout << "array size = " << size << " : ";
        for (int i = 0; i < size; ++i)
            std::cout << arr[i] << ' ';
        std::cout << std::endl;
    } else {
        std::cout << "메모리 할당받지 못했습니다." << std::endl;
    }
    return 0;
}