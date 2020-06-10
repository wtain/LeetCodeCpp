
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/transpose-matrix/

Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.





Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]


Note:

1 <= A.length <= 1000
1 <= A[0].length <= 1000
*/

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		const int n = A.size();
		const int m = A[0].size();

		vector<vector<int>> result(m, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				result[j][i] = A[i][j];
			}
		}
		return result;
	}
};

void printMatrix(const vector<vector<int>>& m) {
	for (const auto& row : m) {
		copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << endl;
}

int main()
{
	printMatrix(Solution().transpose(vector<vector<int>>{{1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 } }));

    return 0;
}

