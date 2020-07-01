
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/perfect-squares/

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/

// MEMORY LIMIT EXCEEDED?
//Runtime: 184 ms, faster than 71.95% of C++ online submissions for Perfect Squares.
//Memory Usage : 9 MB, less than 64.01% of C++ online submissions for Perfect Squares.
//class Solution {
//public:
//	int numSquares(int n) {
//		int ns = sqrt(n) + 1;
//		vector<int> dp(n + 1);
//		for (int i = 1; i <= n; ++i) {
//			int is = sqrt(i) + 1;
//			int cnt = numeric_limits<int>::max();
//			for (int j = 1; j <= is; ++j) {
//				int j2 = j * j;
//				int n1 = i - j2;
//				if (n1 < 0)
//					break;
//				cnt = min(cnt, dp[n1] + 1);
//			}
//			dp[i] = cnt;
//		}
//
//		return dp[n];
//	}
//};

//class Solution {
//public:
//	int numSquares(int n) {
//		int ns = sqrt(n) + 1;
//		vector<int> ss(ns + 1);
//		int cnt = 0;
//		for (int i = 1; i <= n; ++i) {
//			++ss[1];
//			++cnt;
//			for (int j = 1; j <= ns; ++j) {
//				int j12 = (j + 1) * (j + 1);
//				if (ss[j] == j12)
//			}
//		}
//
//		return cnt;
//	}
//};

//Runtime: 28 ms, faster than 92.08% of C++ online submissions for Perfect Squares.
//Memory Usage : 6.3 MB, less than 82.25% of C++ online submissions for Perfect Squares.
class Solution {
public:
	int numSquares(int n) {
		if (!n)
			return 0;
		int ns = sqrt(n) + 1;
		vector<int> r(ns + 1);
		for (int is = 1; is <= ns; ++is) {
			int is2 = is * is;
			if (is2 == n)
				return 1;
			r[is] = is2;
		}
		for (int i = 1; i <= ns; ++i) {
			int t = n - r[i];
			if (binary_search(begin(r), end(r), t))
				return 2;
		}
		for (int i = 1; i <= ns; ++i) {
			for (int j = 1; j <= ns; ++j) {
				int t = n - r[i] - r[j];
				if (binary_search(begin(r), end(r), t))
					return 3;
			}
		}
		return 4;
	}
};

int main()
{
	cout << Solution().numSquares(0) << endl; // 0

	cout << Solution().numSquares(12) << endl; // 3
	cout << Solution().numSquares(13) << endl; // 2

	cout << Solution().numSquares(10000) << endl; // 1

	cout << Solution().numSquares(1234567890) << endl; // 3

    return 0;
}

