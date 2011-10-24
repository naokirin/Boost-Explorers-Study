namespace rinsin{
  class I_DataStruct{
  public:
    virtual ~I_DataStruct(){};
    virtual void pop() = 0;
    virtual void push(const int& value) = 0;
  };

}
