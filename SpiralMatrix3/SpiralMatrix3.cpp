
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/spiral-matrix-iii/

On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.

Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

Now, we walk in a clockwise spiral shape to visit every position in this grid.

Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.)

Eventually, we reach all R * C spaces of the grid.

Return a list of coordinates representing the positions of the grid in the order they were visited.



Example 1:

Input: R = 1, C = 4, r0 = 0, c0 = 0
Output: [[0,0],[0,1],[0,2],[0,3]]




Example 2:

Input: R = 5, C = 6, r0 = 1, c0 = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]




Note:

1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C

*/

//Runtime: 20 ms, faster than 96.46% of C++ online submissions for Spiral Matrix III.
//Memory Usage : 10.8 MB, less than 96.02% of C++ online submissions for Spiral Matrix III.
class Solution {
public:
	vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
		vector<vector<int>> result;
		result.reserve(R * C);
		int x = c0, y = r0;
		int len = 1;
		int cur = 0;
		int dir = 0; // right, down, left, up
		int dx = 1, dy = 0;

		while (result.size() < result.capacity()) {
			if (x >= 0 && x < C && y >= 0 && y < R)
				result.push_back(vector<int>{y, x});
			x += dx;
			y += dy;
			if (++cur == len) {
				cur = 0;
				dir = (dir + 1) % 4;
				if (dir == 0) {
					dx = 1; dy = 0;
					++len;
				} else if (dir == 1) {
					dx = 0; dy = 1;
				}
				else if (dir == 2) {
					dx = -1; dy = 0;
					++len;
				}
				else if (dir == 3) {
					dx = 0; dy = -1;
				}
			}
		}

		return result;
	}
};

void print(const vector<vector<int>>& s) {
	for (const auto& p : s)
		cout << "(" << p[0] << " " << p[1] << ") ";
	cout << endl;
}

int main()
{
	print(Solution().spiralMatrixIII(1, 4, 0, 0)); // [[0,0],[0,1],[0,2],[0,3]]
	print(Solution().spiralMatrixIII(5, 6, 1, 4)); // [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]

    return 0;
}

