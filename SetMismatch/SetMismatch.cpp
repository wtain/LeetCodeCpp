
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) 
	{
		/*
		const int n = nums.size();
		const int expectedSum = (n * (n + 1)) >> 1;
		int sum = accumulate(begin(nums), end(nums), 0);
		int diff = expectedSum - sum;

		int i = 0;
		while (nums[i] > 0)
		{
			int index = nums[i] - 1;
			nums[i] = -nums[i];
			if (i == index)
				++i;
			else
				swap(nums[i], nums[index]);
		}

		return{-nums[i], -nums[i] + diff};
		*/
		const int n = nums.size();
		int dup = -1;
		int missing = 1;
		for (int i = 0; i < n; ++i)
		{
			if (nums[abs(nums[i]) - 1] < 0)
				dup = abs(nums[i]);
			else
				nums[abs(nums[i]) - 1] *= -1;
		}
		for (int i = 0; i < n; ++i)
			if (nums[i] > 0)
				missing = i + 1;
		return{ dup, missing };
	}
};

int main()
{
	//vector<int> v = { 1,2,2,4 }; // 2 3
	vector<int> v = { 2, 3, 2 }; // 2 1
	auto r = Solution().findErrorNums(v);
	cout << r[0] << " " << r[1] << endl;

    return 0;
}

