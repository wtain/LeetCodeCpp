
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/4sum/

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]

https://leetcode.com/problems/4sum-ii

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ? N ? 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

*/

/*
class Solution {
public:
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
int result = 0;
unordered_map<int, int> countsab;
for (auto a : A)
{
for (auto b : B)
{
++countsab[a + b];
}
}
for (auto c : C)
{
for (auto d : D)
{
const int target = -c - d;
auto it = countsab.find(target);
if (it != end(countsab))
result += it->second;
}
}
return result;
}
};
*/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) 
	{
		vector<vector<int>> result;
		const int n = nums.size();

		sort(begin(nums), end(nums));

		for (int i = 0; i < n - 3; ++i)
		{
			if (nums[i] * 4 > target)
				return result;
			for (int j = n - 1; j > i + 2; --j)
			{
				if (nums[j] * 4 < target)
					break;
				int lo = i + 1, hi = j - 1;
				int t = target - nums[i] - nums[j];
				while (lo < hi)
				{
					int s = nums[lo] + nums[hi];
					if (s < t)
						++lo;
					else if (s > t)
						--hi;
					else
					{
						result.push_back({ nums[i], nums[lo], nums[hi], nums[j] });
						while (++lo < hi && nums[lo - 1] == nums[lo]);
						while (lo < --hi && nums[hi + 1] == nums[hi]);
					}
				}
				while (j > i + 2 && nums[j - 1] == nums[j]) --j;
			}
			while (i < n - 3 && nums[i + 1] == nums[i]) ++i;
		}

		return result;
	}
};


int main()
{
	vector<int> v = { 1, 0, -1, 0, -2, 2 };
	auto r = Solution().fourSum(v, 0);
	for (const auto& ri : r)
	{
		copy(begin(ri), end(ri), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
    return 0;
}

