#include <boost/utility.hpp>

class do_not_copy : private boost::noncopyable{
};

int main(){
  do_not_copy dnc1;
  do_not_copy dnc2(dnc1);  // �R���p�C���G���[
  do_not_copy dnc3;
  dnc3 = dnc1;  // �R���p�C���G���[

  return 0;
}
