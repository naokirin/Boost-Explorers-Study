#include <boost/utility.hpp>
#include <iostream>


struct bad_op_class{
  int operator&() const{
    std::cout << "boooo!" << std::endl;
    return 0;
  }
};

int main(){

  bad_op_class a;
  bad_op_class *b = boost::addressof(a);  // アドレスが渡される
  bad_op_class *c = &a;  // アドレスではない!

  return 0;
}
