
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/product-of-array-except-self/

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

*/

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) 
	{
		const size_t n = nums.size();
		vector<int> p1(n), p2(n);
		partial_sum(begin(nums), end(nums), begin(p1), multiplies<int>());
		partial_sum(rbegin(nums), rend(nums), rbegin(p2), multiplies<int>());

		vector<int> result(n);

		for (int i = 0; i < n; ++i)
		{
			int pl = (i > 0) ? p1[i - 1] : 1;
			int pr = (i < n-1) ? p2[i + 1] : 1;

			result[i] = pl * pr;
		}

		return result;
	}
};

int main()
{
	vector<int> test = { 1, 2, 3, 4 };
	const auto result = Solution().productExceptSelf(test);
	copy(begin(result), end(result), ostream_iterator<int>(cout, ", "));
	cout << endl;

    return 0;
}

