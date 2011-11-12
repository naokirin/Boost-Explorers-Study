#include <iostream>
#include <typeinfo>
#include <boost/typeof/typeof.hpp>
#include <complex>

int main(){

  int x = 0;
  std::cout << typeid(BOOST_TYPEOF(x)).name() << std::endl;

  BOOST_AUTO(y, 90);

  std::cout << typeid(BOOST_TYPEOF(y)).name() << std::endl;

  return 0;
}
