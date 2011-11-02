#include <boost/type_traits.hpp>

template <class T>
void trivial_ctor_checker(){
  static_assert(boost::has_trivial_constructor<T>::value, "Not has trivial Ctor!");
};

class Foo{Foo() = default;};
class Bar{};
class Far{Far(){};};
class Boo{Boo(int){}};

int main(){
  trivial_ctor_checker<Foo>(); // OK
  trivial_ctor_checker<Bar>(); // OK
  // trivial_ctor_checker<Far>(); // Compile Error!
  // trivial_ctor_checker<Boo>(); // Compile Error!

  return 0;
}
