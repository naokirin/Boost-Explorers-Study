#include <cassert>
#include <boost/type_traits.hpp>

template <class T>
void trivial_ctor_checker(){
  static_assert(boost::has_trivial_constructor<T>::value, "Not has trivial Ctor!");
};
