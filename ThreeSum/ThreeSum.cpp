
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//vector<vector<int>> threeSum(vector<int>& nums)
//{
//	vector<vector<int>> result;
//	sort(begin(nums), end(nums)); // n*log(n)
//	int l = 0, r = nums.size() - 1;
//	while (l < r)
//	{
//		int a = nums[l];
//		int c = nums[r];
//
//		int b = -a - c;
//
//		if (binary_search(begin(nums) + l + 1, begin(nums) + r, b))
//			result.push_back({ a, b, c });
//
//		int l1 = l; int r1 = r;
//
//		while (l1 < r && nums[l1] == a)
//			++l1;
//		while (l < r1 && nums[r1] == c)
//			--r1;
//
//		r = r1;
//		/*if (abs(nums[l] - nums[l1]) < abs(nums[r] - nums[r1]))
//		l = l1;
//		else
//		r = r1;*/
//
//		/*
//		if (b > 0)
//		{
//		while (l < r && nums[l] == a)
//		++l;
//		}
//		else // if (a + c >= 0)
//		{
//		while (l < r && nums[r] == c)
//		--r;
//		}
//		*/
//	}
//	return result;
//}

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> result;
		sort(begin(nums), end(nums)); // n*log(n)
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int l = i+1, r = n - 1;
			while (l < r)
			{
				int s = nums[i] + nums[l] + nums[r];
				if (s > 0)
					--r;
				else if (s < 0)
					++l;
				else
				{
					result.push_back({ nums[i], nums[l], nums[r] });
					while (l < r && nums[l] == nums[l + 1])
						++l;
					while (l < r && nums[r] == nums[r - 1])
						--r;
					++l; --r;
				}
			}
		}
		return result;
	}
};

int main()
{
	//vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	//vector<int> nums = { -2,0,1,1,2 };
	//vector<int> nums = { 0,0,0,0 };
	vector<int> nums = { -4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6 };
	auto r = Solution().threeSum(nums);
	for (int i = 0; i < r.size(); ++i)
		cout << r[i][0] << " " << r[i][1] << " " << r[i][2] << endl;

    return 0;
}

