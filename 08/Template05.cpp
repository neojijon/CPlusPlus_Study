#include <iostream>

enum Days { Sunday = 0, Monday = Sunday + 1, Tuesday, 
            Wednesday,  Thursday, Friday, Saturday = Sunday + 6};

const char *week[] = { "Sunday", "Monday", "Tuesday", "Wednesday", 
                       "Thursday", "Friday", "Saturday"};

template<Days D>
class Select {
    
public:
    const char * DayName() {
       return week[D];  
    }
};

int main() {
    Select<Sunday> today; // 열거형 타입의 데이터는 정수로 변환이 가능하다.
    std::cout << today.DayName() << "은 " << Sunday + 1 << "번째 요일이다." << std::endl;
    }