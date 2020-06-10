
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
[1,3,1],
[1,5,1],
[4,2,1]
]
Output: 7
Explanation: Because the path 1?3?1?1?1 minimizes the sum.
*/

//Runtime: 24 ms, faster than 10.78% of C++ online submissions for Minimum Path Sum.
//Memory Usage : 10.1 MB, less than 100.00% of C++ online submissions for Minimum Path Sum.
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		const size_t n = grid.size();
		const size_t m = grid[0].size();

		vector<vector<int>> dp(n, vector<int>(m));

		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < m; ++j) {
				if (!i && !j) {
					dp[i][j] = grid[i][j];
					continue;
				}
				int v = numeric_limits<int>::max();
				if (i > 0)
					v = min(v, dp[i - 1][j]);
				if (j > 0)
					v = min(v, dp[i][j - 1]);
				dp[i][j] = v + grid[i][j];
			}
		}

		return dp[n - 1][m - 1];
	}
};

int main()
{
	cout << Solution().minPathSum(vector<vector<int>> {
		{ 1, 3, 1 },
		{ 1, 5, 1 },
		{ 4, 2, 1 }
	}) << endl; // 7

    return 0;
}

