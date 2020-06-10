
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*

https://leetcode.com/problems/permutations-ii/

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
[1,1,2],
[1,2,1],
[2,1,1]
]

*/

//class Solution {
//public:
//
//	struct pairhash {
//	public:
//		template <typename T, typename U>
//		std::size_t operator()(const std::pair<T, U> &x) const
//		{
//			return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
//		}
//	};
//
//	typedef unordered_set<pair<int, int>, pairhash> UsedHashtable;
//
//	void permuteUniqueImpl(vector<vector<int>>& result, vector<int>& nums, vector<int>& current, UsedHashtable& used, unordered_map<int, int>& counts)
//	{
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			pair<int, int> ni_on_current = { nums[i], current.size() };
//			auto it = used.find(ni_on_current);
//			if (it != end(used))
//				continue;
//			if (!counts[nums[i]])
//				continue;
//
//			counts[nums[i]]--;
//			//it = used.insert(it, ni_on_current);
//			current.push_back(nums[i]);
//			if (current.size() == nums.size())
//				result.push_back(current); 
//			else
//				permuteUniqueImpl(result, nums, current, used, counts);
//			current.pop_back();
//
//			counts[nums[i]]++;
//			//used.erase(it);
//			it = used.insert(it, ni_on_current);
//		}
//	}
//
//	vector<vector<int>> permuteUnique(vector<int>& nums) 
//	{
//		vector<vector<int>> result;
//		UsedHashtable used;
//		unordered_map<int, int> counts;
//		vector<int> current;
//		for (auto i : nums)
//			counts[i]++;
//		permuteUniqueImpl(result, nums, current, used, counts);
//
//		return result;
//	}
//};

class Solution {
public:

	void permuteUniqueImpl(vector<vector<int>>& result, vector<int>& nums, vector<int>& current, unordered_map<int, int>& counts)
	{
		for (auto& p: counts)
		{
			const auto pi = p.first;
			if (!p.second)
				continue;

			p.second--;
			current.push_back(pi);
			if (current.size() == nums.size())
				result.push_back(current);
			else
				permuteUniqueImpl(result, nums, current, counts);

			current.pop_back();
			p.second++;
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		vector<vector<int>> result;
		unordered_map<int, int> counts;
		vector<int> current;
		for (auto i : nums)
			counts[i]++;
		permuteUniqueImpl(result, nums, current, counts);

		return result;
	}
};

int main()
{
	vector<int> nums = { 1, 1, 2 };
	auto pms = Solution().permuteUnique(nums);
	for (const auto& pm : pms)
	{
		copy(begin(pm), end(pm), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

    return 0;
}

