
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/sum-of-square-numbers/

Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5


Example 2:

Input: 3
Output: False
*/

/*
Runtime: 156 ms, faster than 8.79% of C++ online submissions for Sum of Square Numbers.
Memory Usage: 10.2 MB, less than 16.67% of C++ online submissions for Sum of Square Numbers.
156 ms	10.2 MB
*/
//class Solution {
//public:
//	bool judgeSquareSum(int c) {
//		int s = sqrt(c);
//		vector<int> squares;
//		squares.resize(s + 1);
//		for (int i = 0; i <= s; ++i)
//			squares[i] = i*i;
//
//		++s;
//		for (int i = 0; i < s; ++i) {
//			int a = squares[i];
//			int b = c - a;
//			if (binary_search(begin(squares) + i, end(squares), b))
//				return true;
//		}
//		return false;
//	}
//};

/*
Runtime: 8 ms, faster than 24.68% of C++ online submissions for Sum of Square Numbers.
Memory Usage: 10.1 MB, less than 16.67% of C++ online submissions for Sum of Square Numbers.
Accepted	8 ms
*/
//class Solution {
//public:
//	bool judgeSquareSum(int c) {
//		int s = sqrt(c);
//		vector<int> squares;
//		squares.resize(s + 1);
//		for (int i = 0; i <= s; ++i)
//			squares[i] = i*i;
//
//		++s;
//		for (int i = 0; i < s; ++i) {
//			int a = squares[i];
//			int b = c - a;
//			int bs = sqrt(b);
//			if (bs*bs == b)
//				return true;
//		}
//		return false;
//	}
//};

/*
Runtime: 4 ms, faster than 64.84% of C++ online submissions for Sum of Square Numbers.
Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Sum of Square Numbers.
4 ms	6 MB
*/
class Solution {
public:
	bool judgeSquareSum(int c) {
		if (!c)
			return true;
		for (unsigned int i = 0; i < c; ++i) {
			unsigned a = i*i;
			if (a > c)
				return false;
			unsigned b = c - a;
			unsigned bs = sqrt(b);
			if (bs*bs == b)
				return true;
		}
		return false;
	}
};

int main()
{
	cout << boolalpha << Solution().judgeSquareSum(5) << endl; // true
	cout << boolalpha << Solution().judgeSquareSum(3) << endl; // false
	cout << boolalpha << Solution().judgeSquareSum(0) << endl; // true
	cout << boolalpha << Solution().judgeSquareSum(2147482647) << endl; // ???

    return 0;
}

