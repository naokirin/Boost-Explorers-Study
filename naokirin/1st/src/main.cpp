#include "stack.hpp"
#include <iostream>
#include <cassert>

int main(){
  rinsin::stack s1;

  std::list<int> l;
  l.push_back(1); l.push_back(2); 

  rinsin::stack s2(l);

  s1.push(1);
  s1.push(2);
  assert(s1.getData() == l);
  assert(s2.getData() == l);

  s1.pop();
  l.pop_back();

  assert(s1.getData() == l);

  return 0;
}
