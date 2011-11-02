#include <vector>
#include "static_assert_class.hpp"
#include "static_assert_function.hpp"

int main(){
  // static_assert_class.hpp
  OnlyIntegral<int>(); // OK
  OnlyIntegral<long>(); // OK
  OnlyIntegral<short>(); // OK
  // OnlyIntegral<double>(); // Compile Error!
  // OnlyIntegral<std::vector<int> >(); // Compile Error!

  // static_assert_function.hpp
  upto10<1>(); // OK
  upto10<5>(); // OK
  // upto10<10>(); // Compile Error!

  return 0;
}
