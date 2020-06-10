
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/degree-of-an-array/

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.

*/

class Solution {
public:

	struct Stats {
		int count;
		int minI;
		int maxI;

		Stats() : count(0) {

		}

		int visit(int index) {
			if (1 == ++count)
				minI = index;
			maxI = index;
			return count;
		}

		int len() const { return maxI - minI + 1; }
	};

	pair<unordered_map<int, Stats>, int> calcFrequencies(const vector<int>& nums) {
		unordered_map<int, Stats> freqs;
		int maxFreq = 0;
		//for (int a : nums)
			//maxFreq = max(maxFreq, ++freqs[a]);
		for (int i = 0; i < nums.size(); ++i)
			maxFreq = max(maxFreq, freqs[nums[i]].visit(i));
		
		return{ freqs, maxFreq };
	}

	int findShortestSubArray(vector<int>& nums) {
		auto freqs = calcFrequencies(nums);
		int minLen = numeric_limits<int>::max();
		for (const auto& f : freqs.first) {
			if (f.second.count < freqs.second)
				continue;
			minLen = min(minLen, f.second.len());
		}
		return minLen;
	}
};

int main()
{
	cout << Solution().findShortestSubArray(vector<int>({ 1, 2, 2, 3, 1 })) << endl; // 2
	cout << Solution().findShortestSubArray(vector<int>({ 1,2,2,3,1,4,2 })) << endl; // 6
    return 0;
}

