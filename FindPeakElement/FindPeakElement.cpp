
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/find-peak-element/

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ? nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -?.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5
Explanation: Your function can return either index number 1 where the peak element is 2,
or index number 5 where the peak element is 6.
Note:

Your solution should be in logarithmic complexity.
*/

//class Solution {
//public:
//	int findPeakElement(vector<int>& nums) 
//	{
//		return search(nums, 0, nums.size() - 1);
//	}
//
//	int search(const vector<int>& nums, int l, int r)
//	{
//		if (l == r)
//			return l;
//		int mid = (l + r) / 2;
//		if (nums[mid] > nums[mid + 1])
//			return search(nums, l, mid);
//		else
//			return search(nums, mid+1, r);
//	}
//};

class Solution {
public:
	int findPeakElement(vector<int>& nums)
	{
		int l = 0, r = nums.size() - 1;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] > nums[mid + 1])
				r = mid;
			else
				l = mid + 1/*, r*/; // /
		}
		return l;
	}
};

int main()
{
	cout << Solution().findPeakElement(vector<int>({ 1,2,3,1 })) << endl; // 2
	cout << Solution().findPeakElement(vector<int>({ 1,2,1,3,5,6,4 })) << endl; // 1 or 5

    return 0;
}

