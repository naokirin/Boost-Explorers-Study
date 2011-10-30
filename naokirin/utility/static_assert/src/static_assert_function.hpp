#include <boost/static_assert.hpp>

template <int i>
void upto10(){
  BOOST_STATIC_ASSERT(i<10);
}
