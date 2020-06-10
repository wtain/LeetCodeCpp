
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

/*
https://leetcode.com/problems/matrix-cells-in-distance-order/

We are given a matrix with R rows and C columns has cells with integer coordinates (r, c), where 0 <= r < R and 0 <= c < C.

Additionally, we are given a cell in that matrix with coordinates (r0, c0).

Return the coordinates of all cells in the matrix, sorted by their distance from (r0, c0) from smallest distance to largest distance.  Here, the distance between two cells (r1, c1) and (r2, c2) is the Manhattan distance, |r1 - r2| + |c1 - c2|.  (You may return the answer in any order that satisfies this condition.)



Example 1:

Input: R = 1, C = 2, r0 = 0, c0 = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (r0, c0) to other cells are: [0,1]
Example 2:

Input: R = 2, C = 2, r0 = 0, c0 = 1
Output: [[0,1],[0,0],[1,1],[1,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
Example 3:

Input: R = 2, C = 3, r0 = 1, c0 = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].


Note:

1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C
*/

//Runtime: 192 ms, faster than 29.40% of C++ online submissions for Matrix Cells in Distance Order.
//Memory Usage : 18.9 MB, less than 65.00% of C++ online submissions for Matrix Cells in Distance Order.
//class Solution {
//public:
//
//	struct Vector {
//		int x, y;
//
//		Vector(int x, int y) : x(x), y(y) {}
//
//		int Dist() const {
//			return abs(x) + abs(y);
//		}
//	};
//
//	struct Cell : public Vector {
//		using Vector::Vector;
//
//		Vector operator- (const Cell& c) const {
//			return Vector(x - c.x, y - c.y);
//		}
//
//		vector<int> toVector() const { return{ x, y }; }
//	};
//
//	struct Comparator : public Cell {
//
//		using Cell::Cell;
//
//		bool operator() (const Cell& c1, const Cell& c2) const {
//			return (c1 - *this).Dist() < (c2 - *this).Dist();
//		}
//	};
//
//	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
//		multiset<Cell, Comparator> cells(Comparator(r0, c0));
//		for (int i = 0; i < R; ++i)
//			for (int j = 0; j < C; ++j)
//				cells.emplace(Cell(i, j));
//
//		vector<vector<int>> result;
//		result.reserve(R * C);
//		for (const auto& c : cells)
//			result.emplace_back(c.toVector());
//		return result;
//	}
//};

//Runtime: 88 ms, faster than 88.82% of C++ online submissions for Matrix Cells in Distance Order.
//Memory Usage : 16.5 MB, less than 82.50% of C++ online submissions for Matrix Cells in Distance Order.
class Solution {
public:

	struct Comparator {
		int r0, c0;

		Comparator(int r0, int c0) : r0(r0), c0(c0) {}

		int dist(const vector<int>& c) const {
			return abs(c[0] - r0) + abs(c[1] - c0);
		}

		bool operator() (const vector<int>& c1, const vector<int>& c2) const {
			return dist(c1) < dist(c2);
		}
	};

	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int>> result;

		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				result.push_back(vector<int>{i, j});

		sort(begin(result), end(result), Comparator(r0, c0));

		return result;
	}
};

void print(const vector<vector<int>>& v) {
	for (const auto& p : v)
		cout << "[" << p[0] << " " << p[1] << "] ";
	cout << endl;
}

int main()
{
	print(Solution().allCellsDistOrder(1, 2, 0, 0)); // [[0,0],[0,1]]
	print(Solution().allCellsDistOrder(2, 2, 0, 1)); // [[0,1],[0,0],[1,1],[1,0]]
	print(Solution().allCellsDistOrder(2, 3, 1, 2)); // [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
	print(Solution().allCellsDistOrder(3, 5, 2, 3)); // [[2,3],[1,3],[2,2],[2,4],[0,3],[1,2],[1,4],[2,1],[0,2],[0,4],[1,1],[2,0],[0,1],[1,0],[0,0]]

    return 0;
}

