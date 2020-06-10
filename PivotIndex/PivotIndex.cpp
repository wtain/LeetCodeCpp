
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

/*

https://leetcode.com/problems/find-pivot-index/

Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:

Input:
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation:
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.


Example 2:

Input:
nums = [1, 2, 3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.


Note:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].

*/

class Solution {
public:
	int pivotIndex(vector<int>& nums) 
	{
		const size_t n = nums.size();
		if (!n)
			return -1;
		vector<int> sums1(n);
		vector<int> sums2(n);
		partial_sum(begin(nums), end(nums), begin(sums1));
		partial_sum(rbegin(nums), rend(nums), rbegin(sums2));

		if (sums2[1] == 0)
			return 0;

		for (size_t i = 1; i < n - 1; ++i)
		{
			if (sums1[i - 1] == sums2[i + 1])
				return i;
		}

		if (n >= 2 && sums1[n-2] == 0)
			return n-1;

		return -1;
	}
};

void PrintArray(const vector<int>& nums)
{
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ","));
	cout << endl;
}

void RunTest(vector<int>& nums)
{
	PrintArray(nums);
	cout << Solution().pivotIndex(nums) << endl;
}

int main()
{
	vector<int> test1 = { 1, 7, 3, 6, 5, 6 }; // 3
	vector<int> test2 = { 1, 2, 3 }; // -1
	vector<int> test3 = { 1, -3, 3 }; // 0
	vector<int> test4 = { 3, -3, 1 }; // 2
	vector<int> test5 = { -1, -1, 0, 1, 1, -1 }; // 0
	RunTest(test1);
	RunTest(test2);
	RunTest(test3);
	RunTest(test4);
	RunTest(test5);

    return 0;
}
