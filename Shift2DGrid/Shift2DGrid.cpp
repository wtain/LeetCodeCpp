
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/shift-2d-grid/

Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.



Example 1:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]
Example 2:


Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
Example 3:

Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]


Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 50
1 <= n <= 50
-1000 <= grid[i][j] <= 1000
0 <= k <= 100

*/

//Runtime: 44 ms, faster than 83.73% of C++ online submissions for Shift 2D Grid.
//Memory Usage : 14.1 MB, less than 53.47% of C++ online submissions for Shift 2D Grid.
//class Solution {
//public:
//	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
//		const int n = grid.size();
//		if (!n)
//			return{};
//		const int m = grid[0].size();
//		vector<vector<int>> result(n, vector<int>(m));
//
//		int nm = n * m;
//
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < m; ++j) {
//				int ij = i * m + j;
//				int ij1 = (ij + k) % nm;
//
//				int i1 = ij1 / m;
//				int j1 = ij1 % m;
//
//				result[i1][j1] = grid[i][j];
//			}
//		}
//
//		return result;
//	}
//};

// in-place!

//Runtime: 56 ms, faster than 46.41% of C++ online submissions for Shift 2D Grid.
//Memory Usage : 13.8 MB, less than 99.67% of C++ online submissions for Shift 2D Grid.
class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		const int n = grid.size();
		if (!n)
			return{};
		const int m = grid[0].size();

		int nm = n * m;
		int cnt = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int ij = i * m + j;
				int ij1 = (ij + k) % nm;

				int v = grid[i][j];

				while (ij1 != ij) {

					int i1 = ij1 / m;
					int j1 = ij1 % m;

					swap(grid[i1][j1], v);
					++cnt;

					ij1 = (ij1 + k) % nm;
				}

				grid[i][j] = v;
				++cnt;

				if (cnt == nm)
					return grid;
			}
		}

		return grid;
	}
};

void print(const vector<vector<int>>& m) {
	for (const auto& r : m) {
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << endl;
}

int main()
{
	print(Solution().shiftGrid(vector<vector<int>>{
		{1, 2, 3}, 
		{ 4,5,6 }, 
		{ 7,8,9 }
	}, 1)); // [[9,1,2],[3,4,5],[6,7,8]]

	print(Solution().shiftGrid(vector<vector<int>>{ {3, 8, 1, 9}, { 19,7,2,5 }, { 4,6,11,10 }, { 12,0,21,13 }}, 4)); // [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

	print(Solution().shiftGrid(vector<vector<int>>{ {1, 2, 3},
	{ 4,5,6 },
	{ 7,8,9 }}, 9)); // [[1,2,3],[4,5,6],[7,8,9]]

	print(Solution().shiftGrid(vector<vector<int>>{ {1, 2, 3},
	{ 4,5,6 },
	{ 7,8,9 }}, 19)); // [[9,1,2],[3,4,5],[6,7,8]]

	print(Solution().shiftGrid(vector<vector<int>>{ {1, 2, 3},
	{ 4,5,6 },
	{ 7,8,9 }}, 18)); // [[1,2,3],[4,5,6],[7,8,9]]

	print(Solution().shiftGrid(vector<vector<int>>{ {1, 2, 3},
	{ 4,5,6 },
	{ 7,8,9 }}, 10)); // [[9,1,2],[3,4,5],[6,7,8]]

	print(Solution().shiftGrid(vector<vector<int>>{ {1, 2, 3},
	{ 4,5,6 },
	{ 7,8,9 }}, 2)); // [[8,9,1],[2,3,4],[5,6,7]]

    return 0;
}

