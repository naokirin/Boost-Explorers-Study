#include<list>

namespace pocketberserker {

	class MyStack {

		std::list<int> data;

	public:

		MyStack() {}

		MyStack(const std::list<int>& d): data(d) {}

		void push(int num) {
			data.push_back(num);
		}

		int back() {
			return data.back();
		}

		void pop() {
			data.pop_back();
		}

		std::list<int> get() {
			return data;
		}
	};
}

