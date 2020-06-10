
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/reshape-the-matrix/

In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input:
nums =
[[1,2],
[3,4]]
r = 1, c = 4
Output:
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input:
nums =
[[1,2],
[3,4]]
r = 2, c = 4
Output:
[[1,2],
[3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.

*/

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int n = nums.size();
		int m = nums[0].size();
		if (n*m != r*c)
			return nums;

		int a = 0, b = 0;

		vector<vector<int>> result;
		result.resize(r);
		for (int i = 0; i < r; ++i) {
			result[i].resize(c);
			for (int j = 0; j < c; ++j) {
				result[i][j] = nums[a][b++];
				if (b == m) {
					b = 0;
					++a;
				}
			}
		}
		return result;
	}
};

void printMatrix(const vector<vector<int>>& v) {
	for (const auto& row : v) {
		copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << endl;
}

int main()
{
	{
		vector<vector<int>> m = { 
			{1, 2}, 
			{3, 4} 
		};
		auto r = Solution().matrixReshape(m, 1, 4);
		printMatrix(r); // 1 2 3 4
	}
	
	{
		vector<vector<int>> m = {
			{ 1, 2 },
			{ 3, 4 }
		};
		auto r = Solution().matrixReshape(m, 2, 4);
		printMatrix(r);
		/*
			{ 1, 2 },
			{ 3, 4 }
		*/
	}
    return 0;
}

