
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/longest-harmonious-subsequence/

We define a harmounious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:

Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].


Note: The length of the input array will not exceed 20,000.
*/

//class Solution {
//public:
//	int findLHS(vector<int>& nums) {
//		unordered_map<int, int> counts;
//		for (int i = 0; i < nums.size(); ++i)
//			counts[nums[i]]++;
//		int maxLen = 0;
//
//		for (const auto& p : counts) {
//			auto it = counts.find(p.first+1);
//			if (it != end(counts))
//				maxLen = max(maxLen, p.second + it->second);
//		}
//		return maxLen;
//	}
//};

class Solution {
public:
	int findLHS(vector<int>& nums) {
		unordered_map<int, int> counts;

		int maxLen = 0;

		for (int i = 0; i < nums.size(); ++i) {
			counts[nums[i]]++;

			auto it = counts.find(nums[i] + 1);
			if (it != end(counts))
				maxLen = max(maxLen, counts[nums[i]] + counts[nums[i] + 1]);

			it = counts.find(nums[i] - 1);
			if (it != end(counts))
				maxLen = max(maxLen, counts[nums[i]] + counts[nums[i] - 1]);
		}

		return maxLen;
	}
};

int main()
{
	cout << Solution().findLHS(vector<int>({ 1,3,2,2,5,2,3,7 })) << endl; // 5
    return 0;
}

