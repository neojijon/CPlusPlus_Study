#include <iostream>
#include <cassert>

#define NDEBUG

template <typename Type>
class Array {
    public:
        typedef int size_type;

        Array(size_type size) : _size(size) {
            _data = new Type[_size]();
        }
/*
        Array(std::initializer_list<Type> init) : _size(init.size()) {
            _data = new Type[_size];
            std::copy(init.begin(), init.end(), _data);
        }
 */       
        ~Array() {
            if (_data) { 
                delete[] _data;
                _size = 0;
            }
        }
        
        inline size_type size() const { return _size; }

        Type& operator[](size_type index){
            assert(index < _size);
            return _data[index];
        }

        const Type& operator[](size_type index) const {
            assert(index < _size);
            return _data[index];
        }

    private:
        Type* _data;
        size_type _size;
};

int main(){
    Array<double> array(4); 
    array[0] = 2.3;
    array[1] = 3.2;
    array[2] = 4.2;
    array[3] = 16.78;
    
    for(int i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
