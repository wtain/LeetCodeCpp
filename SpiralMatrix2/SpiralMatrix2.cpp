
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/spiral-matrix-ii/

59. Spiral Matrix II
Medium

873

105

Add to List

Share
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*/

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {

		vector<vector<int>> result(n, vector<int>(n));

		int i = 0, j = 0;
		int state = n > 1 ? 0 : 1; // right down left up
		int i1 = 0, i2 = n - 1;
		int j1 = 0, j2 = n - 1;

		for (int k = 0; k < n*n; ++k) {
			result[i][j] = k+1;
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

void printMatrix(const vector<vector<int>>& m) {
	for (const auto& row : m) {
		copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}

int main()
{
	printMatrix(Solution().generateMatrix(3));
	/*
	[ 1, 2, 3 ],
	[ 8, 9, 4 ],
	[ 7, 6, 5 ]
	*/
	printMatrix(Solution().generateMatrix(1));
	printMatrix(Solution().generateMatrix(0));
    return 0;
}

