
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/fibonacci-number/

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).



Example 1:

Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.


Note:

0 ? N ? 30.

Accepted
*/

class Solution {
public:
	int fib(int N) {
		static vector<int> numbers;
		if (numbers.empty()) {
			numbers.resize(30 + 1);
			numbers[0] = 0;
			numbers[1] = 1;
			for (int i = 2; i <= 30; ++i)
				numbers[i] = numbers[i - 1] + numbers[i - 2];
		}
		return numbers[N];
	}
};

int main()
{
	cout << Solution().fib(2) << endl; // 1
	cout << Solution().fib(3) << endl; // 2
	cout << Solution().fib(4) << endl; // 3

    return 0;
}

