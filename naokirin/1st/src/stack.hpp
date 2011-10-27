#ifndef __STACK_HPP
#define __STACK_HPP

#include <list>
#include "interface_struct.h"
#include <algorithm>

namespace rinsin{

  template <class T>
  class StackImpl : public I_DataStruct<T>{
  protected:
    std::list<T> data_;

  public:
    StackImpl() = default;

    StackImpl(const std::list<T>& l){
      data_ = l;
    }

    void push(const T& value){
      data_.push_back(value);
    }

    void pop(){
      data_.pop_back();
    }

    T back() const{
      return data_.back();
    }

    std::list<T> getData() const{
      return data_;
    }
  
  };

  template<class T>
  struct Stack : public StackImpl<T>{
  public:
    Stack() : StackImpl<T>(){}
    Stack(const std::list<T>& l) : StackImpl<T>(l){}
  };

  template<>
  struct Stack<bool> : public StackImpl<bool> {
  public:
    Stack() : StackImpl<bool>(){}
    Stack(const std::list<bool>& l) : StackImpl<bool>(l){}

    void flip(){
      std::for_each(data_.begin(), data_.end(), [&](bool& bit){bit = !bit;});
    }

  };
}

#endif // __STACK_HPP
