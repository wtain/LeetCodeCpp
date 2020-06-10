
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3341/
https://leetcode.com/problems/contiguous-array/

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
*/

//Runtime: 256 ms, faster than 31.95% of C++ online submissions for Contiguous Array.
//Memory Usage : 83 MB, less than 8.33% of C++ online submissions for Contiguous Array.
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int balance = 0;
		const int n = nums.size();
		unordered_map<int, int> index;
		index.emplace(0, -1);
		int maxLen = 0;
		for (int i = 0; i < n; ++i) {
			if (nums[i] == 1)
				++balance;
			else
				--balance;
			auto it = index.find(balance);
			if (it == end(index))
				index.emplace_hint(it, balance, i);
			else
				maxLen = max(maxLen, i - it->second);
		}
		return maxLen;
	}
};

int main()
{
	cout << Solution().findMaxLength(vector<int>{0, 1}) << endl; // 2
	cout << Solution().findMaxLength(vector<int>{0, 1, 0}) << endl; // 2

    return 0;
}

