
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:

	void subsetsImpl(vector<vector<int>>& results, const vector<int>& nums)
	{
		const int n = nums.size();
		int maskMax = (1 << n) - 1;
		for (int mask = 0; mask <= maskMax; ++mask)
		{
			vector<int> subset;
			for (int j = 0; j < n; ++j)
			{
				if (mask & (1 << j))
					subset.push_back(nums[j]);
			}
			results.push_back(subset);
		}
	}

	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> results;
		subsetsImpl(results, nums);
		return results;
	}
};

/*
0 0 0
0 0 1

*/

int main()
{
	vector<int> nums = { 1, 2, 3 };
	const auto subsets = Solution().subsets(nums);
	for (const auto& subset : subsets)
	{
		cout << "[";
		copy(begin(subset), end(subset), ostream_iterator<int>(cout, ","));
		cout << "]";
		cout << endl;
	}
    return 0;
}

