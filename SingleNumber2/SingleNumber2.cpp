#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) 
	{
		int result = 0;
		int mask = 1;
		for (int b = 0; b < 32; ++b)
		{
			int cnt = 0;
			for (const auto vi : nums)
			{
				if (vi & mask)
				{
					++cnt;
					cnt %= 3;
				}
			}
			if (cnt)
				result |= mask;
			mask <<= 1;
		}
		return result;
	}
};

int main()
{
	vector<int> v1 = { 2,2,3,2 };
	cout << Solution().singleNumber(v1) << endl; // 3
	vector<int> v2 = { 0,1,0,1,0,1,99 };
	cout << Solution().singleNumber(v2) << endl; // 99
    return 0;
}

