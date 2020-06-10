
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) 
	{
		int result = 0;
		int resultDiff = numeric_limits<int>::max();
		sort(begin(nums), end(nums));
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			int l = i + 1, r = n - 1;
			while (l < r)
			{
				int s = nums[i] + nums[l] + nums[r];
				int diff = abs(target - s);
				if (resultDiff > diff)
				{
					resultDiff = diff;
					result = s;
					if (!resultDiff) ///
						break;       ///
				}
				if (s > target)
					--r;
				else if (s < target)
					++l;
				else
					break;
			}
			if (!resultDiff)
				break;
		}
		return result;
	}
};

int main()
{
	//vector<int> nums = { -1, 2, 1, -4 };
	//cout << Solution().threeSumClosest(nums, 1) << endl; // 2

	vector<int> nums = { 0, 1, 2 };
	cout << Solution().threeSumClosest(nums, 3) << endl; // 3

    return 0;
}

