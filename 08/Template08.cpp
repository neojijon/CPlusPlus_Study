#include <iostream>
#include <string>

// Visual Studio는 __FUNCTION__ Macro를 사용한다.
#define __PRETTY_FUNCTION__ __FUNCTION__

template <typename Key, typename Value>
class KeyValuePair {
public:
    KeyValuePair( Key k, Value v) : key(k), value(v) {
        std::cout << "① " << __PRETTY_FUNCTION__ << ':' << "original\n";
    }
private:    
    Key key;
    Value value;
};

template <>
class KeyValuePair<int, std::string> {
public:
    KeyValuePair( int k, std::string v) : key(k), value(v) {
        std::cout << "② " << __PRETTY_FUNCTION__ << ':' << "explicit full specialized\n";
    }
private:    
    int key;
    std::string value;
};

template <typename Key>
class KeyValuePair<Key, std::string> {
public:
    KeyValuePair( Key k, std::string v) : key(k), value(v) {
        std::cout << "③ " << __PRETTY_FUNCTION__ << ':' << "specialized\n";
    }
private:    
    Key key;
    std::string value;
};

int main(){
    KeyValuePair<int,int> kvp1(100, 100);
    KeyValuePair<long, std::string> kvp2(100, "템플릿의 특수화");
    KeyValuePair<int, std::string> kvp3(100, "템플릿의 특수화");
}