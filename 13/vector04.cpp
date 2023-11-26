#include <iostream>
#include <vector>
#include <deque>

typedef  std::pair <std::string, int> Boxing;

int main(){   
    std::vector<Boxing> myVector;

    myVector.push_back( std::make_pair(std::string("토마토"), 800));
    myVector.emplace( myVector.begin(), "사과", 1000 );
    myVector.emplace_back( "빠나나", 3000 );
    std::deque<Boxing> myDeque;
    while(!myVector.empty()) {
        myDeque.push_back(myVector.back());
        myVector.pop_back();
    }
    std::cout << "myVector의 데이터 : ";
    for( auto& item : myVector )
        std::cout << '(' << item.first << " : " << item.second << ')' << ' ';
    std::cout << std::endl;
    std::cout << "myDeque의 데이터 : ";
    for( auto& item : myDeque )
        std::cout << '(' << item.first << " : " << item.second << ')' << ' ';
    std::cout << std::endl;
}

