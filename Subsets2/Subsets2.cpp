
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

/*
https://leetcode.com/problems/subsets-ii/

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]

*/

//class Solution {
//public:
//
//	void subsetsWithDupImpl(const vector<int>& nums, int i0, vector<vector<int>>& result) {
//		//if (i0 == nums.size())
//		//	return;
//		if (i0 == nums.size() - 1) {
//			result.push_back(vector<int>{});
//			result.push_back(vector<int>{nums[i0]});
//			return;
//		}
//		subsetsWithDupImpl(nums, i0 + 1, result);
//		const int n = result.size();
//		//if (i0 < nums.size() - 1 && nums[i0] != nums[i0+1])
//			for (int i = 0; i < n; ++i) {
//				const auto& r = result[i];
//				auto r1 = r;
//				r1.push_back(nums[i0]);
//				result.push_back(r1);
//			}
//	}
//
//	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//		vector<vector<int>> result;
//		sort(begin(nums), end(nums), greater<int>());
//		subsetsWithDupImpl(nums, 0, result);
//		return result;
//	}
//};

//class Solution {
//public:
//
//	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//		vector<vector<int>> result;
//		sort(begin(nums), end(nums));
//
//		const int n = nums.size();
//
//		vector<pair<int, int>> nums2;
//		for (int i = 0; i < n; ++i) {
//			if (i == 0 || nums[i] != nums[i - 1])
//				nums2.emplace_back(nums[i], 1);
//			else
//				nums2.back().second++;
//		}
//		
//		const int m = nums2.size();
//		
//		int maskMax = (1 << m) - 1;
//		for (int mask = 0; mask <= maskMax; ++mask) {
//			vector<int> subset;
//			for (int i = 0; i < m; ++i)
//				if (mask & (1 << i))
//					for (int j = 0; j < nums2[i].second; ++j)
//						subset.push_back(nums2[i].first);
//			result.push_back(subset);
//		}
//
//		return result;
//	}
//};

//Runtime: 12 ms, faster than 29.38% of C++ online submissions for Subsets II.
//Memory Usage : 8.4 MB, less than 28.99% of C++ online submissions for Subsets II.
class Solution {
public:

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		set<vector<int>> result;
		sort(begin(nums), end(nums));

		const int n = nums.size();

		int maskMax = (1 << n) - 1;
		for (int mask = 0; mask <= maskMax; ++mask) {
			vector<int> subset;
			for (int i = 0; i < n; ++i)
				if (mask & (1 << i))
					subset.push_back(nums[i]);
			result.insert(subset);
		}

		return vector<vector<int>>(begin(result), end(result));
	}
};

void print(const vector<vector<int>>& solution) {
	for (const auto& result : solution) {
		cout << "[";
		copy(begin(result), end(result), ostream_iterator<int>(cout, ","));
		cout << "]" << endl;
	}
	cout << endl << endl;
}

int main()
{
	print(Solution().subsetsWithDup(vector<int>{1,2,2}));
	print(Solution().subsetsWithDup(vector<int>{2, 2, 1}));

    return 0;
}

