#ifndef Array_hpp
#define Array_hpp 

#include <initializer_list>
#include <exception>
#include <iterator>

template <typename Type>
class Array {
public:
    typedef  std::size_t  size_type;
   
    class iterator { 
        public:
        typedef Type value_type;
        typedef Type& reference;
        typedef Type* pointer;
        typedef std::random_access_iterator_tag iterator_category;

        // typedef typename std::iterator<std::random_access_iterator_tag, Type>::difference_type  difference_type; 
       typedef std::ptrdiff_t difference_type;
        
        constexpr iterator() : _ptr( nullptr ) {}
        constexpr iterator( Type* rhs ) : _ptr( rhs ) {}
        constexpr iterator( const iterator &rhs ) : _ptr( rhs._ptr ) {}
        constexpr iterator& operator=(Type* rhs) {_ptr = rhs; return *this;} 
        constexpr iterator& operator=(const iterator &rhs) {_ptr = rhs._ptr; return *this;} 
        constexpr iterator& operator+=( difference_type rhs ) { _ptr += rhs; return *this; }
        constexpr iterator& operator-=( difference_type rhs ) { _ptr -= rhs; return *this; }
        constexpr Type& operator*() const { return *_ptr; }
        constexpr Type* operator->() const { return _ptr; }
        constexpr Type& operator[]( difference_type rhs ) const { return _ptr[rhs]; }

        constexpr iterator& operator++() { ++_ptr; return *this; }
        constexpr iterator& operator--() { --_ptr; return *this; }
        constexpr iterator operator++( int ) { iterator tmp( *this ); ++_ptr; return tmp; }
        constexpr iterator operator--( int ) { iterator tmp( *this ); --_ptr; return tmp; }
        
        constexpr iterator operator+( difference_type rhs ) const { return iterator( _ptr + rhs ); }
        constexpr iterator operator-( difference_type rhs ) const { return iterator( _ptr - rhs ); }

        constexpr difference_type operator+(const iterator& rhs) const { return _ptr + rhs._ptr; }
        constexpr difference_type operator-(const iterator& rhs) const { return _ptr - rhs._ptr; }
        friend constexpr iterator operator+( difference_type lhs, const iterator& rhs ) { 
            return iterator( lhs + rhs._ptr ); 
        }
        friend constexpr iterator operator-( difference_type lhs, const iterator& rhs ) { 
            return iterator( lhs - rhs._ptr ); 
        }

        constexpr bool operator==( const iterator& rhs ) const { return _ptr == rhs._ptr; }
        constexpr bool operator!=( const iterator& rhs ) const { return _ptr != rhs._ptr; }
        constexpr bool operator>( const iterator& rhs ) const { return _ptr > rhs._ptr; }
        constexpr bool operator<( const iterator& rhs ) const { return _ptr < rhs._ptr; }
        constexpr bool operator>=( const iterator& rhs ) const { return _ptr >= rhs._ptr; }
        constexpr bool operator<=( const iterator& rhs ) const { return _ptr <= rhs._ptr; }
    private:
        Type* _ptr;
    };
          
    // class const_iterator { /* 생략한다... */ }
 
    constexpr Array( size_type size = 0 ): _size( size ) {
        if (0 == size) _data = nullptr;
        else _data = new Type[_size](); // 초기화를 시켜준다.
    }
    
    constexpr Array( std::initializer_list<Type> init ) : _size( init.size() ) {
        _data = new Type[_size];
        std::copy( init.begin(), init.end(), _data );
    }
    
    template<typename _InputIterator>
    constexpr Array(_InputIterator _first, _InputIterator _last) {
        size_type size = _last - _first;
        _data = new Type[size];
        std::copy( _first, _last, _data );
        _size = size;
    }

    inline ~Array() {
        if (_data) {
            delete[] _data;
            _size = 0;
        }
    }

    constexpr void push_back(Type t){
        size_type size = _size + 1;
        Type *temp = new Type[size];
        std::copy( _data, _data + _size, temp );
        temp[_size] = t;
        delete[] _data;
        _data = temp;
        _size = size;
    }
    
    constexpr Type pop_back(){
        if( 0 == _size )
            throw std::runtime_error("Array : 비어있습니다.");
        --_size;
        return _data[_size];
    }
    
    constexpr size_type size() const { return _size; }

    constexpr Type& operator[]( size_type index ){
        if( index >= _size || index < 0 )
            throw std::runtime_error("index가 잘못되었습니다.");
        return _data[index];
    }
    
    constexpr const Type& operator[]( size_type index ) const {
        if( index >= _size || index < 0 )
            throw std::runtime_error("index가 잘못되었습니다.");
        return _data[index];
    }
    
    constexpr iterator begin() {
        return iterator( _data );
    }

    constexpr iterator end() {
        return iterator( _data + _size );
    }

private:
    Type* _data;
    size_type _size;
};
#endif