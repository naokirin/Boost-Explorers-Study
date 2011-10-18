#include "../src/stack.hpp"
#include <memory>
#include <gtest/gtest.h>

using namespace rinsin;

class StackTest : public ::testing::Test 
{
protected:
  std::unique_ptr<Stack> stack;

  virtual void SetUp() {
    stack = std::unique_ptr<Stack>(new Stack());
  }

  virtual void TearDown() {}
};


TEST_F(StackTest, testPush){
  stack->push(1);
  EXPECT_EQ(1,stack->back());
}

TEST_F(StackTest, testPop){
  stack->push(1);
  stack->push(2);
  stack->pop();
  EXPECT_EQ(1, stack->back());
}

TEST_F(StackTest, test){
  std::unique_ptr<Stack> s(new Stack(std::list<int>(3, 2)));
  EXPECT_TRUE(std::list<int>(3, 2) == s->getData());
}
