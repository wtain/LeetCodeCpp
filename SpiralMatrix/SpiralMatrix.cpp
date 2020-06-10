
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/spiral-matrix/

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
[1, 2, 3, 4],
[5, 6, 7, 8],
[9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		if (!n)
			return{};
		const int m = matrix[0].size();
		vector<int> result;
		result.reserve(n*m);

		int i = 0, j = 0;
		int state = m > 1 ? 0 : 1; // right down left up
		int i1 = 0, i2 = n - 1;
		int j1 = 0, j2 = m - 1;

		for (int k = 0; k < n*m; ++k) {
			result.push_back(matrix[i][j]);
			switch (state) {
			case 0:
				++j;
				if (j == j2) {
					state = i1 < i2 ? 1 : 2;
					++i1;
				}
				break;
			case 1:
				++i;
				if (i == i2) {
					state = j1 < j2 ? 2 : 3;
					j2--;
				}
				break;
			case 2:
				--j;
				if (j == j1) {
					state = i1 < i2 ? 3 : 0;
					i2--;
				}
				break;
			case 3:
				--i;
				if (i == i1) {
					state = j1 < j2 ? 0 : 1;
					j1++;
				}
				break;
			}
		}

		return result;
	}
};

int main()
{
	{
		auto r = Solution().spiralOrder(vector<vector<int>> {
			{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 }
		});
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // [1,2,3,6,9,8,7,4,5]
		cout << endl;
	}
	{
		auto r = Solution().spiralOrder(vector<vector<int>> {
			{ 1,  2,  3,  4},
			{ 5,  6,  7,  8 },
			{ 9, 10, 11, 12 }
		});
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // [1,2,3,4,8,12,11,10,9,5,6,7]
		cout << endl;
	}
	{
		auto r = Solution().spiralOrder(vector<vector<int>> {
			{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }
		});
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // [1, 2, 3, 4, 5, 6, 7, 8, 9]
		cout << endl;
	}
	{
		auto r = Solution().spiralOrder(vector<vector<int>> {
			{ 1 }, 
			{ 2 }, 
			{ 3 }, 
			{ 4 }, 
			{ 5 }, 
			{ 6 }, 
			{ 7 }, 
			{ 8 }, 
			{ 9 }
		});
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // [1, 2, 3, 4, 5, 6, 7, 8, 9]
		cout << endl;
	}
	{
		auto r = Solution().spiralOrder(vector<vector<int>>{});
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // []
		cout << endl;
	}
    return 0;
}

