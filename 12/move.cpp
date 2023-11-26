#include <iostream>
#include <vector>
#include <string>
#include <iterator>
 
int main() {
    std::vector<int> myArr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; 
    std::vector<int> nums{3, 4, 2, 8, 15 };
    std::move(myArr.begin(), myArr.end(), std::back_inserter(nums));

    std::cout << "기본 타입의 데이터는 복사된다.\n";
    for (int i : myArr) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    for (int i : nums) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::string sArr[] = {"공기", "물", "불", "흙"};
    std::vector<std::string> foo = {"air","water","fire","earth"};
    std::vector<std::string> bar(4);

    // moving ranges:
    std::cout << "\n배열이라 하더라도 객체의 교환은 가능하다.\n";
    std::move ( foo.begin(), foo.end(), sArr );

    std::cout << "sArr의 요소 :";
    for (std::string& x : sArr)std::cout << " [" << x << "]";
    std::cout << std::endl;
    std::cout << " foo의 요소 :";
    for (std::string& x: foo) std::cout << " [" << x << "]";
    std::cout << std::endl;
    
    std::move ( sArr, sArr+4, bar.begin() );    
    std::move ( foo.begin(), foo.end(), std::back_inserter(bar));

    std::cout << "bar의 크기는 " << bar.size() << "이다.";
    for (std::string& x: bar) std::cout << " [" << x << "]";
    std::cout << std::endl;

    std::cout << "sArr의 요소 :";
    for (std::string& x : sArr)std::cout << " [" << x << "]";
    std::cout << std::endl;
    std::cout << " foo의 요소 :";
    for (std::string& x: foo) std::cout << " [" << x << "]";
    std::cout << std::endl;
    
    // moving container:
    std::cout << "\n컨테이너 이동...\n";
    foo = std::move (bar);

   std::cout << "foo의 크기는 " << foo.size() << "이다.";
    for (std::string& x: foo) std::cout << " [" << x << "]";
    std::cout << std::endl;

    std::cout << "bar의 크기는 " << bar.size() << "이다.";
    for (std::string& x: bar) std::cout << " [" << x << "]";
    std::cout << std::endl;
}