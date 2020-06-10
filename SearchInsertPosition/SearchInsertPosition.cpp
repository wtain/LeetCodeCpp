
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3356/

https://leetcode.com/problems/search-insert-position/

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0

*/

//Runtime: 16 ms, faster than 7.15% of C++ online submissions for Search Insert Position.
//Memory Usage : 9.8 MB, less than 29.97% of C++ online submissions for Search Insert Position.
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		auto b = begin(nums), e = end(nums);
		while (b != e)
		{
			auto m = b + distance(b, e) / 2;
			if (*m == target)
				return distance(begin(nums), m);
			if (*m > target)
				e = m;
			else
				b = m + 1;
		}
		return distance(begin(nums), b);
	}
};

int main()
{
	cout << Solution().searchInsert(vector<int>{1, 3, 5, 6}, 5) << endl; // 2
	cout << Solution().searchInsert(vector<int>{1, 3, 5, 6}, 2) << endl; // 1
	cout << Solution().searchInsert(vector<int>{1, 3, 5, 6}, 7) << endl; // 4
	cout << Solution().searchInsert(vector<int>{1, 3, 5, 6}, 0) << endl; // 0

    return 0;
}

