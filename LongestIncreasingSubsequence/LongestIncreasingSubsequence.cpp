
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//	int lengthOfLIS(vector<int>& nums) {
//		if (nums.empty())
//			return 0;
//		vector<int> L(nums.size(), 1);
//
//		for (size_t i = 1; i < nums.size(); ++i)
//		{
//			int mx = 0;
//			for (size_t j = 0; j < i; ++j)
//			{
//				if (nums[j] >= nums[i])
//					continue;
//				if (mx < L[j])
//					mx = L[j];
//			}
//			L[i] = 1 + mx;
//		}
//		return *max_element(begin(L), end(L));
//	}
//};

int main()
{
	// See MaxSortedSubArray

    return 0;
}

