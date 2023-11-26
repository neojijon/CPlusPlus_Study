#include <string>
#include <iostream>

template<typename T>
struct my_map {
    my_map(T t) : data(t) {}
    T GetData() {
        return data;
    }
    
private:
    T data;
};

template<typename K, typename V, template<typename A> typename C = my_map>
class Map {
public:
    Map( K k, V v ) : key(k), value(v) { 
        std::cout << "범용 Map 클래스 템플릿의 생성자가 호출되었습니다." << std::endl;
    }
    
    K Getkey() {
        return key.GetData();
    }
    
    V Getvalue() {
        return value.GetData();
    }
private:
    C<K> key;
    C<V> value;
};

template<typename K>
class Map<K,int> {
public:
    Map( K k, int v ) : key(k), value(v) {
        std::cout << "Map<K,V> 클래스 템플릿의 생성자가 호출되었습니다." << std::endl;
    }

    K Getkey() {
        return key;
    }
    
    int Getvalue() {
        return value;
    }
private:
    K key;
    int value;
};

int main() {
    Map<int, int> imap(100, 1000);
    std::cout << "Map(" << imap.Getkey() << ",'" << imap.Getvalue() << "')\n";
    
    Map<int, std::string, my_map> map( 1000, "템플릿 템플릿 인수" );
    std::cout << "Map(" << map.Getkey() << ",'" << map.Getvalue().c_str() << "')\n";
}
