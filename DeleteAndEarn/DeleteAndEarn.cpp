
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

/*
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:

Input: nums = [3, 4, 2]
Output: 6
Explanation:
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.


Example 2:

Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation:
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.


Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].
*/

// DOES NOT WORK, HANGS
//class Solution {
//public:
//
//	unordered_map<int, int> getCounts(vector<int>& nums) {
//		unordered_map<int, int> result;
//		for (const auto n : nums)
//			result[n]++;
//		return result;
//	}
//
//	int deleteAndEarnImpl(unordered_map<int, int>& counts) {
//		int r = 0;
//		for (auto& p : counts) {
//			if (!p.second)
//				continue;
//			int pv = p.second * p.first;
//			int c1 = 0, c2 = 0;
//			int c0 = p.second;
//			auto i1 = counts.find(p.first - 1);
//			auto i2 = counts.find(p.first + 1);
//			if (i1 != end(counts)) {
//				c1 = i1->second;
//				counts.erase(i1);
//			}
//			if (i2 != end(counts)) {
//				c2 = i2->second;
//				counts.erase(i2);
//			}
//			p.second = 0;
//			r = max(r, pv + deleteAndEarnImpl(counts));
//			p.second = c0;
//			if (c1)
//				counts[p.first - 1] = c1;
//			if (c2)
//				counts[p.first + 1] = c2;
//		}
//		return r;
//	}
//
//	int deleteAndEarn(vector<int>& nums) {
//		auto c = getCounts(nums);
//		return deleteAndEarnImpl(c);
//	}
//};

//Runtime: 24 ms, faster than 28.88% of C++ online submissions for Delete and Earn.
//Memory Usage : 10.5 MB, less than 43.03% of C++ online submissions for Delete and Earn.
//class Solution {
//public:
//
//	map<int, int> getCounts(vector<int>& nums) {
//		map<int, int> result;
//		for (const auto n : nums)
//			result[n]++;
//		return result;
//	}
//
//	int deleteAndEarn(vector<int>& nums) {
//		auto c = getCounts(nums);
//		
//		const auto n = c.size();
//
//		vector<vector<int>> dp(n+1, vector<int>(2));
//
//		int i = 1;
//		int prevV = -1;
//		for (auto rit = rbegin(c); rit != rend(c); ++rit, ++i) {
//			int v0 = dp[i - 1][0];
//			int v1 = dp[i - 1][1];
//			int ci = rit->first * rit->second;
//			if (rit == rbegin(c) || rit->first + 1 != prevV)
//				dp[i][1] = ci + max(v0, v1);
//			else
//				dp[i][1] = max(v0 + ci, v1);
//
//			dp[i][0] = max(v0, v1);
//			prevV = rit->first;
//		}
//
//		return max(dp[n][0], dp[n][1]);
//	}
//};

//Runtime: 28 ms, faster than 23.27% of C++ online submissions for Delete and Earn.
//Memory Usage : 10.6 MB, less than 42.00% of C++ online submissions for Delete and Earn.
class Solution {
public:

	int deleteAndEarn(vector<int>& nums) {
		
		sort(begin(nums), end(nums), greater<int>());

		const auto n = nums.size();

		vector<vector<int>> dp(n + 1, vector<int>(2));

		int prevv = -1;
		int k = 0;
		for (int i = 0; i < n; ++i, ++k) {
			int v0 = dp[k][0];
			int v1 = dp[k][1];
			int ci = nums[i];
			int j = i;
			int si = 0;
			while (j < n && nums[j] == nums[i]) {
				si += ci;
				++j;
			}
			if (nums[i] == nums[0] || nums[i] + 1 != prevv)
				dp[k+1][1] = si + max(v0, v1);
			else
				dp[k+1][1] = max(v0 + si, v1);

			dp[k+1][0] = max(v0, v1);
			prevv = ci;
			i = j - 1;
		}

		return max(dp[k][0], dp[k][1]);
	}
};

int main()
{
	cout << Solution().deleteAndEarn(vector<int>{3, 4, 2}) << endl; // 6
	cout << Solution().deleteAndEarn(vector<int>{2, 2, 3, 3, 3, 4}) << endl; // 9

    return 0;
}

