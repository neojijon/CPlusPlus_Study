#include <iostream>
#include <vector>       // std::pmr::vector
 
int main(){
    std::pmr::vector<int> first;
    std::pmr::vector<int> second (4,100); 
    std::pmr::vector<int> third (second.begin(),second.end()); 
    std::pmr::vector<int> fourth (third);
   
    fourth.reserve(100);    
    fourth.resize(10);
    printf("벡터의 크기를 %d으로 재조정한다.\n", fourth.capacity());
    std::cout << "fourth 벡터의 요소 수 : " << fourth.size() << std::endl;
    std::cout << "fourth 벡터의 요소 : ";
    for(auto& i : fourth)
       std::cout << i << ' ';
    std::cout <<std::endl;

    fourth.clear();
    printf("clear()함수 호출후 크기는 %d이다.\n", fourth.capacity());
    
    fourth.shrink_to_fit();
    printf("shrink_to_fit() 함수 호출후 크기는 %d이다.\n", fourth.capacity());
    return 0;
}