#include <iostream>
#include <vector>

template <class T, class U>
auto test(T a, U b) -> decltype(a*b){

  return a*b;
}

int main(){
  std::vector<int> vec;

  for(int i =0; i < 10; ++i)
    vec.push_back(i);

  for(auto itr=vec.begin(); itr != vec.end(); ++itr)
    std::cout << *itr;

  std::cout << std::endl;

  std::cout << test(1.0, 2.0) << std::endl;

  return 0;
}
