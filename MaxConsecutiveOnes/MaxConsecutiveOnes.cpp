// MaxConsecutiveOnes.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/max-consecutive-ones/

Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int mx = 0;
		int c = 0;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			if (nums[i] == 1) {
				++c;
				mx = max(c, mx);
			}
			else c = 0;
		}
		return mx;
	}
};

int main()
{
	cout << Solution().findMaxConsecutiveOnes(vector<int>{1, 1, 0, 1, 1, 1}) << endl; // 3

    return 0;
}

