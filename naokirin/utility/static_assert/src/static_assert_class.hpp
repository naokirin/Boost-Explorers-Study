#include <boost/type_traits.hpp>
#include <boost/static_assert.hpp>

template <class T>
class OnlyIntegral{
  BOOST_STATIC_ASSERT(boost::is_integral<T>::value);

private:
  T value;

public:
  OnlyIntegral(){value = 0;}
  void increment(){++value;}
  void decrement(){--value;}
  T getValue() const{return value;}
};
