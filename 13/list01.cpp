#include <iostream>
#include <list>
#include <iomanip>

const size_t MAXWIDTH = 80;
typedef  std::pair <std::string, int> Boxing;

void print(const char *str, std::list<Boxing>& myList){
    std::cout << std::left << std::setw(MAXWIDTH) << std::setfill('-') 
              << str << std::endl;    
    for( auto& item : myList )
        std::cout << '(' << item.first << " : " << item.second << ')' << ' ';
    std::cout << std::endl;
}

int main(){
 {   
    std::list< Boxing > myList;

    myList.push_front( std::make_pair(std::string("토마토"), 800));
    myList.push_back( std::make_pair(std::string("전구"), 2000));

    Boxing b = std::make_pair(std::string("신발"), 25000);
    myList.insert( myList.begin(), b );
    myList.insert( myList.begin(), b );

    myList.emplace( myList.begin(), "사과", 500 );
    
    // template <class... Args> void emplace_front (Args&&... args);
    myList.emplace_front( "짜장면", 5000 );
    myList.emplace_front( "해물짬뽕", 7000 );
    print("첫 번째 myList : ", myList);

    // 정렬은 올림차순으로 한다.
    auto s = [] (Boxing& b1, Boxing& b2) -> bool { 
                 if (b1.second == b2.second)
                      return b1.first < b2.first;
                 else return b1.second < b2.second; };
             
    myList.sort(s);
    print("Sort후 myList : ", myList);
    
    auto u = [] (Boxing& b1, Boxing& b2) -> bool { 
                 return b1.first == b2.first && b1.second == b2.second; 
             };
    myList.unique(u);
    print("unique로 중복 삭제후 myList : ", myList);

    myList.pop_front();
    myList.erase( myList.begin() );
    print("pop_front와 erase 함수로 삭제후 myList : ", myList);
  }
  return 0;
}

