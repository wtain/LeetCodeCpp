
#include <iostream>
#include <vector>

using namespace std;

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
[0,0,0],
[0,1,0],
[0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

//Runtime: 4 ms, faster than 95.27% of C++ online submissions for Unique Paths II.
//Memory Usage : 7.9 MB, less than 61.46% of C++ online submissions for Unique Paths II.
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const auto m = obstacleGrid.size();
		const auto n = obstacleGrid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, 0));

		if (obstacleGrid[0][0] == 0)
			dp[0][0] = 1;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (obstacleGrid[i][j] == 1) {
					dp[i][j] = 0;
					continue;
				}
				if (i == 0 && j == 0)
					continue;
				int n1 = 0, n2 = 0;
				if (i > 0)
					n1 = dp[i - 1][j];
				if (j > 0)
					n2 = dp[i][j - 1];
				dp[i][j] = n1 + n2;
			}
		}

		return dp[m - 1][n - 1];
	}
};

int main()
{
	cout << Solution().uniquePathsWithObstacles(vector<vector<int>>{
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 0 }
	}) << endl; // 2

	cout << Solution().uniquePathsWithObstacles(vector<vector<int>>{
		{ 1, 0 }
	}) << endl; // 0


    return 0;
}

