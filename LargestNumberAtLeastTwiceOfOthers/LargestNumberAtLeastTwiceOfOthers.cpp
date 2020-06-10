
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/largest-number-at-least-twice-of-others/

In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:

Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.


Example 2:

Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.


Note:

nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].
*/

class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		if (nums.size() == 1)
			return 0;
		if (nums.size() < 2)
			return -1;
		pair<int, int> max1, max2;
		if (nums[0] > nums[1]) {
			max1 = make_pair(0, nums[0]);
			max2 = make_pair(1, nums[1]);
		}
		else {
			max2 = make_pair(0, nums[0]);
			max1 = make_pair(1, nums[1]);
		}
		for (int i = 2; i < nums.size(); ++i) {
			if (nums[i] >= max1.second) {
				max2 = max1;
				max1 = make_pair(i, nums[i]);
			}
			else if (nums[i] > max2.second) {
				max2 = make_pair(i, nums[i]);
			}
		}
		if (max1.second >= 2 * max2.second)
			return max1.first;
		return -1;
	}
};

int main()
{
	cout << Solution().dominantIndex(vector<int>{ 3, 6, 1, 0 }) << endl; // 1
	cout << Solution().dominantIndex(vector<int>{ 1, 2, 3, 4 }) << endl; // -1
	cout << Solution().dominantIndex(vector<int>{ 1 }) << endl; // 0
    return 0;
}

