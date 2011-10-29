#ifndef __QUEUE_HPP
#define __QUEUE_HPP

#include <list>
#include "interface_struct.h"
#include <algorithm>

namespace rinsin{
  template <class T>
  class QueueImpl : public I_DataStruct<T>{
  protected:
    std::list<T> data_;

  public:
    QueueImpl() = default;

    QueueImpl(const std::list<T>& l) : data_(l){}

    void push(const T& value){
      data_.push_back(value);
    }

    void pop(){
      data_.pop_front();
    }

    T front() const{
      return data_.front();
    }

    std::list<T> getData() const{
      return data_;
    }
  
  };

  template <class T>
  class Queue : public QueueImpl<T>{
  public:
    Queue() : QueueImpl<T>() {}
    Queue(const std::list<T>& l) : QueueImpl<T>(l) {}
  };

  template <>
  class Queue<bool> : public QueueImpl<bool>{
  public:
    Queue() : QueueImpl<bool>() {}
    Queue(const std::list<bool>& l) : QueueImpl<bool>(l) {}

    void flip(){
      std::for_each(data_.begin(), data_.end(), [&](bool& bit){bit = !bit;});
    }
  };
}

#endif // __QUEUE_HPP

