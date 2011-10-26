#ifndef __STACK_HPP
#define __STACK_HPP

#include <list>
#include "interface_struct.h"

namespace rinsin{

  template <class T>
  class Stack : public I_DataStruct<T>{
    std::list<T> data;

  public:

    Stack() = default;

    Stack(const std::list<T> l){
      data = l;
    }

    void push(const T& value){
      data.push_back(value);
    }

    void pop(){
      data.pop_back();
    }

    T back() const{
      return data.back();
    }

    std::list<T> getData() const{
      return data;
    }
  
  };
}

#endif // __STACK_HPP
