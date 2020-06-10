
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.


Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false


Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.

*/

class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		const int n = coordinates.size();
		if (n <= 2)
			return true;
		/*
		    i   j   k
		   v1x v1y v1z
		   v2x v2y c2z

		    i   j   k
		   v1x v1y  0
		   v2x v2y  0

		   0 0 v1x*v2y-v1y*v2x
		*/

		int v1x = coordinates[1][0] - coordinates[0][0];
		int v1y = coordinates[1][1] - coordinates[0][1];

		for (int i = 2; i < n; ++i) {
			int v2x = coordinates[i][0] - coordinates[0][0];
			int v2y = coordinates[i][1] - coordinates[0][1];

			if (v1x*v2y - v1y*v2x)
				return false;
		}
		return true;
	}
};

int main()
{
	cout << boolalpha << Solution().checkStraightLine(vector<vector<int>>({ {1, 2}, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 5, 6 }, { 6, 7 }})) << endl; // true
	cout << boolalpha << Solution().checkStraightLine(vector<vector<int>>({ {1,1},{2,2},{3,4},{4,5},{5,6},{7,7} })) << endl; // false

    return 0;
}

