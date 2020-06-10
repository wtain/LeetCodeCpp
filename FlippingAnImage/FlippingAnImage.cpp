
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/flipping-an-image/

Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1
*/

class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		const int n = A.size();
		const int m = A[0].size();
		//const int m2 = m / 2;
		vector<vector<int>> result(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int j1 = m - 1 - j;
				result[i][j1] = 1 - A[i][j];
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
	printMatrix(Solution().flipAndInvertImage(vector<vector<int>>{ {1, 1, 0}, { 1, 0, 1 }, { 0, 0, 0 }}));
	/* 
		[
			[1,0,0],
			[0,1,0],
			[1,1,1]
		]
	*/

	cout << endl;

	printMatrix(Solution().flipAndInvertImage(vector<vector<int>>{ {1, 1, 0, 0}, { 1,0,0,1 }, { 0,1,1,1 }, { 1,0,1,0 } }));
	/* [
		[1,1,0,0],
		[0,1,1,0],
		[0,0,0,1],
		[1,0,1,0]]
	*/

    return 0;
}

