#include <iostream>     // std::cout
#include <functional>   // std::function, std::negate
#include <vector>

int half(int x) {return x/2;}

struct third {
  int operator()(int x) {return x/3;}
};

struct MyValue {
  int value;
  int fifth() {return value/5;}
};

int main () {
  std::vector<std::function<int(int)>> func = {half, &half, third()/*, std::negate<int>()*/};
  func.push_back([](int x){return x * 4;});  // lambda expression
  
  int x = 60;
  for (auto& f : func)  
      std::cout << (x = f(x)) << ' ';
      
  std::cout << std::endl;

  std::function<int(MyValue&)> value = &MyValue::value;
  std::function<int(MyValue&)> fifth = &MyValue::fifth;

  MyValue sixty {60};

  std::cout << "value(sixty): " << value(sixty) << '\n';
  std::cout << "fifth(sixty): " << fifth(sixty) << '\n';

  return 0;
}
