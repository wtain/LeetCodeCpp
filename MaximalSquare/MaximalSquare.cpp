
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/maximal-square/

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

//Runtime: 44 ms, faster than 24.63% of C++ online submissions for Maximal Square.
//Memory Usage : 11.7 MB, less than 7.41% of C++ online submissions for Maximal Square.
//class Solution {
//public:
//	int maximalSquare(vector<vector<char>>& matrix) {
//		size_t n = matrix.size();
//		if (!n)
//			return 0;
//		size_t m = matrix[0].size();
//		vector<vector<int>> dp(n, vector<int>(m));
//
//		int maxSize = 0;
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < m; ++j) {
//				if (matrix[i][j] != '1')
//					continue;
//
//				if (i > 0 && j > 0)
//					dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
//				else 
//					dp[i][j] = 1;
//
//				maxSize = max(maxSize, dp[i][j]);
//			}
//		}
//		return maxSize * maxSize;
//	}
//};

//Runtime: 44 ms, faster than 24.63% of C++ online submissions for Maximal Square.
//Memory Usage : 11.2 MB, less than 48.15% of C++ online submissions for Maximal Square.
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		size_t n = matrix.size();
		if (!n)
			return 0;
		size_t m = matrix[0].size();
		vector<int> dp(m+1);

		int maxSize = 0, prev = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				int temp = dp[j];
				if (matrix[i - 1][j - 1] == '1') {
					dp[j] = min(min(dp[j - 1], dp[j]), prev) + 1;
					maxSize = max(maxSize, dp[j]);
				}
				else
				{
					dp[j] = 0;
				}
				prev = temp;
			}
		}
		return maxSize * maxSize;
	}
};

int main()
{
	cout << Solution().maximalSquare(vector<vector<char>>
	{
		{ '1', '0', '1', '0', '0' },
		{ '1', '0', '1', '1', '1' },
		{ '1', '1', '1', '1', '1' },
		{ '1', '0', '0', '1', '0' }
	}) << endl; // 4

	cout << Solution().maximalSquare(vector<vector<char>>{}) << endl; // 0

    return 0;
}

