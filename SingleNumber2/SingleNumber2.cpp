#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3368/
https://leetcode.com/problems/single-number-ii/

Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

//Runtime: 20 ms, faster than 42.85% of C++ online submissions for Single Number II.
//Memory Usage : 9.8 MB, less than 24.99% of C++ online submissions for Single Number II.
class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		int result = 0;
		unsigned int mask = 1;
		for (int b = 0; b < 32; ++b)
		{
			int cnt = 0;
			for (const auto vi : nums)
			{
				if (vi & mask)
				{
					++cnt;
					cnt %= 3;
				}
			}
			if (cnt)
				result |= mask;
			mask <<= 1;
		}
		return result;
	}
};

int main()
{
	vector<int> v1 = { 2,2,3,2 };
	cout << Solution().singleNumber(v1) << endl; // 3
	vector<int> v2 = { 0,1,0,1,0,1,99 };
	cout << Solution().singleNumber(v2) << endl; // 99
    return 0;
}

