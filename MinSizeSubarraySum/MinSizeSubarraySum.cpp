
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) 
	{
		int i1 = 0, i2 = 0;
		int cs = 0;
		int minLen = nums.size();
		bool found = false;
		while (i1 < nums.size())
		{
			if (cs < s && i2 < nums.size())
				cs += nums[i2++];
			else
				cs -= nums[i1++];

			int len = i2 - i1;
			if (cs >= s && (minLen > len || !found))
			{
				minLen = len;
				found = true;
			}
		}
		return found ? minLen : 0;
	}
};

int main()
{
	//vector<int> nums = { 2,3,1,2,4,3 };
	//cout << Solution().minSubArrayLen(7, nums) << endl; // 2
	vector<int> nums = { 1,2,3,4,5 };
	cout << Solution().minSubArrayLen(15, nums) << endl; // 2

    return 0;
}

