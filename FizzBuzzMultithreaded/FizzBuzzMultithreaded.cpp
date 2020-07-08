
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
https://leetcode.com/problems/fizz-buzz-multithreaded/

Write a program that outputs the string representation of numbers from 1 to n, however:

If the number is divisible by 3, output "fizz".
If the number is divisible by 5, output "buzz".
If the number is divisible by both 3 and 5, output "fizzbuzz".
For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz.

Suppose you are given the following code:

class FizzBuzz {
public FizzBuzz(int n) { ... }               // constructor
public void fizz(printFizz) { ... }          // only output "fizz"
public void buzz(printBuzz) { ... }          // only output "buzz"
public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
public void number(printNumber) { ... }      // only output the numbers
}
Implement a multithreaded version of FizzBuzz with four threads. The same instance of FizzBuzz will be passed to four different threads:

Thread A will call fizz() to check for divisibility of 3 and outputs fizz.
Thread B will call buzz() to check for divisibility of 5 and outputs buzz.
Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and outputs fizzbuzz.
Thread D will call number() which should only output the numbers.

*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fizz Buzz Multithreaded.
//Memory Usage : 7 MB, less than 21.01% of C++ online submissions for Fizz Buzz Multithreaded.
class FizzBuzz {
public:

	enum State {
		StateNumber,
		StateFizz,
		StateBuzz,
		StateFizzBuzz,
		StateFinished
	};

private:
	int n;
	mutex m;
	condition_variable cv;

	State state;
	int i;

public:
	FizzBuzz(int n) {
		this->n = n;
		state = StateNumber;
		i = 1;
	}

	// printFizz() outputs "fizz".
	void fizz(function<void()> printFizz) {
		run([&]() {printFizz(); }, State::StateFizz);
	}

	// printBuzz() outputs "buzz".
	void buzz(function<void()> printBuzz) {
		run([&]() {printBuzz(); }, State::StateBuzz);
	}

	// printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
		run([&]() {printFizzBuzz(); }, State::StateFizzBuzz);
	}

	// printNumber(x) outputs "x", where x is an integer.
	void number(function<void(int)> printNumber) {
		run([&]() {printNumber(i); }, State::StateNumber);
	}

private:

	void run(function<void()> print, State stateToProcess) {
		while (state != State::StateFinished) {
			unique_lock<mutex> lock(m);
			cv.wait(lock, [&] {return state == stateToProcess || state == State::StateFinished; });
			if (state == State::StateFinished)
				return;

			print();

			moveNextState();

			lock.unlock();
			cv.notify_all();
		}
	}

	void moveNextState() {
		++i;
		if (i > n)
			state = State::StateFinished;
		else if (i % 3 == 0 && i % 5 == 0)
			state = State::StateFizzBuzz;
		else if (i % 3 == 0)
			state = State::StateFizz;
		else if (i % 5 == 0)
			state = State::StateBuzz;
		else
			state = State::StateNumber;
	}
};

void randomSleep(mt19937& gen) {
	this_thread::sleep_for(chrono::duration<int, milli>(10 + gen() % 200));
}

void threadA(FizzBuzz& foo, mt19937& gen) {
	foo.fizz([&]() {
		randomSleep(gen);
		cout << "fizz ";
	});
}

void threadB(FizzBuzz& foo, mt19937& gen) {
	foo.buzz([&]() {
		randomSleep(gen);
		cout << "buzz ";
	});
}

void threadC(FizzBuzz& foo, mt19937& gen) {
	foo.fizzbuzz([&]() {
		randomSleep(gen);
		cout << "fizzbuzz ";
	});
}

void threadD(FizzBuzz& foo, mt19937& gen) {
	foo.number([&](int i) {
		randomSleep(gen);
		cout << i << " ";
	});
}

int main()
{
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());  // to seed mersenne twister.

	for (int i = 0; i < 10; ++i) {
		FizzBuzz fizzBuzz(15);

		thread t1(threadA, ref(fizzBuzz), ref(gen)), t2(threadB, ref(fizzBuzz), ref(gen)), t3(threadC, ref(fizzBuzz), ref(gen)), t4(threadD, ref(fizzBuzz), ref(gen));

		t1.join();
		t2.join();
		t3.join();
		t4.join();

		cout << endl;
	}

    return 0;
}

