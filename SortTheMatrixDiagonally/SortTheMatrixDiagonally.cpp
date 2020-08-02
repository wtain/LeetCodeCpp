
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/sort-the-matrix-diagonally/

Given a m * n matrix mat of integers, sort it diagonally in ascending order from the top-left to the bottom-right then return the sorted array.



Example 1:


Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100

*/

//Runtime: 16 ms, faster than 97.84% of C++ online submissions for Sort the Matrix Diagonally.
//Memory Usage : 9.4 MB, less than 53.85% of C++ online submissions for Sort the Matrix Diagonally.
class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		const auto n = mat.size();
		const auto m = mat[0].size();
		const int d = n + m - 1;
		const int v = 100 + 1;
		//vector<vector<int>> counts(d, vector<int>(v));
		int i0 = n - 1, j0 = 0;
	
		vector<vector<int>> result(n, vector<int>(m));
		for (int i = 0; i < d; ++i) {
			vector<int> counts(v);
			int i1 = i0, j1 = j0;
			while (i1 < n && j1 < m)
				counts[mat[i1++][j1++]]++;

			i1 = i0, j1 = j0;
			int k = 0;
			while (i1 < n && j1 < m) {
				while (!counts[k])
					++k;
				result[i1++][j1++] = k;
				counts[k]--;
			}

			if (i0 == 0)
				j0++;
			else
				i0--;
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
	print(Solution().diagonalSort(vector<vector<int>>{
		{3, 3, 1, 1}, 
		{ 2,2,1,2 }, 
		{ 1,1,1,2 }
	}));
	/*
	[
		[1,1,1,1],
		[1,2,2,2],
		[1,2,3,3]
	]
	*/

    return 0;
}

