
#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/single-number/

/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int sum = 0;
		for (const auto n : nums)
			sum ^= n;
		return sum;
	}
};

int main()
{
	cout << Solution().singleNumber(vector<int>({ 2, 2, 1 })) << endl; // 1
	cout << Solution().singleNumber(vector<int>({ 4,1,2,1,2 })) << endl; // 4
    return 0;
}

