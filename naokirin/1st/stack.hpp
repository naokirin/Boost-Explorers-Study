#include <list>

namespace rinsin{

  class stack {
    std::list<int> data;

  public:

    stack() = default;

    stack(const std::list<int> l){
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
