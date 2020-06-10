
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<int> prevLevel{ triangle[0][0] };
		int minCost = triangle[0][0];
		for (int level = 1; level < triangle.size(); ++level) {
			vector<int> currentLevel(triangle[level].size());
			minCost = numeric_limits<int>::max();
			for (int i = 0; i < triangle[level].size(); ++i) 
			{
				int minCostI = numeric_limits<int>::max();
				if (i > 0)
					minCostI = prevLevel[i - 1];
				if (i < triangle[level].size() - 1)
					minCostI = min(minCostI, prevLevel[i]);
				currentLevel[i] = triangle[level][i] + minCostI;
				minCost = min(currentLevel[i], minCost);
			}
			prevLevel.swap(currentLevel);
		}
		return minCost;
	}
};

int main()
{
	cout << Solution().minimumTotal(vector<vector<int>>{ {2}, { 3, 4 }, { 6,5,7 }, { 4,1,8,3 }}) << endl; // 11

    return 0;
}

