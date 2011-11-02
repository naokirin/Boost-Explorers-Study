#include <boost/utility.hpp>

class do_not_copy : private boost::noncopyable{
};

int main(){
  do_not_copy dnc1;
  do_not_copy dnc2(dnc1);  // コンパイルエラー
  do_not_copy dnc3;
  dnc3 = dnc1;  // コンパイルエラー

  return 0;
}
