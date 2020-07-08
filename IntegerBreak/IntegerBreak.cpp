
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
https://leetcode.com/problems/integer-break/

Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 ? 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 ? 3 ? 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.

*/

// #pragma message("!!!!!!!!!!!!!!!!!!!!!!!! Not solved problem, MEDIUM")

//Runtime: 4 ms, faster than 17.50% of C++ online submissions for Integer Break.
//Memory Usage : 6 MB, less than 78.11% of C++ online submissions for Integer Break.
//class Solution {
//public:
//	int integerBreak(int n) {
//		const int nmax = 58 + 1;
//		vector<int> dp(nmax);
//		for (int i = 2; i < nmax; ++i) {
//			for (int j = 1; j < i; ++j) {
//				dp[i] = max(dp[i], j * (i - j));
//				dp[i] = max(dp[i], j * dp[i - j]);
//			}
//		}
//		return dp[n];
//	}
//};

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Integer Break.
//Memory Usage : 6.4 MB, less than 11.80% of C++ online submissions for Integer Break.
//class Solution {
//public:
//	int integerBreak(int n) {
//		vector<int> dp(n + 1);
//		for (int i = 2; i < n + 1; ++i) {
//			for (int j = 1; j < i; ++j) {
//				dp[i] = max(dp[i], j * (i - j));
//				dp[i] = max(dp[i], j * dp[i - j]);
//			}
//		}
//		return dp[n];
//	}
//};

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Integer Break.
//Memory Usage : 6.2 MB, less than 31.98% of C++ online submissions for Integer Break.
class Solution {
public:
	int integerBreak(int n) {
		vector<int> trivial = { 0, 1, 1, 2, 4 };
		if (n < trivial.size())
			return trivial[n];
		switch (n % 3) {
		case 0:
			return pow(3, n / 3);
		case 1:
			return 2 * 2 * pow(3, (n-4) / 3);
		case 2:
			return 2 * pow(3, (n - 2) / 3);
		}
		return 0;
	}
};

int main()
{
	cout << Solution().integerBreak(2) << endl; // 1
	cout << Solution().integerBreak(10) << endl; // 36

    return 0;
}

