
#include <iostream>

using namespace std;

/*
https://leetcode.com/problems/divide-two-integers/

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [?231,  231 ? 1]. For the purpose of this problem, assume that your function returns 231 ? 1 when the division result overflows.

*/

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (!divisor || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;
		if (dividend == INT_MIN && divisor == 1)
			return INT_MIN;

		int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

		long long dvd = labs(dividend);
		long long dvs = labs(divisor);

		int rv = 0;
		while (dvd >= dvs)
		{
			long long t = dvs;
			long long multiple = 1;
			while (dvd >= (t << 1))
			{
				t <<= 1;
				multiple <<= 1;
			}
			dvd -= t;
			rv += multiple;
		}
		return sign > 0 ? rv : -rv;
	}
};

int main()
{
	cout << Solution().divide(10, 3) << endl; // 3
	cout << Solution().divide(7, -3) << endl; // -2

    return 0;
}

