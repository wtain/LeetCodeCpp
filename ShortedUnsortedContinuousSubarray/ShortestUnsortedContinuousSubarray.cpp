
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://twchen.gitbook.io/leetcode/array/shortest-unsorted-continuous-subarray

https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

*/

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) 
	{
		const int n = nums.size();
		int nmax = nums[0], nmin = nums[n-1];

		int r = 0, l = 1;
		for (int i = 1; i < n; ++i)
		{
			if (nums[i] < nmax)
				r = i;
			else
				nmax = max(nmax, nums[i]);
		}

		for (int i = n-2; i >= 0; --i)
		{
			if (nums[i] > nmin)
				l = i;
			else
				nmin = min(nmin, nums[i]);
		}
		return r - l + 1;
	}
};

int main()
{
	vector<int> v = { 2, 6, 4, 8, 10, 9, 15 };
	cout << Solution().findUnsortedSubarray(v) << endl; // 5

	vector<int> v2 = { 1,2,3,4 };
	cout << Solution().findUnsortedSubarray(v2) << endl; // 0

    return 0;
}

