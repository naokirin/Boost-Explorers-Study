#include "../src/stack.hpp"
#include <list>
#include <memory>
#include <gtest/gtest.h>

using namespace rinsin;

class StackTest : public ::testing::Test 
{
protected:
  std::unique_ptr<Stack<int> > stack;

  virtual void SetUp() {
    stack = std::unique_ptr<Stack<int> >(new Stack<int>());
  }

  virtual void TearDown() {}
};

// Test Stack.push()
TEST_F(StackTest, testPush){
  stack->push(1);
  EXPECT_EQ(1, stack->back());
  EXPECT_EQ((size_t)1, stack->getData().size());

  stack->push(2);
  EXPECT_EQ(2, stack->back());
  EXPECT_EQ((size_t)2, stack->getData().size());
}

// Test Stack.pop()
TEST_F(StackTest, testPop){
  stack->push(1);
  stack->push(2);
  stack->push(3);
  stack->pop();
  EXPECT_EQ(2, stack->back());
  EXPECT_EQ((size_t)2, stack->getData().size());

  stack->pop();
  EXPECT_EQ(1, stack->back());
  EXPECT_EQ((size_t)1, stack->getData().size());

  stack->pop();
  EXPECT_TRUE(stack->getData().empty());
  EXPECT_EQ((size_t)0, stack->getData().size());
}

// Test Stack Constructor
TEST_F(StackTest, testConstructor){
  stack = std::unique_ptr<Stack<int> >(new Stack<int>(std::list<int>(3, 2)));
  EXPECT_TRUE(std::list<int>(3, 2) == stack->getData());

  stack = std::unique_ptr<Stack<int> >(new Stack<int>(std::list<int>(0)));
  EXPECT_TRUE(std::list<int>(0) == stack->getData());
}
