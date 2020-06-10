
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//	int maxProduct(vector<int>& nums) 
//	{
//		const size_t n = nums.size();
//		if (!n)
//			return 0;
//		vector<int> maxPos(n, 0);
//		vector<int> maxNeg(n, 0);
//
//		int maxP = nums[0];
//
//		if (nums[0] > 0)
//			maxPos[0] = nums[0];
//		else
//			maxNeg[0] = nums[0];
//
//		for (int i = 1; i < n; ++i)
//		{
//			if (nums[i] > 0)
//			{
//				maxPos[i] = max(maxPos[i - 1] * nums[i], nums[i]);
//				maxNeg[i] = min(maxNeg[i - 1] * nums[i], nums[i]);
//			}
//			else
//			{
//				maxPos[i] = max(maxNeg[i - 1] * nums[i], nums[i]);
//				maxNeg[i] = min(maxPos[i - 1] * nums[i], nums[i]);
//			}
//			if (maxPos[i] > maxP)
//				maxP = maxPos[i];
//		}
//
//		return maxP;
//	}
//};

class Solution {
public:
	int maxProduct(vector<int>& nums)
	{
		const int n = nums.size();
		if (!n)
			return 0;
		int maxP = 0, maxN = 0;
		if (nums[0] > 0)
			maxP = nums[0];
		else
			maxN = nums[0];

		int maxPRD = nums[0];

		for (int i = 1; i < n; ++i)
		{
			if (nums[i] > 0)
			{
				maxP = max(maxP*nums[i], nums[i]);
				maxN = min(maxN*nums[i], nums[i]);
			}
			else
			{
				int maxP1 = max(maxN*nums[i], nums[i]);
				int maxN1 = min(maxP*nums[i], nums[i]);
				maxP = maxP1;
				maxN = maxN1;
			}
			maxPRD = max(maxPRD, maxP);
		}

		return maxPRD;
	}
};

int main()
{
	vector<int> test1 = { 2,3,-2,4 }; // [2,3] = 6
	vector<int> test2 = { -2,0,-1 }; // [0] = 0
	vector<int> test3 = { -2,-1 }; // [-2,-1] = 2
	vector<int> test4 = { -2,2,-1 }; // [-2,2,-1] = 4
	vector<int> test5 = { -2 }; // [-2] = -2

	cout << Solution().maxProduct(test1) << endl;
	cout << Solution().maxProduct(test2) << endl;
	cout << Solution().maxProduct(test3) << endl;
	cout << Solution().maxProduct(test4) << endl;
	cout << Solution().maxProduct(test5) << endl;

    return 0;
}

