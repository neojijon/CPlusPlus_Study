#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <initializer_list>

#define NDEBUG

template <typename Type>
class Array {
    public:
        typedef int size_type;
       class iterator { 
            public:
                typedef Type value_type;
                typedef Type& reference;
                typedef Type* pointer;
                typedef std::forward_iterator_tag iterator_category;
                typedef int difference_type;

                iterator(pointer ptr = nullptr) : _ptr(ptr) { }
                iterator operator++() { ++_ptr; return *this; }
                iterator operator++(int) { iterator tmp( *this ); ++_ptr; return tmp; }
                reference operator*() { return *_ptr; }
                pointer operator->() { return _ptr; }
                bool operator==(const iterator& rhs) { return _ptr == rhs._ptr; }
                bool operator!=(const iterator& rhs) { return _ptr != rhs._ptr; }
            private:
                pointer _ptr;
        };

        Array(size_type size) : _size(size) {
            _data = new Type[_size]();
        }

        Array(std::initializer_list<Type> init) : _size(init.size()) {
            _data = new Type[_size];
            std::copy(init.begin(), init.end(), _data);
        }
        
        template<typename _InputIterator>
        inline Array(_InputIterator _first, _InputIterator _last) {
            size_type size = _last - _first;
            _data = new Type[size];
            std::copy( _first, _last, _data );
            _size = size;
        }
    
        ~Array() {
            if (_data) { 
                delete[] _data;
                _size = 0;
            }
        }

        size_type size() const { return _size; }

        Type& operator[](size_type index){
            assert(index < _size);
            return _data[index];
        }

        const Type& operator[](size_type index) const {
            assert(index < _size);
            return _data[index];
        }

        iterator begin(){
            return iterator(_data);
        }

        iterator end(){
            return iterator(_data + _size);
        }

    private:
        Type* _data;
        size_type _size;
};

struct Account {
    Account() = default;
    
    Account( const char *id, const char *name, int bal ) {
        strcpy( this->account, id );
        strcpy( this->name, name );
        this->balance = bal;
    }

    char account[20];
    char name[20];
    int  balance;
};

int main(){
    Array<double> array = {2.3, 3.2, 4.3, 16.78, 9.4, 3.14};
    for(Array<double>::iterator i = array.begin(); i != array.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
  
   Array<Account> list  = {
        { "120-345-129099", "홍길동", 60000 },
        { "120-345-223011", "김홍도", 10000 },
        { "210-545-144011", "신사임당", 50000 }
    };
    
    for (auto& i : list) {
        printf( "계 좌 : %s , 소유자 : %s", i.account, i.name );
        printf( ", 잔 액 : %i\n", i.balance );
    }

    std::vector<double> vec;
    std::copy(array.begin(), array.end(), std::back_inserter(vec));

    for(std::vector<double>::iterator i = vec.begin(); i != vec.end(); ++i) {
        std::cout << *i << " ";
    }

    std::cout << std::endl;
    return 0;
}
