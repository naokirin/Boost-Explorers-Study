#ifndef __QUEUE_HPP
#define __QUEUE_HPP

#include <list>
#include "interface_struct.h"

namespace rinsin{
  template <class T>
  class Queue : public I_DataStruct<T>{
    std::list<T> data;

  public:

    Queue() = default;

    Queue(const std::list<T> l){
      data = l;
    }

    void push(const T& value){
      data.push_back(value);
    }

    void pop(){
      data.pop_front();
    }

    T front() const{
      return data.front();
    }

    std::list<T> getData() const{
      return data;
    }
  
  };
}

#endif // __QUEUE_HPP

