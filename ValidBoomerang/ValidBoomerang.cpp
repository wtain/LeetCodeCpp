
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

/*
https://leetcode.com/problems/valid-boomerang/

A boomerang is a set of 3 points that are all distinct and not in a straight line.

Given a list of three points in the plane, return whether these points are a boomerang.

Example 1:

Input: [[1,1],[2,3],[3,2]]
Output: true
Example 2:

Input: [[1,1],[2,2],[3,3]]
Output: false


Note:

points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100
*/

class Solution {
public:

	struct Vector {
		int x, y;

		Vector(int x, int y) : x(x), y(y) { }

		explicit Vector(const vector<int>& p) : x(p[0]), y(p[1]) {

		}

		int productLength(const Vector& v) {
			return x*v.y - v.x*y;
		}
	};

	struct Point : public Vector {
		using Vector::Vector;

		Vector operator- (const Point& p) const {
			return Vector(x - p.x, y - p.y);
		}
	};

	bool isBoomerang(vector<vector<int>>& points) {
		Point p1(points[0]), p2(points[1]), p3(points[2]);
		Vector v1 = p2 - p1, v2 = p3 - p1;
		return !!v1.productLength(v2);
	}
};

int main()
{
	cout << boolalpha << Solution().isBoomerang(vector<vector<int>>{ {1, 1}, { 2,3 }, { 3,2 }}) << endl; // true
	cout << boolalpha << Solution().isBoomerang(vector<vector<int>>{ {1, 1}, { 2,2 }, { 3,3 }}) << endl; // false

    return 0;
}

