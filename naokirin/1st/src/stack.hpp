#ifndef __STACK_HPP
#define __STACK_HPP

#include <list>
#include "interface_struct.h"

namespace rinsin{

  class Stack : public I_DataStruct{
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

    std::list<int> getData() const{
      return data;
    }
  
  };
}

#endif // __STACK_HPP
