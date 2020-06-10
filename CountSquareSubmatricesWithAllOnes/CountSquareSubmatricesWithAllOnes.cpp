
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/
https://leetcode.com/problems/count-square-submatrices-with-all-ones/

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.



Example 1:

Input: matrix =
[
[0,1,1,1],
[1,1,1,1],
[0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix =
[
[1,0,1],
[1,1,0],
[1,1,0]
]
Output: 7
Explanation:
There are 6 squares of side 1.
There is 1 square of side 2.
Total number of squares = 6 + 1 = 7.


Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
Hide Hint #1
Create an additive table that counts the sum of elements of submatrix with the superior corner at (0,0).
Hide Hint #2
Loop over all subsquares in O(n^3) and check if the sum make the whole array to be ones, if it checks then add 1 to the answer.

*/

//Runtime: 1412 ms
//Memory Usage : 26.6 MB
//class Solution {
//public:
//	int countSquares(vector<vector<int>>& matrix) {
//		const size_t n = matrix.size();
//		const size_t m = matrix[0].size();
//
//		vector<vector<int>> sums(n, vector<int>(m));
//
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < m; ++j) {
//				int sum = matrix[i][j];
//				if (i > 0 && j > 0)
//					sum -= sums[i-1][j-1];
//				if (i > 0)
//					sum += sums[i - 1][j];
//				if (j > 0)
//					sum += sums[i][j - 1];
//				sums[i][j] = sum;
//			}
//		}
//
//		int s = min(n, m);
//
//		int cnt = sums[n - 1][m - 1];
//		for (int k = 2; k <= s; ++k) {
//			int k2 = k * k;
//
//			for (int i = k-1; i < n; ++i) {
//				for (int j = k-1; j < m; ++j) {
//					int sum = sums[i][j];
//					int i1 = i - k, j1 = j - k;
//					if (i1 >= 0 && j1 >= 0)
//						sum += sums[i1][j1];
//					if (i1 >= 0)
//						sum -= sums[i1][j];
//					if (j1 >= 0)
//						sum -= sums[i][j1];
//					if (sum == k2)
//						++cnt;
//				}
//			}
//		}
//
//		return cnt;
//	}
//};

//class Solution {
//public:
//	int countSquares(vector<vector<int>>& matrix) {
//		const size_t n = matrix.size();
//		const size_t m = matrix[0].size();
//
//		vector<int> sums1(n);
//		vector<int> sums2(m);
//
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < m; ++j) {
//				sums1[i] += matrix[i][j];
//				sums2[j] += matrix[i][j];
//			}
//		}
//
//		int cnt = 0;
//
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < m; ++j) {
//			}
//		}
//
//		return cnt;
//	}
//};

//Runtime: 264 ms
//Memory Usage : 26.3 MB
class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		const size_t n = matrix.size();
		const size_t m = matrix[0].size();

		vector<vector<int>> dp(n, vector<int>(m));

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (matrix[i][j] != 1)
					continue;

				if (!i || !j) {
					dp[i][j] = 1;
					++cnt;
					continue;
				}

				int val = numeric_limits<int>::max();

				if (i > 0 && j > 0)
					val = min(val, dp[i - 1][j - 1]);
				if (i > 0)
					val = min(val, dp[i - 1][j]);
				if (j > 0)
					val = min(val, dp[i][j - 1]);

				dp[i][j] = val + 1;

				cnt += dp[i][j];
			}
		}

		return cnt;
	}
};

int main()
{
	cout << Solution().countSquares(vector<vector<int>>{
		{ 0, 1, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 0, 1, 1, 1 }
	}) << endl; // 15

	cout << Solution().countSquares(vector<vector<int>>{
		{ 1, 0, 1 },
		{ 1, 1, 0 },
		{ 1, 1, 0 }
	}) << endl; // 7

    return 0;
}

