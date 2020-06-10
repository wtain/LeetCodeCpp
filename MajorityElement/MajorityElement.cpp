
#include <algorithm>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/majority-element/
Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		make_heap(begin(nums), end(nums));
		if (nums[0] == nums[1])
			return nums[0];
		if (nums[0] == nums[2])
			return nums[0];
		return nums[2];
	}
};

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 3, 5, 3, 3, 3, 6, 3, 4, 3, 6, 3, 5, 3, 4, 3, 3, 3, 6, 3, 7, 3};

	Solution().majorityElement(v);

    return 0;
}

