#ifndef __STACK_HPP
#define __STACK_HPP

#include <list>
#include "interface_struct.h"
#include <algorithm>

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

  template<>
  class Stack<bool> : public I_DataStruct<bool>{
  std::list<bool> data;

  public:
    Stack() = default;

    Stack(const std::list<bool> l){
      data = l;
    }

    void push(const bool& value){
      data.push_back(value);
    }

    void pop(){
      data.pop_back();
    }

    bool back() const{
      return data.back();
    }

    std::list<bool> getData() const{
      return data;
    }

    void flip(){
      std::for_each(data.begin(), data.end(), [&](bool& bit){bit = !bit;});
    }

  };
}

#endif // __STACK_HPP
