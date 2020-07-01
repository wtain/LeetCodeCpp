
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <string>

using namespace std;

/*
https://leetcode.com/problems/partition-equal-subset-sum/

Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.


Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].


Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

*/

// TLE
//class Solution {
//public:
//
//	bool canPartitionImpl(const vector<int>& nums, int i0, int ps) {
//		if (0 == ps)
//			return true;
//		if (i0 == nums.size())
//			return false;
//		for (int i = i0; i < nums.size(); ++i) {
//			if (nums[i] <= ps && canPartitionImpl(nums, i + 1, ps - nums[i]))
//				return true;
//		}
//		return false;
//	}
//
//	bool canPartition(vector<int>& nums) {
//		const auto n = nums.size();
//		int s = accumulate(begin(nums), end(nums), 0);
//		if (s % 2)
//			return false;
//		int ps = s / 2;
//
//		sort(begin(nums), end(nums), greater<int>());
//
//		return canPartitionImpl(nums, 0, ps);
//	}
//};

//Runtime: 4 ms, faster than 99.58% of C++ online submissions for Partition Equal Subset Sum.
//Memory Usage : 8.8 MB, less than 99.17% of C++ online submissions for Partition Equal Subset Sum.
//class Solution {
//public:
//
//	bool canPartitionImpl(const vector<int>& nums, int i0, int ps) {
//		if (0 == ps)
//			return true;
//		if (i0 == nums.size())
//			return false;
//		for (int i = i0; i < nums.size(); ++i) {
//			if (nums[i] <= ps && canPartitionImpl(nums, i + 1, ps - nums[i]))
//				return true;
//		}
//		return false;
//	}
//
//	bool canPartition(vector<int>& nums) {
//		const auto n = nums.size();
//		int s = accumulate(begin(nums), end(nums), 0);
//		if (s % 2)
//			return false;
//		int ps = s / 2;
//
//		for (const auto ni : nums)
//			if (ni > ps)
//				return false;
//
//		sort(begin(nums), end(nums), greater<int>());
//
//		return canPartitionImpl(nums, 0, ps);
//	}
//};


//Runtime: 656 ms, faster than 13.39% of C++ online submissions for Partition Equal Subset Sum.
//Memory Usage : 11 MB, less than 44.58% of C++ online submissions for Partition Equal Subset Sum.
class Solution {
public:

	bool canPartition(vector<int>& nums) {
		const auto n = nums.size();
		int s = accumulate(begin(nums), end(nums), 0);
		if (s % 2)
			return false;
		int ps = s / 2;

		vector<vector<bool>> dp(n + 1, vector<bool>(ps + 1));
		dp[0][0] = true;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= ps; ++j) {
				if (nums[i - 1] <= j)
					dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		return dp[n][ps];
	}
};

void runTest(const string& name, vector<int> nums, const bool expected) {
	cout << name << ": " << boolalpha << (Solution().canPartition(nums) == expected) << endl;
}

int main()
{
	runTest("Failed case 2 - TLE", { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 100 }, false);
	runTest("Huge", { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 100 }, true);
	runTest("Failed case 1", { 1, 2, 5 }, false);
	runTest("Example 1", { 1, 5, 11, 5 }, true);
	runTest("Example 2", { 1, 2, 3, 5 }, false);

    return 0;
}

