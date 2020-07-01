
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?



Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28


Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.

*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
//Memory Usage : 6.7 MB, less than 6.75% of C++ online submissions for Unique Paths.
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 1));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!i || !j)
					continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[m - 1][n - 1];
	}
};

int main()
{
	cout << Solution().uniquePaths(3, 2) << endl; // 3
	cout << Solution().uniquePaths(7, 3) << endl; // 28
	cout << Solution().uniquePaths(10, 10) << endl; // 48620
	// cout << Solution().uniquePaths(100, 100) << endl; // INVALID
	// cout << Solution().uniquePaths(50, 50) << endl; // INVALID
	cout << Solution().uniquePaths(1, 100) << endl; // 1

    return 0;
}

