namespace rinsin{
  template <class T>
  class I_DataStruct{
  public:
    virtual ~I_DataStruct(){};
    virtual void pop() = 0;
    virtual void push(const T& value) = 0;
  };

}
