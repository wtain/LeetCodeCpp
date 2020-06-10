
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution 
{
public:

	void permuteImpl(vector<vector<int>>& out, const vector<int>& nums, vector<bool>& used, vector<int>& r)
	{
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			if (used[i])
				continue;

			r.push_back(nums[i]);
			if (r.size() == n)
			{
				out.push_back(r);
			}
			else
			{
				used[i] = true;
				permuteImpl(out, nums, used, r);
				used[i] = false;
			}
			r.pop_back();
		}
	}

	vector<vector<int>> permute(vector<int>& nums) 
	{
		vector<vector<int>> result;
		vector<int> r;
		vector<bool> used(nums.size(), false);
		permuteImpl(result, nums, used, r);
		return result;
	}
};

int main()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8 };
	auto pms = Solution().permute(nums);
	for (const auto& pm : pms)
	{
		copy(begin(pm), end(pm), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

    return 0;
}

