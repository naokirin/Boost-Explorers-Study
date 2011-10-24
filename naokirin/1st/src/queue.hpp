#ifndef __QUEUE_HPP
#define __QUEUE_HPP

#include <list>
#include "interface_struct.h"

namespace rinsin{

  class Queue : I_DataStruct {
    std::list<int> data;

  public:

    Queue() = default;

    Queue(const std::list<int> l){
      data = l;
    }

    void push(const int& value){
      data.push_back(value);
    }

    void pop(){
      data.pop_front();
    }

    int front() const{
      return data.front();
    }

    std::list<int> getData(){
      return data;
    }
  
  };
}

#endif // __QUEUE_HPP

