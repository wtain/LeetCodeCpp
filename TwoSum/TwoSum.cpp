
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:

	class Comparator
	{
		const vector<int>& nums;
	public:
		explicit Comparator(const vector<int>& nums)
			: nums(nums)
		{

		}

		bool operator() (const int i, const int j) const
		{
			return nums[i] < nums[j];
		}
	};

	class Predicate
	{
		const vector<int>& nums;
		const int v;
	public:
		Predicate(const vector<int>& nums, const int v)
			: nums(nums)
			, v(v)
		{

		}

		bool operator() (const int i) const
		{
			return nums[i] == v;
		}
	};

	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> idx;
		int i = 0;
		idx.reserve(nums.size());
		generate_n(back_inserter(idx), nums.size(), [&i] { return i++; });
		sort(begin(idx), end(idx), Comparator(nums));
		
		for (int i = 0; i < nums.size(); ++i)
		{
			int target2 = target - nums[idx[i]];
			auto it2 = find_if(begin(idx) + i + 1, end(idx), Predicate(nums, target2));
			if (end(idx) != it2)
			{
				vector<int> rv = {idx[i], *it2};
				return rv;
			}
		}
		return vector<int>();
	}
};

//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		for (int i = 0; i < nums.size() - 1; ++i)
//		{
//			for (int j = i + 1; j < nums.size(); ++j)
//			{
//				if (nums[i] + nums[j] == target)
//				{
//					return vector<int> { i, j };
//				}
//			}
//		}
//		return vector<int>();
//	}
//};

int main()
{
	//vector<int> v = {2, 7, 11, 15};
	vector<int> v = { 3, 2, 4 };
	Solution s;
	
	//auto r = s.twoSum(v, 9 /*6*/);
	auto r = s.twoSum(v, 6);
	copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
	cout << endl;

    return 0;
}

