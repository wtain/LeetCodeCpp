
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/super-ugly-number/

Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.

Example:

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12
super ugly numbers given primes = [2,7,13,19] of size 4.
Note:

1 is a super ugly number for any given primes.
The given numbers in primes are in ascending order.
0 < k ? 100, 0 < n ? 106, 0 < primes[i] < 1000.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

*/

class Solution {
public:

	int nthSuperUglyNumber(int n, vector<int>& primes)
	{
		vector<int> values;
		vector<int> iters(primes.size(), 0);
		values.push_back(1);
		while (--n)
		{
			int next = values[iters[0]] * primes[0];
			int idx = 0;
			for (int i = 1; i < primes.size(); ++i)
			{
				int next1 = values[iters[i]] * primes[i];
				if (next1 < next)
				{
					next = next1;
					idx = i;
				}
			}
			for (int i = 0; i < primes.size(); ++i)
			{
				int next1 = values[iters[i]] * primes[i];
				if (next1 == next)
					++iters[i];
			}
			values.push_back(next);
		}
		return values.back();
	}
};

int main()
{
	vector<int> primes = { 2,7,13,19 };
	cout << boolalpha << Solution().nthSuperUglyNumber(12, primes) << endl;
	/*vector<int> primes = { 2,3,5 };
	cout << boolalpha << Solution().nthSuperUglyNumber(10, primes) << endl; */

	return 0;
}

