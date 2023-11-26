#ifndef door_hpp
#define door_hpp

extern int myGlobal;
namespace mynamespace {

// using namespace std;

struct Door {
    void Open();
    void Close();
    void ShowState() const;

    void SetName(std::string s);
    std::string GetName() const;

    int state;
    std::string name;
    void State(int i);
};

inline void Door::State(int i){
	state = i;
}
}
#endif 