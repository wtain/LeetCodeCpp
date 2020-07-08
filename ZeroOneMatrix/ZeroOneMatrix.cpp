
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <queue>

using namespace std;

/*
https://leetcode.com/problems/01-matrix/

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.



Example 1:

Input:
[[0,0,0],
[0,1,0],
[0,0,0]]

Output:
[[0,0,0],
[0,1,0],
[0,0,0]]
Example 2:

Input:
[[0,0,0],
[0,1,0],
[1,1,1]]

Output:
[[0,0,0],
[0,1,0],
[1,2,1]]


Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.

*/

//Runtime: 168 ms, faster than 47.40% of C++ online submissions for 01 Matrix.
//Memory Usage : 31 MB, less than 33.53% of C++ online submissions for 01 Matrix.
//class Solution {
//public:
//
//	//struct IntPairHasher {
//
//	//	int operator() (const pair<int, int>& p) {
//	//		return p.first * 2000001 + p.second;
//	//	}
//
//	//};
//
//	/*if (i > 0 && (result[i - 1][j] = min(result[i - 1][j], 1)))
//		toVisit.emplace(i - 1, j);
//	if (i < n - 1 && (result[i + 1][j] = min(result[i + 1][j], 1)))
//		toVisit.emplace(i + 1, j);
//	if (j > 0 && (result[i][j - 1] = min(result[i][j - 1], 1)))
//		toVisit.emplace(i, j - 1);
//	if (j < m - 1 && (result[i][j + 1] = min(result[i][j + 1], 1)))
//		toVisit.emplace(i, j + 1);*/
//
//	void step(queue<pair<int, int>>& toVisit, int i, int j, vector<vector<int>>& result, const int newDist, const int n, const int m, const vector<vector<bool>>& visited) {
//		if (i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && result[i][j] > newDist) {
//			result[i][j] = newDist;
//			toVisit.emplace(i, j);
//		}
//	}
//
//	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//		const int n = matrix.size();
//		if (!n)
//			return{};
//		const int m = matrix[0].size();
//		const int bigval = n*m;
//		vector<vector<int>> result(n, vector<int>(m, bigval));
//		vector<vector<bool>> visited(n, vector<bool>(m, false));
//
//		//unordered_set<pair<int, int>, IntPairHasher> toVisit;
//		queue<pair<int, int>> toVisit;
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < m; ++j) {
//				if (!matrix[i][j]) {
//					result[i][j] = 0;
//					toVisit.emplace(i, j);
//				}
//			}
//		}
//
//		while (!toVisit.empty()) {
//			const auto p = toVisit.front();
//			toVisit.pop();
//			int i = p.first;
//			int j = p.second;
//			visited[i][j] = true;
//			int newDist = result[i][j] + 1;
//			step(toVisit, i - 1, j, result, newDist, n, m, visited);
//			step(toVisit, i + 1, j, result, newDist, n, m, visited);
//			step(toVisit, i, j - 1, result, newDist, n, m, visited);
//			step(toVisit, i, j + 1, result, newDist, n, m, visited);
//		}
//
//		return result;
//	}
//};

//Runtime: 156 ms, faster than 52.68% of C++ online submissions for 01 Matrix.
//Memory Usage : 26.4 MB, less than 78.65% of C++ online submissions for 01 Matrix.
class Solution {
public:

	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		if (!n)
			return{};
		const int m = matrix[0].size();
		const int bigval = n*m;
		vector<vector<int>> result(n, vector<int>(m, bigval));
	
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (!matrix[i][j]) {
					result[i][j] = 0;
				} else {
					if (i > 0)
						result[i][j] = min(result[i][j], result[i - 1][j] + 1);
					if (j > 0)
						result[i][j] = min(result[i][j], result[i][j - 1] + 1);
				}
			}
		}

		for (int i1 = 0; i1 < n; ++i1) {
			int i = n - 1 - i1;
			for (int j1 = 0; j1 < m; ++j1) {
				int j = m - 1 - j1;
				if (!matrix[i][j]) {
					result[i][j] = 0;
				}
				else {
					if (i1 > 0)
						result[i][j] = min(result[i][j], result[i + 1][j] + 1);
					if (j1 > 0)
						result[i][j] = min(result[i][j], result[i][j + 1] + 1);
				}
			}
		}

		return result;
	}
};

void print(const vector<vector<int>>& matrix) {
	for (const auto& row : matrix) {
		copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << endl;
}

int main()
{
	print(Solution().updateMatrix(vector<vector<int>>{
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 0 }
	}));
	/*[[0, 0, 0],
	[0, 1, 0],
	[0, 0, 0]]*/
	
	print(Solution().updateMatrix(vector<vector<int>>{
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 1, 1, 1 }
	}));
	/*[[0, 0, 0],
	[0, 1, 0],
	[1, 2, 1]]*/

    return 0;
}

