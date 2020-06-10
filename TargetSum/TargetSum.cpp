
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/target-sum/

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

// RE
//class Solution {
//public:
//
//	int findTargetSumWaysImpl(const vector<int>& nums, int S, int startIndex) {
//		if (startIndex == nums.size())
//			return S == 0 ? 1 : 0;
//		
//		return findTargetSumWaysImpl(nums, S + nums[startIndex], startIndex + 1) + 
//			   findTargetSumWaysImpl(nums, S - nums[startIndex], startIndex + 1);
//	}
//
//	int findTargetSumWays(vector<int>& nums, int S) {
//		return findTargetSumWaysImpl(nums, S, 0);
//	}
//};

//TLE
//class Solution {
//public:
//
//	int findTargetSumWaysImpl(const vector<int>& nums, int currentSum, int S, int startIndex) {
//		if (startIndex == nums.size())
//			return S == currentSum ? 1 : 0;
//		
//		return findTargetSumWaysImpl(nums, currentSum + nums[startIndex], S, startIndex + 1) +
//			   findTargetSumWaysImpl(nums, currentSum - nums[startIndex], S, startIndex + 1);
//	}
//
//	int findTargetSumWays(vector<int>& nums, int S) {
//		return findTargetSumWaysImpl(nums, 0, S, 0);
//	}
//};

//Runtime: 32 ms, faster than 64.96% of C++ online submissions for Target Sum.
//Memory Usage : 38.1 MB, less than 23.08% of C++ online submissions for Target Sum.
//class Solution {
//	vector<vector<int>> sumCounts;
//
//public:
//
//	int findTargetSumWaysImpl(const vector<int>& nums, int currentSum, int S, int startIndex) {
//		if (startIndex == nums.size())
//			return S == currentSum ? 1 : 0;
//
//		if (sumCounts[startIndex][currentSum + 1000] != numeric_limits<int>::min())
//			return sumCounts[startIndex][currentSum + 1000];
//			
//		int cnt = findTargetSumWaysImpl(nums, currentSum + nums[startIndex], S, startIndex + 1) +
//				findTargetSumWaysImpl(nums, currentSum - nums[startIndex], S, startIndex + 1);
//
//		sumCounts[startIndex][currentSum + 1000] = cnt;
//		return cnt;
//	}
//
//	int findTargetSumWays(vector<int>& nums, int S) {
//		sumCounts.resize(nums.size(), vector<int>(2001, numeric_limits<int>::min()));
//		return findTargetSumWaysImpl(nums, 0, S, 0);
//	}
//};

//Runtime: 88 ms, faster than 55.60% of C++ online submissions for Target Sum.
//Memory Usage : 38.2 MB, less than 23.08% of C++ online submissions for Target Sum.
//class Solution {
//
//public:
//
//	int findTargetSumWays(vector<int>& nums, int S) {
//		vector<vector<int>> sumCounts;
//		const int n = nums.size();
//		sumCounts.resize(n, vector<int>(2001, 0));
//
//		sumCounts[0][1000 + nums[0]] = 1;
//		sumCounts[0][1000 - nums[0]] += 1;
//		for (int i = 1; i < n; ++i) {
//			for (int sum = -1000; sum <= 1000; ++sum) {
//				if (sumCounts[i - 1][1000 + sum] > 0) {
//					sumCounts[i][1000 + sum + nums[i]] += sumCounts[i - 1][1000 + sum];
//					sumCounts[i][1000 + sum - nums[i]] += sumCounts[i - 1][1000 + sum];
//				}
//			}
//		}
//
//		return S > 1000 ? 0 : sumCounts[n - 1][1000 + S];
//	}
//};

/*
Runtime: 68 ms, faster than 57.20% of C++ online submissions for Target Sum.
Memory Usage: 13.7 MB, less than 38.46% of C++ online submissions for Target Sum.
*/
class Solution {
	
public:

	int findTargetSumWays(vector<int>& nums, int S) {
		vector<vector<int>> sumCounts;
		const int n = nums.size();
		sumCounts.resize(2, vector<int>(2001, 0));

		sumCounts[0][1000 + nums[0]] = 1;
		sumCounts[0][1000 - nums[0]] += 1;
		for (int i = 1; i < n; ++i) {
			for (int sum = -1000; sum <= 1000; ++sum)
				sumCounts[i % 2][1000 + sum] = 0;
			for (int sum = -1000; sum <= 1000; ++sum) {
				if (sumCounts[(i - 1) % 2][1000 + sum] > 0) {
					sumCounts[i % 2][1000 + sum + nums[i]] += sumCounts[(i - 1) % 2][1000 + sum];
					sumCounts[i % 2][1000 + sum - nums[i]] += sumCounts[(i - 1) % 2][1000 + sum];
				}
			}
		}

		return S > 1000 ? 0 : sumCounts[(n-1) % 2][1000 + S];
	}
};

int main()
{

	cout << Solution().findTargetSumWays(vector<int>{2, 107, 109, 113, 127, 131, 137, 3, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 47, 53}, 2147483647) << endl; // 0
	cout << Solution().findTargetSumWays(vector<int>{1, 1, 1, 1, 1}, 3) << endl; // 5

    return 0;
}

