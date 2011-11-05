#include <iostream>
#include <vector>
#include <complex>

// T型とU型のデータを*で演算したときの
// 戻り値の型が戻り値になる
template <class T, class U>
auto test(T a, U b) -> decltype(a*b){

  return a*b;
}

int main(){
  std::vector<int> vec;

  for(int i =0; i < 10; ++i)
    vec.push_back(i);

  // イテレータの型の宣言は長くなりがちなので、
  // autoで型推論してもらう
  for(auto itr=vec.begin(); itr != vec.end(); ++itr)
    std::cout << *itr;

  std::cout << std::endl;

  auto z = std::complex<int>(1, 2);
  std::cout << test(z, 2) << std::endl;

  return 0;
}
