
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/count-numbers-with-unique-digits/

Given a non-negative integer n, count all numbers with unique digits, x, where 0 ? x < 10n.

Example:

Input: 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ? x < 100,
excluding 11,22,33,44,55,66,77,88,99


Constraints:

0 <= n <= 8

*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Numbers with Unique Digits.
//Memory Usage : 6.2 MB, less than 5.48% of C++ online submissions for Count Numbers with Unique Digits.
class Solution {
	vector<int> fact;
	vector<int> result;
public:

	Solution() {
		fact.resize(10);
		fact[0] = 1;
		for (size_t i = 1; i < 10; ++i)
			fact[i] = i * fact[i - 1]; // We put DP into your DP

		result.resize(9);
		result[0] = 1;
		for (size_t i = 1; i < 9; ++i)
			result[i] = result[i - 1] + 9 * fac(9) / fac(10 - i);
	}

	int fac(int i) {
		return fact[i];
	}

	int countNumbersWithUniqueDigits(int n) {
		return result[n];
	}
};

int main()
{
	cout << Solution().countNumbersWithUniqueDigits(0) << endl; // 1
	cout << Solution().countNumbersWithUniqueDigits(1) << endl; // 10
	cout << Solution().countNumbersWithUniqueDigits(2) << endl; // 91
	cout << Solution().countNumbersWithUniqueDigits(3) << endl; // 739
	cout << Solution().countNumbersWithUniqueDigits(4) << endl; // ?


    return 0;
}

