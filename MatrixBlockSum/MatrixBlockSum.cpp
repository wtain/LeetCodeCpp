
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/matrix-block-sum/

Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.


Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n, K <= 100
1 <= mat[i][j] <= 100

*/

//Runtime: 24 ms, faster than 37.46% of C++ online submissions for Matrix Block Sum.
//Memory Usage : 9.6 MB, less than 42.42% of C++ online submissions for Matrix Block Sum.
class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
		const int n = mat.size();
		if (!n)
			return{};
		const int m = mat[0].size();

		vector<vector<int>> result(n, vector<int>(m));
		vector<vector<int>> sums(n+1, vector<int>(m+1));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int s00 = sums[i][j];
				int s01 = sums[i][j + 1];
				int s10 = sums[i + 1][j];

				sums[i+1][j+1] = s01 + s10 - s00 + mat[i][j];
			}
		}

		for (int i = 0; i < n; ++i) {
			int i1 = max(i - K, 0);
			int i2 = min(i + K + 1, n);
			for (int j = 0; j < m; ++j) {
				int j1 = max(j - K, 0);
				int j2 = min(j + K + 1, m);
				result[i][j] = sums[i2][j2] + sums[i1][j1] - sums[i1][j2] - sums[i2][j1];
			}
		}

		return result;
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
	print(Solution().matrixBlockSum(vector<vector<int>>{ {1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 } }, 1));
	print(Solution().matrixBlockSum(vector<vector<int>>{ {1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 } }, 2));

    return 0;
}

