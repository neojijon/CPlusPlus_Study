#include <iostream> 
#include <memory> 
#include <memory_resource>
#include <vector>
#include <iterator>

int main() {
    std::pmr::polymorphic_allocator<char> alloc;   
    char* array = alloc.allocate(100 * sizeof(char));
    size_t c = 0;
    for (char ch = 'A'; ch <= 'z'; ++ch)
        array[c++] = ch;
    array[c] = NULL;

    std::cout << c << ", " << array << std::endl;
    alloc.deallocate(array, 100 * sizeof(char));
	
    char buffer[64] = {};
    std::fill_n(std::begin(buffer), std::size(buffer) - 1, '_');
    std::cout << buffer << std::endl;

    std::pmr::monotonic_buffer_resource pool{
        std::data(buffer), std::size(buffer)
    };

    std::pmr::vector<char> vec{ &pool };
    for (char ch = 'a'; ch <= 'z'; ++ch)
        vec.push_back(ch);

    std::cout << buffer << std::endl;

    std::pmr::memory_resource* mr = std::pmr::get_default_resource();
    void* p = mr->allocate(2*sizeof(int), alignof(int));

    int* p_int = new(p) int[2] { 256, 1024 };

    std::cout << p_int[0] << ", " << p_int[1] << std::endl;

    std::cout << p << std::endl;
    std::cout << p_int << std::endl;

    std::destroy_n(p_int, 2);

    p_int = new(p) int{ 64 };
    std::cout << *p_int << std::endl;

    std::cout << p << std::endl;
    std::cout << p_int << std::endl;

    std::destroy_at(p_int);

    mr->deallocate(p, sizeof(int), alignof(int));
    return 0;
}