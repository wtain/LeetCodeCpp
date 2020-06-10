
#include <iostream>
#include <queue>

using namespace std;

class MyStack {

	queue<int> m_first, m_second;

private:

	queue<int>& Current()
	{
		return m_first.empty() ? m_second : m_first;
	}

	queue<int>& Other()
	{
		return m_first.empty() ? m_first : m_second;
	}

public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		Current().push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		queue<int>& q1 = Current();
		queue<int>& q2 = Other();
		int sz = q1.size() - 1;
		for (int i = 0; i < sz; ++i)
		{
			q2.push(q1.front());
			q1.pop();
		}
		int rv = q1.front();
		q1.pop();
		return rv;
	}

	/** Get the top element. */
	int top() {
		return Current().back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return m_first.empty() && m_second.empty();
	}
};

int main()
{
	MyStack s;

	s.push(1);
	s.push(2);
	s.push(3);

	while (!s.empty())
		cout << s.pop() << endl;

    return 0;
}

