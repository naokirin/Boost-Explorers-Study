/**
 クラススタックの作成
 0. int型のデータを保持できるようにする（std::vectorやstd::listを用いてもよいが、どちらがよりよいか調べること。特にパフォーマンスがどうなっているかに気をつける）
 1. int型の値をプッシュして、末尾にデータを追加できるメンバ関数
 2. ポップして、末尾のデータを削除するメンバ関数
 3. 末尾の値を返すメンバ関数
 4. すべてのデータを返すメンバ関数（内部データ型と一致させておくこと）
 5. 内部データ型と同じ型のデータを受け取って、その値によってデータを初期化するコンストラクタを定義する
 **/

//test

#include <iostream>
#include <vector>
#include <boost/assign.hpp>

class MyStack{
public:
	//int型の値をプッシュして、末尾にデータを追加できるメンバ関数
	void push(const int n);
	//ポップして、末尾のデータを削除する関数
	void pop();
	//末尾の要素を返す
	int last();
	//すべてのデータを返すメンバ関数
	std::vector<int> all();
	//内部型データ型と同じ型のデータを受け取って、その値によってデータを初期化するコンストラクタを定義する
	MyStack(std::vector<int> s);
	void show();
    
private:
	//int 型データの保持
	std::vector<int> stack;
};

static int mystack_test()
{
    using namespace boost::assign;
	std::vector<int> s;
    s += 1,2,3;
    
	const int N = 100;
	MyStack mystack(s);
	mystack.push(N);
	mystack.push(N+1);
	mystack.push(N+2);
	
    mystack.show();
	mystack.pop();
	mystack.show();
    
	mystack.push(mystack.last());
	mystack.show();
    
	return 0;   
}

void MyStack::push(const int n)
{
	stack.push_back(n);
}

void MyStack::pop()
{
	stack.pop_back();
}

int MyStack::last()
{
	return stack.back();
}

std::vector<int> MyStack::all()
{
	return stack;
}

MyStack::MyStack(std::vector<int> s)
{
	stack = s;
}

void MyStack::show()
{
 
    for(int i: stack) std::cout << i << " ";
    //for(std::vector<int>::iterator it = stack.begin(); it < stack.end(); ++it)
    //    std::cout << *it << " ";
    
	std::cout << std::endl;
}

/**
 キューの作成
 0.int型を保持できるようにする
 1.int型をプッシュして、末尾にデータを追加できるメンバ関数
 2.ポップして、先頭のデータを削除するメンバ関数
 3.先頭の値を返すメンバ関数
 4.すべてのデータを返すメンバ関数（内部データ型と一致させておくこと）
 5. 内部データ型と同じ型のデータを受け取って、その値によってデータを初期化するコンストラクタを定義する
**/


class MyQueue{
public:
	//int型の値をプッシュして、末尾にデータを追加できるメンバ関数
	void push(const int n);
	//ポップして、先頭のデータを削除する関数
	void pop();
	//先頭の要素を返す
	int first();
	//すべてのデータを返すメンバ関数
	std::vector<int> all();
	//内部型データ型と同じ型のデータを受け取って、その値によってデータを初期化するコンストラクタを定義する
	MyQueue(std::vector<int> q);
	void show();
    
private:
	//int 型データの保持
	std::vector<int> queue;
};

static int myqueue_test()
{
    using namespace boost::assign;
	std::vector<int> q;
    q += 1,2,3;
    
	const int N = 100;
	MyQueue myqueue(q);
	myqueue.push(N);
	myqueue.push(N+1);
	myqueue.push(N+2);
	
    myqueue.show();
	
    myqueue.pop();
	myqueue.show();
    
	myqueue.push(myqueue.first());
	myqueue.show();
    
	return 0;   
}

void MyQueue::push(const int n)
{
	queue.push_back(n);
}

void MyQueue::pop()
{
	queue.pop_back();
}

int MyQueue::first()
{
	return queue.front();
}

std::vector<int> MyQueue::all()
{
	return queue;
}

MyQueue::MyQueue(std::vector<int> q)
{
	queue = q;
}

void MyQueue::show()
{
    
    for(int i: queue) std::cout << i << " ";
    
	std::cout << std::endl;
}

int main () 
{
	//return mystack_test();    
	return myqueue_test();
}

