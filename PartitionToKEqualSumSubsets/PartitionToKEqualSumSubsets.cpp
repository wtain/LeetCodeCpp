
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <set>
#include <functional>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.


Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.

*/

// WRONG
//class Solution {
//public:
//	bool canPartitionKSubsets(vector<int>& nums, int k) {
//		int s = accumulate(begin(nums), end(nums), 0);
//		if (s % k)
//			return false;
//		int ps = s / k;
//
//		//multiset<int, greater<int>> sets;
//		multiset<int, less<int>> sets;
//		for (int i = 0; i < k; ++i)
//			sets.insert(0);
//
//		for (const auto n : nums) {
//			int t = ps - n;
//			bool f = false;
//			for (auto it = begin(sets); it != end(sets); ++it) {
//				if (*it <= t) {
//					int newv = *it + n;
//					sets.erase(it);
//					if (newv < ps)
//						sets.emplace(newv);
//
//					/*copy(begin(sets), end(sets), ostream_iterator<int>(cout, " "));
//					cout << endl;*/
//
//					f = true;
//					break;
//				}
//			}
//			if (!f)
//				return false;
//		}
//		return true;
//	}
//};

// TLE; afetr adding sort and drops for superfluous cases checks
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Partition to K Equal Sum Subsets.
//Memory Usage : 9.1 MB, less than 97.18% of C++ online submissions for Partition to K Equal Sum Subsets.
//class Solution {
//public:
//
//	bool canPartitionKSubsetsImpl(const vector<int>& nums, int starti, vector<int>& sets, const int ps) {
//		if (starti == nums.size()) {
//			for (int j = 0; j < sets.size(); ++j) {
//				if (sets[j] != ps)
//					return false;
//			}
//			return true;
//		}
//		for (int j = 0; j < sets.size(); ++j) {
//			if (sets[j] == ps)
//				continue;
//			if (sets[j] + nums[starti] <= ps) {
//				sets[j] += nums[starti];
//				if (canPartitionKSubsetsImpl(nums, starti + 1, sets, ps))
//					return true;
//				sets[j] -= nums[starti];
//			}
//			if (!sets[j])
//				break;
//		}
//		return false;
//	}
//
//	bool canPartitionKSubsets(vector<int>& nums, int k) {
//		int s = accumulate(begin(nums), end(nums), 0);
//		if (s % k)
//			return false;
//		int ps = s / k;
//
//		sort(begin(nums), end(nums), greater<int>());
//
//		vector<int> sets;
//		for (int i = 0; i < k; ++i)
//			sets.emplace_back(0);
//
//		return canPartitionKSubsetsImpl(nums, 0, sets, ps);
//	}
//};

//Runtime: 144 ms, faster than 16.42% of C++ online submissions for Partition to K Equal Sum Subsets.
//Memory Usage : 17.6 MB, less than 13.20% of C++ online submissions for Partition to K Equal Sum Subsets.
class Solution {
public:

	bool canPartitionKSubsets(vector<int>& nums, int k) {
		const auto n = nums.size();
		int s = accumulate(begin(nums), end(nums), 0);
		if (s % k)
			return false;
		int ps = s / k;

		sort(begin(nums), end(nums), greater<int>());

		vector<bool> states(1 << n);
		vector<int> sums(1 << n);
		states[0] = true;

		for (int state = 0; state < states.size(); ++state) {
			if (!states[state])
				continue;
			for (int i = 0; i < n; ++i) {
				int nextState = state | (1 << i);
				if (nextState != state && !states[nextState]) {
					if (nums[i] <= ps - (sums[state] % ps)) {
						states[nextState] = true;
						sums[nextState] = sums[state] + nums[i];
					}
					else {
						break;
					}
				}
			}
		}

		return states[(1 << n) - 1];
	}
};

int main()
{
	cout << boolalpha << Solution().canPartitionKSubsets(vector<int>{605, 454, 322, 218, 8, 19, 651, 2220, 175, 710, 2666, 350, 252, 2264, 327, 1843}, 4) << endl; // true

	cout << boolalpha << Solution().canPartitionKSubsets(vector<int>{10, 10, 10, 7, 7, 7, 7, 7, 7, 6, 6, 6}, 3) << endl; // true

	cout << boolalpha << Solution().canPartitionKSubsets(vector<int>{4, 3, 2, 3, 5, 2, 1}, 4) << endl; // true

	cout << boolalpha << Solution().canPartitionKSubsets(vector<int>{4, 3, 2, 2, 5, 2, 1}, 4) << endl; // false

	cout << boolalpha << Solution().canPartitionKSubsets(vector<int>{4, 3, 2, 3, 6, 1, 1}, 4) << endl; // false

    return 0;
}

