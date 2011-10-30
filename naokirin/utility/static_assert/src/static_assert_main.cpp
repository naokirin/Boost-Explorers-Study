#include <vector>
#include "static_assert_class.hpp"
#include "static_assert_function.hpp"
#include "cpp11_static_assert.hpp"

class Foo{Foo() = default;};
class Bar{};
class Far{Far(){};};
class Boo{Boo(int){}};

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

  // cpp11_static_assert.hpp
  trivial_ctor_checker<Foo>(); // OK
  trivial_ctor_checker<Bar>(); // OK
  // trivial_ctor_checker<Far>(); // Compile Error!
  // trivial_ctor_checker<Boo>(); // Compile Error!

  return 0;
}
