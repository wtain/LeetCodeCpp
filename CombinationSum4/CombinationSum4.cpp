
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/combination-sum-iv/

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.


Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
*/

//Line 11: Char 7 : runtime error : signed integer overflow : 1941940377 + 357856184 cannot be represented in type 'int' (solution.cpp)
//SUMMARY : UndefinedBehaviorSanitizer : undefined - behavior prog_joined.cpp : 20 : 7
//class Solution {
//public:
//	int combinationSum4(vector<int>& nums, int target) {
//		vector<int> dp(target + 1);
//		dp[0] = 1;
//		for (int i = 1; i <= target; ++i) {
//			int v = 0;
//			for (auto n : nums) {
//				if (n > i)
//					continue;
//				v += dp[i - n];
//			}
//			dp[i] = v;
//		}
//		return dp[target];
//	}
//};

// STACK OVERFLOW
//class Solution {
//public:
//	
//	int combinationSum4impl(vector<int>& nums, int target, vector<int>& dp) {
//		int v = 0;
//		if (dp[target] != -1)
//			return dp[target];
//		for (auto n : nums) {
//			if (n > target)
//				continue;
//			if (-1 == dp[target - n])
//				dp[target - n] = combinationSum4impl(nums, target - n, dp);
//			v += dp[target - n];
//		}
//		return dp[target] = v;
//	}
//
//	int combinationSum4(vector<int>& nums, int target) {
//		vector<int> dp(target + 1, -1);
//		dp[0] = 1;
//		return combinationSum4impl(nums, target, dp);
//	}
//};

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<unsigned long long> dp(target + 1);
		dp[0] = 1ll;
		for (int i = 1; i <= target; ++i) {
			unsigned long long v = 0ll;
			for (auto n : nums) {
				if (n > i)
					continue;
				v += dp[i - n];
			}
			dp[i] = v;
		}
		return dp[target];
	}
};

int main()
{
	cout << Solution().combinationSum4(vector<int>{1, 2, 3}, 4) << endl; // 7
	cout << Solution().combinationSum4(vector<int>{3, 33, 333}, 10000) << endl; // 0
	
    return 0;
}

