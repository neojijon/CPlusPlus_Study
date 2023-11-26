#include <iostream>

enum Days { Sunday = 0, Monday = Sunday + 1, Tuesday, 
            Wednesday,  Thursday, Friday, Saturday = Sunday + 6};
enum class Months : short { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

const char *week[] = { "Sunday", "Monday", "Tuesday", "Wednesday", 
                   "Thursday", "Friday", "Saturday"};
const char * DayName(Days day) {
    if ( day < Sunday || day > Saturday)  
      return "알수없는 주";
  return week[day];  
}

int main () {
    Months thisMonth = Months::Dec;

    // Months 열거형 타입의 요소로부터 Days 열거형 타입의 요소로 변환한다.
    // static_cast 연산자는 다음과 동일한 기능을 수행한다.
    // Days today = (Days) thisMonth;
    Days today = static_cast<Days>(thisMonth);
    std::cout << DayName(today) << "은 " << today + 1 << "번째 요일이다." << std::endl;
    
    Months nextMonth = (Months) ((short) Months::Dec - 12 + 1 );
    today = static_cast<Days>(nextMonth);
    std::cout << DayName(today) << "은 " << today + 1 << "번째 요일이다." << std::endl;
    
    // 열거형 타입의 요소로부터 int 또는 float으로 변환은 다음과 같다.
    float one = static_cast<float>(today);
    std::cout << DayName(today) << "은 " << one + 1 << "번째 요일이다." << std::endl;
}
