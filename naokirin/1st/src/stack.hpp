#ifndef __STACK_HPP
#define __STACK_HPP

#include <list>

namespace rinsin{

  class Stack {
    std::list<int> data;

  public:

    Stack() = default;

    Stack(const std::list<int> l){
      data = l;
    }

    void push(const int& value){
      data.push_back(value);
    }

    void pop(){
      data.pop_back();
    }

    int back() const{
      return data.back();
    }

    std::list<int> getData(){
      return data;
    }
  
  };
}

#endif // __STACK_HPP
