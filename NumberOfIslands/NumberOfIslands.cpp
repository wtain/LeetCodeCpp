
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/number-of-islands/

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

//Runtime: 32 ms, faster than 16.73% of C++ online submissions for Number of Islands.
//Memory Usage : 10 MB, less than 100.00% of C++ online submissions for Number of Islands.
//Runtime: 28 ms, faster than 25.18% of C++ online submissions for Number of Islands.
//Memory Usage : 9.9 MB, less than 100.00% of C++ online submissions for Number of Islands.
class Solution {
public:

	void mark(vector<vector<char>>& grid, const size_t i0, const size_t j0, const size_t n, const size_t m) {
		stack<pair<size_t, size_t>> toProcess;
		toProcess.emplace(i0, j0);
		while (!toProcess.empty()) {
			const auto p = toProcess.top();
			toProcess.pop();
			grid[p.first][p.second] = '0';
			if (p.first > 0 && grid[p.first-1][p.second] == '1')
				toProcess.emplace(p.first - 1, p.second);
			if (p.second > 0 && grid[p.first][p.second - 1] == '1')
				toProcess.emplace(p.first, p.second - 1);
			if (p.first < n-1 && grid[p.first + 1][p.second] == '1')
				toProcess.emplace(p.first + 1, p.second);
			if (p.second < m-1 && grid[p.first][p.second + 1] == '1')
				toProcess.emplace(p.first, p.second + 1);
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;
		int cnt = 0;

		const size_t n = grid.size();
		const size_t m = grid[0].size();

		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < m; ++j) {
				if (grid[i][j] == '1') {
					++cnt;
					mark(grid, i, j, n, m);
				}
			}
		}

		return cnt;
	}
};

//Runtime: 28 ms, faster than 25.18% of C++ online submissions for Number of Islands.
//Memory Usage : 9.6 MB, less than 100.00% of C++ online submissions for Number of Islands.
//Runtime: 24 ms, faster than 30.40% of C++ online submissions for Number of Islands.
//Memory Usage : 9.8 MB, less than 100.00% of C++ online submissions for Number of Islands.
//class Solution {
//public:
//
//	int numIslands(vector<vector<char>>& grid) {
//		if (grid.empty())
//			return 0;
//		int cnt = 0;
//		stack<pair<size_t, size_t>> toProcess;
//
//		const size_t n = grid.size();
//		const size_t m = grid[0].size();
//
//		for (size_t i = 0; i < n; ++i) {
//			for (size_t j = 0; j < m; ++j) {
//				if (grid[i][j] == '1') {
//					++cnt;
//					toProcess.emplace(i, j);
//					while (!toProcess.empty()) {
//						const auto p = toProcess.top();
//						toProcess.pop();
//						grid[p.first][p.second] = '0';
//						if (p.first > 0 && grid[p.first - 1][p.second] == '1')
//							toProcess.emplace(p.first - 1, p.second);
//						if (p.second > 0 && grid[p.first][p.second - 1] == '1')
//							toProcess.emplace(p.first, p.second - 1);
//						if (p.first < n - 1 && grid[p.first + 1][p.second] == '1')
//							toProcess.emplace(p.first + 1, p.second);
//						if (p.second < m - 1 && grid[p.first][p.second + 1] == '1')
//							toProcess.emplace(p.first, p.second + 1);
//					}
//				}
//			}
//		}
//
//		return cnt;
//	}
//};

// DOESN'T WORK
//class Solution {
//public:
//
//	int numIslands(vector<vector<char>>& grid) {
//		if (grid.empty())
//			return 0;
//
//		const size_t n = grid.size();
//		const size_t m = grid[0].size();
//
//		vector<vector<int>> mark(n, vector<int>(m));
//		size_t cnt = 0;
//		size_t lastMark = 0;
//
//		for (size_t i = 0; i < n; ++i) {
//			for (size_t j = 0; j < m; ++j) {
//				if (grid[i][j] == '1') {
//					bool has1 = i > 0 && grid[i - 1][j] == '1';
//					bool has2 = j > 0 && grid[i][j - 1] == '1';
//					if (has1 && has2) {
//						if (mark[i - 1][j] == mark[i][j-1])
//							mark[i][j] = mark[i - 1][j];
//						else {
//							mark[i][j] = min(mark[i - 1][j], mark[i][j - 1]);
//							--cnt;
//						}
//					}
//					else if (has1) {
//						mark[i][j] = mark[i-1][j];
//					}
//					else if (has2) {
//						mark[i][j] = mark[i][j-1];
//					}
//					else if (!has1 && !has2) {
//						mark[i][j] = ++lastMark;
//						++cnt;
//					}
//				}
//			}
//		}
//
//		return cnt;
//	}
//};

int main()
{
	cout << Solution().numIslands(vector<vector<char>> 
	{ 
		{ '1', '1', '1', '1', '0'},
		{ '1', '1', '0', '1', '0'},
		{ '1', '1', '0', '0', '0' },
		{ '0', '0', '0', '0', '0' }
	}) << endl; // 1

	cout << Solution().numIslands(vector<vector<char>>
	{
		{ '1', '1', '0', '0', '0'},
		{ '1', '1', '0', '0', '0' },
		{ '0', '0', '1', '0', '0' },
		{ '0', '0', '0', '1', '1' }
	}) << endl; // 3

	cout << Solution().numIslands(vector<vector<char>>
	{
		{ '1', '1', '1' },
		{ '0', '1', '0' },
		{ '1', '1', '1' }
	}) << endl; // 1

	/*[["1", "1", "1", "1", "1", "1", "1"], 
	["0", "0", "0", "0", "0", "0", "1"], 
		["1", "1", "1", "1", "1", "0", "1"], 
		["1", "0", "0", "0", "1", "0", "1"], 
		["1", "0", "1", "0", "1", "0", "1"], 
		["1", "0", "1", "1", "1", "0", "1"], 
		["1", "1", "1", "1", "1", "1", "1"]]
	expected 1*/

    return 0;
}

