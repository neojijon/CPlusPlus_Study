#include <iostream>
#include <exception>

template <typename T>
class LinkedList {
    struct Node{
        T data;
        Node* prev;
        Node* next;
        Node(T t, Node* p, Node* n) : data(t), prev(p), next(n) {}
    };
    Node* head;
    Node* tail;
public:
    LinkedList() : head( nullptr ), tail ( nullptr ) {}

    template<int N>
    LinkedList(T (&arr) [N]) : LinkedList() {
        for( int i(0); i < N; ++i)
            push_back(arr[i]);
    }

    ~LinkedList(){
        while(head) {
            Node* temp = head;
            head=head->next;
            delete temp;
        }
    }
    
    bool empty() const { return ( !head || !tail ); }
//    operator bool() const { return !empty(); } 
    void push_back(T);
    void push_front(T);
    T pop_back();
    T pop_front();

};

int main(){
    int arr[] = { 4, 6, 8, 32, 19 } ;
    LinkedList<int> list ( arr );
    list.push_back( 11 );
    list.push_front( 100 );
    while( !list.empty() )
        std::cout << list.pop_front()  << " ";
    std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::push_back(T data){
    tail = new Node(data, tail, nullptr);
    if( tail->prev )
        tail->prev->next = tail;

	if( nullptr == head ) head = tail;
}

template <typename T>
void LinkedList<T>::push_front(T data){
    head = new Node(data, nullptr, head);
    if( head->next )
        head->next->prev = head;

	// 처음 입력되는 데이터라면 head와 tail은 같은 Node 객체를 가리킨다.
	if( nullptr == tail) tail = head;
}

template<typename T>
T LinkedList<T>::pop_back(){
    if( empty() )
        throw std::runtime_error("LinkedList : 비어있습니다.");
    
    Node* temp(tail);
    T data( tail->data );
    tail = tail->prev ;

    if( tail )
        tail->next = nullptr;
    else
        head = nullptr ;

    delete temp;
    return data;
}

template<typename T>
T LinkedList<T>::pop_front(){
    if( empty() )
         throw std::runtime_error("LinkedList : 비어있습니다.");

    Node* temp(head);
    T data( head->data );
    head = head->next ;

    if( head )
        head->prev = nullptr;
    else
        tail = nullptr;

    delete temp;
    return data;
}
