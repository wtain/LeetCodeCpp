
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
https://leetcode.com/problems/print-zero-even-odd/

Suppose you are given the following code:

class ZeroEvenOdd {
public ZeroEvenOdd(int n) { ... }      // constructor
public void zero(printNumber) { ... }  // only output 0's
public void even(printNumber) { ... }  // only output even numbers
public void odd(printNumber) { ... }   // only output odd numbers
}
The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A will call zero() which should only output 0's.
Thread B will call even() which should only ouput even numbers.
Thread C will call odd() which should only output odd numbers.
Each of the threads is given a printNumber method to output an integer. Modify the given program to output the series 010203040506... where the length of the series must be 2n.



Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously. One of them calls zero(), the other calls even(), and the last one calls odd(). "0102" is the correct output.
Example 2:

Input: n = 5
Output: "0102030405"

*/

//Runtime: 64 ms, faster than 27.85% of C++ online submissions for Print Zero Even Odd.
//Memory Usage : 6.9 MB, less than 78.67% of C++ online submissions for Print Zero Even Odd.
class ZeroEvenOdd {
private:
	int n;

	mutex m;
	condition_variable cv;
	int state;

public:
	ZeroEvenOdd(int n) {
		this->n = n;
		state = 0;
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
		for (int i = 0; i < n; ++i) {

			unique_lock<mutex> lock(m);
			cv.wait(lock, [&] {return state == 0; });

			printNumber(0);

			state = 1 + i % 2;
			lock.unlock();
			cv.notify_all();
		}
	}

	void even(function<void(int)> printNumber) {
		for (int i = 2; i <= n; i += 2) {

			unique_lock<mutex> lock(m);
			cv.wait(lock, [&] {return state == 2; });

			printNumber(i);

			state = 0;
			lock.unlock();
			cv.notify_all();
		}
	}

	void odd(function<void(int)> printNumber) {
		for (int i = 1; i <= n; i += 2) {
			
			unique_lock<mutex> lock(m);
			cv.wait(lock, [&] {return state == 1; });

			printNumber(i);

			state = 0;
			lock.unlock();
			cv.notify_all();
		}
	}
};

void threadA(ZeroEvenOdd& foo, mt19937& gen) {
	foo.zero([&](int i) {
		this_thread::sleep_for(chrono::duration<int, milli>(10 + gen() % 200));
		cout << i;
	});
}

void threadB(ZeroEvenOdd& foo, mt19937& gen) {
	foo.even([&](int i) {
		this_thread::sleep_for(chrono::duration<int, milli>(10 + gen() % 200));
		cout << i;
	});
}

void threadC(ZeroEvenOdd& foo, mt19937& gen) {
	foo.odd([&](int i) {
		this_thread::sleep_for(chrono::duration<int, milli>(10 + gen() % 200));
		cout << i;
	});
}

int main()
{
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());  // to seed mersenne twister.

	for (int i = 0; i < 10; ++i) {
		ZeroEvenOdd zeroEvenOdd(3);

		thread t1(threadA, ref(zeroEvenOdd), ref(gen)), t2(threadB, ref(zeroEvenOdd), ref(gen)), t3(threadC, ref(zeroEvenOdd), ref(gen));

		t1.join();
		t2.join();
		t3.join();

		cout << endl;
	}

    return 0;
}

