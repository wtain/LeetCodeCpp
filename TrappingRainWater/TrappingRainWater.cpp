
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

https://leetcode.com/problems/trapping-rain-water/solution/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

*/

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

class Solution {
public:
	int trap(vector<int>& height) 
	{
		int n = height.size();
		if (!n)
			return 0;
		int res = 0;
		vector<int> max1(n), max2(n);
		max1[0] = height[0];
		max2[n-1] = height[n-1];
		for (int i = 1; i < n; ++i)
		{
			max1[i] = max(max1[i - 1], height[i]);
			int i1 = n - 1 - i;
			max2[i1] = max(max2[i1 + 1], height[i1]);
		}
		for (int i = 0; i < n; ++i)
		{
			int m = min(max1[i], max2[i]);
			if (height[i] < m)
				res += m - height[i];
		}
		return res;
	}
};

int main()
{
	vector<int> v = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << Solution().trap(v) << endl; // 6
    return 0;
}

