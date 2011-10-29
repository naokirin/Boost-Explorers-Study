#include<gtest/gtest.h>

#include "./mystack.hpp"

using namespace pocketberserker;

TEST(MyStackTest, testPush) {
	MyStack stack;
	stack.push(1);
	stack.push(2);
	ASSERT_EQ(2,stack.back());
}

TEST(MyStackTest, testPop) {
	MyStack stack;
	stack.push(1);
	stack.push(2);
	stack.pop();
	ASSERT_EQ(1,stack.back());
}

TEST(MyStackTest, testGet) {
	MyStack stack;
	stack.push(1);
	stack.push(2);
	std::list<int> data = stack.get();
	ASSERT_EQ(2,data.back());
	ASSERT_EQ(1,data.front());
	ASSERT_EQ((size_t)2,data.size());
}

TEST(MyStackTest, testConstructor) {
	std::list<int> data;
	data.push_back(1);
	data.push_back(2);
	MyStack stack(data);
	ASSERT_EQ(2,stack.back());
	EXPECT_TRUE(data == stack.get());
}

