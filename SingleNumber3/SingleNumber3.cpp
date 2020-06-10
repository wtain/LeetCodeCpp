
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other 
elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) 
	{
		//unordered_set<int> cache;
		
		int v = 0;
		for (const auto vi : nums)
			v ^= vi;
		
		int mask = 1;
		while (!(v & mask))
			mask <<= 1;

		int v0 = 0, v1 = 0;
		for (const auto vi : nums)
		{
			if (vi & mask)
				v1 ^= vi;
			else
				v0 ^= vi;
		}
		return{ v0, v1 };
		/*for (const auto vi : nums)
		{
			auto it = cache.find(vi);
			if (it == end(cache))
				cache.emplace_hint(it, vi);
			else
				cache.erase(it);
		}
		vector<int> result;
		for (const auto ci : cache)
			result.push_back(ci);
		return result;*/
	}
};


int main()
{
	vector<int> nums = { 1,2,1,3,2,5 };
	auto r = Solution().singleNumber(nums);
	copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
	cout << endl;
    return 0;
}

