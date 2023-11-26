#include <string>
#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <iterator>        // std::ostream_iterator
#include <utility>      // std::pair, std::make_pair

typedef std::pair<std::set<std::string>::iterator, bool> Return;

int main (){
    std::set<std::string> mSet;
    mSet.insert("Hello-1");
    mSet.insert("World-1");
    Return rt1 = mSet.emplace("Hello-2");
    std::cout << std::boolalpha << *rt1.first << ", insert OK : "
              << rt1.second     <<  std::endl;
    
    mSet.emplace("World-2");
    Return rt2 = mSet.insert("Hello-1"); // 중복되는 데이터는 입력되지 않는다.
    std::cout << *rt2.first << ", insert OK : "
              << rt2.second <<  std::endl;
              
    std::cout << "mSet : ";
    for(auto& s : mSet)
        std::cout << " " << s.c_str();
    std::cout << std::endl;
    std::cout << "크기 : " << mSet.size() << std::endl;
    
    std::set<std::string>::iterator search = mSet.find("World-2");
    if(search != mSet.end()) 
        std::cout << "Found : " << *search << '\n';
    else 
        std::cout << "Not found\n";

    std::unordered_multiset<std::string> ms;
    std::copy(mSet.begin(), mSet.end(), std::inserter(ms, ms.begin()));
    ms.insert(mSet.begin(), mSet.end());
    ms.insert("Set contains:");
        
    std::cout << "버킷의 수 : " << ms.bucket_count() << std::endl;
    
    while (!ms.empty()) {
       std::cout << '(' << *ms.begin() << ",bucket #" 
                 << ms.bucket(*ms.begin()) << ") ";
       ms.erase(ms.begin());
    }
    std::cout << std::endl;
    return 0;
}