#include "../src/queue.hpp"
#include <list>
#include <memory>
#include <gtest/gtest.h>

using namespace rinsin;

class QueueTest : public ::testing::Test 
{
protected:
  std::unique_ptr<Queue<int> > queue;

  virtual void SetUp() {
    queue = std::unique_ptr<Queue<int> >(new Queue<int>());
  }

  virtual void TearDown() {}
};

// Test Queue.push()
TEST_F(QueueTest, testPush){
  queue->push(1);
  EXPECT_EQ(1, queue->front());
  EXPECT_EQ((size_t)1, queue->getData().size());

  queue->push(2);
  EXPECT_EQ(1, queue->front());
  EXPECT_EQ((size_t)2, queue->getData().size());
}

// Test Queue.pop()
TEST_F(QueueTest, testPop){
  queue->push(1);
  queue->push(2);
  queue->push(3);
  queue->pop();
  EXPECT_EQ(2, queue->front());
  EXPECT_EQ((size_t)2, queue->getData().size());

  queue->pop();
  EXPECT_EQ(3, queue->front());
  EXPECT_EQ((size_t)1, queue->getData().size());

  queue->pop();
  EXPECT_TRUE(queue->getData().empty());
  EXPECT_EQ((size_t)0, queue->getData().size());
}

// Test Queue Constructor
TEST_F(QueueTest, testConstructor){
  queue = std::unique_ptr<Queue<int> >(new Queue<int>(std::list<int>(3, 2)));
  EXPECT_TRUE(std::list<int>(3, 2) == queue->getData());

  queue = std::unique_ptr<Queue<int> >(new Queue<int>(std::list<int>(0)));
  EXPECT_TRUE(std::list<int>(0) == queue->getData());
}
