#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>

struct cmp_str {
   bool operator()(const char *a, const char *b) {
      return std::strcmp(a, b) < 0;
   }
};

int main (){
    std::map<int, std::string> Employees; 

    Employees[1923] = "신사임당";
    Employees[5328] = "홍길동";

    Employees.insert(std::pair<int, const char *>(1924, "김홍도"));
    Employees.insert(std::map<int, const char *>::value_type(7587, "김유신"));
 
    Employees.insert(std::make_pair(5428, (char *)"이순신"));

    std::cout << "Employees[3374]=" << Employees[3374] << std::endl;
    std::cout << "Map size: " << Employees.size() << std::endl;

    // multimap은 키가 유일(unique)하지 않더라도 입력이 가능하다.
    typedef std::unordered_multimap<std::string, int> MapType;
    MapType m;
    
    for( std::map<int, std::string>::iterator i = Employees.begin(); i != Employees.end(); ++i){
       std::cout << " [" << i->first << ": " << i->second << "] ";
       if (!i->second.empty())
           m.insert(std::make_pair((*i).second, (*i).first));
    }
    std::cout << std::endl;

    m.emplace("홍길동", 9324); 
    m.emplace(std::make_pair("홍길동", 0001)); 
     
    std::cout << " m의 요소 : " << std::endl;
    for (MapType::iterator it = m.begin(); it != m.end();  ++it) {
       std::cout << " [" << (*it).first << ", " << (*it).second << "] ";
    }
    std::cout << std::endl;
    
    std::string s = "홍길동"; 
    std::cout << "홍길동 : " << m.count(s);
    std::pair<MapType::iterator, MapType::iterator> ppp = m.equal_range(s);

    std::cout << ", Range of \"" << s << "\" elements:" << std::endl;
    for (MapType::iterator it2 = ppp.first; it2 != ppp.second; ++it2) {
        std::cout << " [" << (*it2).first << ", " << (*it2).second << "] ";
    }
    std::cout << std::endl;

    m.clear();
    return 0;
}