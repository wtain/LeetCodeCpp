
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]
Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]
 

Constraints:

2 <= nums.length <= 500
0 <= nums[i] <= 100
*/

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> counts;
		const int M = 100;
		counts.resize(M + 1);
		for (int n : nums)
			++counts[n];

		int cntLess = 0;
		for (int i = 0; i <= M; ++i) {
			auto ci = counts[i];
			counts[i] = cntLess;
			cntLess += ci;
		}

		vector<int> result;
		result.resize(nums.size());
		for (int i = 0; i < nums.size(); ++i)
			result[i] = counts[nums[i]];
		return result;
	}
};

int main()
{
	{
		auto r = Solution().smallerNumbersThanCurrent(vector<int>({ 8,1,2,2,3 }));
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl; // 4,0,1,1,3
	}
	{
		auto r = Solution().smallerNumbersThanCurrent(vector<int>({ 6,5,4,8 }));
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl; // 2,1,0,3
	}
	{
		auto r = Solution().smallerNumbersThanCurrent(vector<int>({ 7,7,7,7 }));
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl; // 0,0,0,0
	}
    return 0;
}

