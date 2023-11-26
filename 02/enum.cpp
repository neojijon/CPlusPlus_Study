#include <iostream>

enum Days { 
    None = 0x0,
    Sunday = 1, 
    Monday = 1 << 1, 
    Tuesday = 1 << 2, 
    Wednesday = 1 << 3,
    Thursday = 1 << 4,
    Friday = 1 << 5, 
    Saturday  = 1 << 6};

inline Days operator| (Days a, Days b) { return (Days)((int)a | (int)b); }

const char *week[] = { "Sunday", "Monday", "Tuesday", "Wednesday", 
                       "Thursday", "Friday", "Saturday"};
void DayName(Days d) {
    std::cout << d << ", ";
    for (int i = 0; i < 7; ++i) {
        if (d & (1 << i))
            std::cout << week[i] << ' ';
    }
    std::cout << std::endl;
} 

int main() {
    DayName(Sunday);
//    Days meeting = Thursday | Monday;
    Days meeting = Days ((int) Thursday | (int) Monday);
    DayName(meeting);
}

