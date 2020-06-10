
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> L(nums.size(), 1);

		int result = 1;
		for (size_t i = 1; i < nums.size(); ++i)
		{
			int mx = 0;
			for (size_t j = 0; j < i; ++j)
			{
				if (nums[j] >= nums[i])
					continue;
				mx = max(mx, L[j]);
			}
			L[i] = 1 + mx;
			result = max(result, L[i]);
		}
		return result;
	}
};

int main()
{
	Solution s;

	vector<int> v1 = { 10,9,2,5,3,4 };
	vector<int> v2 = { 1, 3, 6, 7, 9, 4, 10, 5, 6 };
	vector<int> v3 = { 10,9,2,5,3,7,101,18 };

	cout << s.lengthOfLIS(v1) << endl; // 3
	cout << s.lengthOfLIS(v2) << endl; // 6
	cout << s.lengthOfLIS(v3) << endl; // 4

    return 0;
}

