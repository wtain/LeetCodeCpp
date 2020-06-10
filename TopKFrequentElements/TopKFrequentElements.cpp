
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ? k ? number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:

	struct NumberAndFrequency
	{
		int Number;
		int Frequency;

		NumberAndFrequency(int n, int f)
			: Number(n)
			, Frequency(f) {}
	};

	struct Compare
	{
		bool operator() (const NumberAndFrequency& l, const NumberAndFrequency& r)
		{
			return l.Frequency < r.Frequency;
		}
	};

	vector<int> topKFrequent(vector<int>& nums, int k) 
	{
		unordered_map<int, int> freqs;
		for (const auto v : nums) // n .. O(n)
		{
			auto it = freqs.find(v); // O(1*)
			if (it == end(freqs))
				freqs.emplace_hint(it, make_pair(v, 1)); // O(1*)
			else
				++it->second;
		}
		vector<NumberAndFrequency> h;
		h.reserve(freqs.size());
		for (const auto& p : freqs) // O(m) m - unique
			h.push_back(NumberAndFrequency(p.first, p.second));

		// No need to construct the whole heap - we can maintain heap of size K

		make_heap(begin(h), end(h), Compare()); // O(n)
		vector<int> result;
		result.reserve(k);
		for (int i = 0; i < k; ++i) // k .. O(k*log(n))
		{
			pop_heap(begin(h), end(h), Compare()); // O(log(n))
			result.push_back(h.back().Number); h.pop_back();
		}
		return result;
	}
};

int main()
{
	vector<int> nums = { 1, 1, 1, 2, 2, 3 };
	auto r = Solution().topKFrequent(nums, 2);

    return 0;
}

