
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/rotting-oranges/
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3418/
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.



Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.


Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/

//Runtime: 8 ms, faster than 96.13% of C++ online submissions for Rotting Oranges.
//Memory Usage : 12.9 MB, less than 93.66% of C++ online submissions for Rotting Oranges.
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		const int n = grid.size();
		const int m = grid[0].size();
		const int BigValue = n * m + 1;
		vector<vector<int>> dist(n, vector<int>(m, BigValue));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 2)
					dist[i][j] = 0;
			}
		}
		bool changesMade = true;
		while (changesMade) {
			changesMade = false;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (!grid[i][j])
						continue;
					const auto dij = dist[i][j];
					if (i > 0 && grid[i - 1][j] == 2) {
						grid[i][j] = 2;
						dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
					}
					if (j > 0 && grid[i][j - 1] == 2) {
						grid[i][j] = 2;
						dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
					}
					if (i < n-1 && grid[i + 1][j] == 2) {
						grid[i][j] = 2;
						dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
					}
					if (j < m-1 && grid[i][j + 1] == 2) {
						grid[i][j] = 2;
						dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
					}
					if (dist[i][j] != dij)
						changesMade = true;
				}
			}
		}
		int maxDist = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 1)
					return -1;
				else if (grid[i][j] == 0)
					continue;
				maxDist = max(maxDist, dist[i][j]);
			}
		}
		return maxDist;
	}
};

int main()
{
	cout << Solution().orangesRotting(vector<vector<int>>{
		{2, 1, 1}, 
		{ 1, 1, 0 }, 
		{ 0, 1, 1 }
	}) << endl; // 4

	cout << Solution().orangesRotting(vector<vector<int>>{
		{2, 1, 1}, 
		{ 0, 1, 1 }, 
		{ 1, 0, 1 }
	}) << endl; // -1

	cout << Solution().orangesRotting(vector<vector<int>>{
		{0, 2 }
	}) << endl; // 0

    return 0;
}

