
#include <iostream>
#include <string>
#include <functional>
#include <thread>
#include <chrono>
#include <random>
#include <mutex>
#include <condition_variable>

using namespace std;

/*
https://leetcode.com/problems/print-foobar-alternately/

Suppose you are given the following code:

class FooBar {
public void foo() {
for (int i = 0; i < n; i++) {
print("foo");
}
}

public void bar() {
for (int i = 0; i < n; i++) {
print("bar");
}
}
}
The same instance of FooBar will be passed to two different threads. Thread A will call foo() while thread B will call bar(). Modify the given program to output "foobar" n times.



Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar(). "foobar" is being output 1 time.
Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.

*/

//Runtime: 632 ms, faster than 5.73% of C++ online submissions for Print FooBar Alternately.
//Memory Usage : 8.2 MB, less than 68.67% of C++ online submissions for Print FooBar Alternately.
class FooBar {
private:
	int n;

	mutex m;
	condition_variable cv;
	bool state;

public:
	FooBar(int n) {
		this->n = n;
		state = false;
	}

	void foo(function<void()> printFoo) {

		for (int i = 0; i < n; i++) {

			unique_lock<mutex> lock(m);
			cv.wait(lock, [&] {return !state; });

			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();

			state = true;
			lock.unlock();
			cv.notify_one();
		}
	}

	void bar(function<void()> printBar) {

		for (int i = 0; i < n; i++) {

			unique_lock<mutex> lock(m);
			cv.wait(lock, [&] {return state; });

			// printBar() outputs "bar". Do not change or remove this line.
			printBar();

			state = false;
			lock.unlock();
			cv.notify_one();
		}
	}
};

void thread1(FooBar& foo, mt19937& gen) {
	foo.foo([&]() { 
		this_thread::sleep_for(chrono::duration<int, milli>(10 + gen() % 200));
		cout << "foo"; 
	});
}

void thread2(FooBar& foo, mt19937& gen) {
	foo.bar([&]() { 
		this_thread::sleep_for(chrono::duration<int, milli>(10 + gen() % 200));
		cout << "bar"; 
	});
}

int main()
{
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());  // to seed mersenne twister.

	for (int i = 0; i < 10; ++i) {
		FooBar foobar(3);

		thread t1(thread1, ref(foobar), ref(gen)), t2(thread2, ref(foobar), ref(gen));

		t1.join();
		t2.join();

		cout << endl;
	}

    return 0;
}

