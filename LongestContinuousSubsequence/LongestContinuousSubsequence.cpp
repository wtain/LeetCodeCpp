
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) 
	{
		int n = nums.size();
		if (!n)
			return 0;

		int longest = 1;
		int current = 1;
		
		for (int i = 1; i < n; ++i)
		{
			if (nums[i] > nums[i - 1])
			{
				++current;
				longest = max(longest, current);
			}
			else
				current = 1;
		}
		return longest;
	}
};

int main()
{
	vector<int> v1 = { 1,3,5,4,7 }; // 3
	vector<int> v2 = { 2,2,2,2,2 }; // 1
	vector<int> v3;

	cout << Solution().findLengthOfLCIS(v1) << endl; // 3
	cout << Solution().findLengthOfLCIS(v2) << endl; // 1
	cout << Solution().findLengthOfLCIS(v3) << endl; // 0

    return 0;
}

