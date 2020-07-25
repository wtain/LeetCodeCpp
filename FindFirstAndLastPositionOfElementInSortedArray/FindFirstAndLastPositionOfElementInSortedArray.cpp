
#include <vector>
#include <iostream>

using namespace std;

/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]


Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9

*/

//Runtime: 32 ms, faster than 12.79% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
//Memory Usage : 13.9 MB, less than 35.47% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int l = 0, r = nums.size();
		while (l < r) {
			int m = l + (r - l) / 2;
			if (nums[m] < target)
				l = m + 1;
			else if (nums[m] >= target)
				r = m;
		}
		int l0 = l;
		l = 0, r = nums.size();
		while (l < r) {
			int m = l + (r - l) / 2;
			if (nums[m] <= target)
				l = m + 1;
			else if (nums[m] > target)
				r = m;
		}
		l = l0;
		--r;
		if (l > r)
			return{ -1,-1 };
		return{ l, r };
	}
};

void print(const vector<int>& p) {
	cout << p[0] << " " << p[1] << endl;
}

int main()
{
	print(Solution().searchRange(vector<int>{5, 7, 7, 8, 8, 10}, 8)); // 3 4
	print(Solution().searchRange(vector<int>{5, 7, 7, 8, 8, 10}, 6)); // -1 -1
	print(Solution().searchRange(vector<int>{8, 8, 8, 8, 8, 8}, 8)); // 0 5

    return 0;
}

