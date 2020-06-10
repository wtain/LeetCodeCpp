
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/

//Runtime: 8 ms, faster than 69.38% of C++ online submissions for Search in Rotated Sorted Array II.
//Memory Usage : 14.1 MB, less than 8.33% of C++ online submissions for Search in Rotated Sorted Array II.
//Runtime: 16 ms, faster than 17.02% of C++ online submissions for Search in Rotated Sorted Array II.
//Memory Usage : 14.1 MB, less than 8.33% of C++ online submissions for Search in Rotated Sorted Array II.
//Runtime: 8 ms, faster than 69.38% of C++ online submissions for Search in Rotated Sorted Array II.
//Memory Usage : 14 MB, less than 8.33% of C++ online submissions for Search in Rotated Sorted Array II.
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int b = 0, e = nums.size() - 1;
		while (b <= e)
		{
			if (nums[b] == nums[e]) {
				if (nums[e] == target)
					return true;
				int v = nums[b];
				while (b < e && nums[b] == v)
					++b;
				while (b < e && nums[e] == v)
					--e;
			}
			size_t n = e - b;
			size_t m = b + (n >> 1);
			if (nums[m] == target)
				return true;
			else if (nums[b] <= nums[m])
			{
				if (target > nums[m])
					b = m + 1;
				else if (target >= nums[b])
					e = m - 1;
				else
					b = m + 1;
			}
			else if (target < nums[m])
				e = m - 1;
			else if (target <= nums[e])
				b = m + 1;
			else
				e = m - 1;
		}
		return false;
	}
};

// WRONG
//class Solution {
//public:
//	bool search(vector<int>& nums, int target) {
//		int b = 0, e = nums.size() - 1;
//		while (b <= e)
//		{
//			if (nums[b] == nums[e]) {
//				if (nums[e] == target)
//					return true;
//				int v = nums[b];
//				while (b < e && nums[b] == nums[e]) {
//					--e; ++b;
//				}
//				continue;
//			}
//			size_t n = e - b;
//			size_t m = b + (n >> 1);
//			if (nums[m] == target)
//				return true;
//			else if (nums[b] <= nums[m])
//			{
//				if (target > nums[m])
//					b = m + 1;
//				else if (target >= nums[b])
//					e = m - 1;
//				else
//					b = m + 1;
//			}
//			else if (target < nums[m])
//				e = m - 1;
//			else if (target <= nums[e])
//				b = m + 1;
//			else
//				e = m - 1;
//		}
//		return false;
//	}
//};

int main()
{
	cout << boolalpha << Solution().search(vector<int>{1, 2, 1}, 2) << endl; // true

	cout << boolalpha << Solution().search(vector<int>{1, 1}, 0) << endl; // false

	cout << boolalpha << Solution().search(vector<int>{2, 5, 6, 0, 2, 2, 2, 2, 2}, 0) << endl; // true
	cout << boolalpha << Solution().search(vector<int>{2, 5, 6, 2, 2, 2, 2, 2, 2}, 0) << endl; // false

	cout << boolalpha << Solution().search(vector<int>{2, 5, 6, 0, 0, 1, 2}, 0) << endl; // true
	cout << boolalpha << Solution().search(vector<int>{2, 5, 6, 0, 0, 1, 2}, 3) << endl; // false

    return 0;
}

