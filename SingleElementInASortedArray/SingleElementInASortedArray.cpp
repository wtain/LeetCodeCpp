
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.



Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10


Note: Your solution should run in O(log n) time and O(1) space.
*/

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		const size_t n = nums.size();
		if (n == 1)
			return nums[0];
		const size_t n2 = n / 2;
		size_t l = 0, r = n2;
		while (l < r) {
			size_t m2 = l + (r - l) / 2;
			size_t m = 2 * m2;
			size_t m1 = m + 1;
			if (nums[m] == nums[m1])
				l = m2 + 1;
			else if (m > 0 && nums[m] == nums[m - 1])
				r = m2;
			else
				return nums[m];
			//if (nums[m] == nums[m - 1])
			//	r = m - 1;
			//else if (nums[m] == nums[m + 1])
			//	l = m/* + 2*/;
			//else
			//	return nums[m];
		}
		return nums[2*l];
		//return -1;;
	}
};

int main()
{
	cout << Solution().singleNonDuplicate(vector<int>{1, 1, 2, 3, 3, 4, 4, 8, 8}) << endl; // 2
	cout << Solution().singleNonDuplicate(vector<int>{3, 3, 7, 7, 10, 11, 11}) << endl; // 10
	cout << Solution().singleNonDuplicate(vector<int>{3}) << endl; // 3
	cout << Solution().singleNonDuplicate(vector<int>{1, 2, 2, 3, 3}) << endl; // 1
	cout << Solution().singleNonDuplicate(vector<int>{1, 1, 2, 2, 3}) << endl; // 3
	cout << Solution().singleNonDuplicate(vector<int>{1, 1, 2, 3, 3}) << endl; // 2

    return 0;
}

