#ifndef __QUEUE_HPP
#define __QUEUE_HPP

#include <list>
#include "interface_struct.h"
#include <algorithm>

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

  // bool型で特殊化
  template <>
  class Queue<bool> : public I_DataStruct<bool>{
    std::list<bool> data;

  public:

    Queue() = default;

    Queue(const std::list<bool> l){
      data = l;
    }

    void push(const bool& value){
      data.push_back(value);
    }

    void pop(){
      data.pop_front();
    }

    bool front() const{
      return data.front();
    }

    std::list<bool> getData() const{
      return data;
    }

    void flip(){
      std::for_each(data.begin(), data.end(), [&](bool& bit){bit = !bit;});
    }
  };
}

#endif // __QUEUE_HPP

