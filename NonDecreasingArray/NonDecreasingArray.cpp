
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/non-decreasing-array/

Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).



Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.


Constraints:

1 <= n <= 10 ^ 4
- 10 ^ 5 <= nums[i] <= 10 ^ 5

*/

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		const int n = nums.size();
		int j = -1;
		for (int i = 1; i < n; ++i) {
			if (nums[i] < nums[i - 1]) {
				if (-1 != j)
					return false;
				j = i - 1;
			}
		}
		if (j <= 0)
			return true;

		if (j >= n - 2)
			return true;

		return nums[j - 1] <= nums[j + 1] || nums[j] <= nums[j + 2];
	}
};

// WRONG
//class Solution {
//public:
//	bool checkPossibility(vector<int>& nums) {
//		const int n = nums.size();
//		bool found = false;
//		for (int i = 1; i < n; ++i) {
//			if (nums[i] < nums[i - 1]) {
//				if (found)
//					return false;
//				found = true;
//			}
//		}
//		return true;
//	}
//};

// WRONG
//class Solution {
//public:
//	bool checkPossibility(vector<int>& nums) {
//		const int n = nums.size();
//		vector<int> mins(n);
//		mins[n - 1] = nums[n - 1];
//		for (int i = n - 2; i >= 0; --i)
//			mins[i] = min(mins[i + 1], nums[i]);
//		bool found = false;
//		for (int i = 0; i < n - 1; ++i) {
//			if (nums[i] > mins[i + 1]) {
//				if (found)
//					return false;
//				found = true;
//			}
//		}
//		return true;
//	}
//};

int main()
{
	cout << boolalpha << Solution().checkPossibility(vector<int>({ 4,2,3 })) << endl; // true
	cout << boolalpha << Solution().checkPossibility(vector<int>({ 4,2,1 })) << endl; // false
	cout << boolalpha << Solution().checkPossibility(vector<int>({ 2, 3, 3, 2, 4 })) << endl; // true
	cout << boolalpha << Solution().checkPossibility(vector<int>({ 3,4,2,3 })) << endl; // false

    return 0;
}

