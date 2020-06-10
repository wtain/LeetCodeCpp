
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int n = nums.size() - 1;

		int i1 = 0;
		int i2 = 0;

		do
		{
			i1 = nums[i1];
			i2 = nums[nums[i2]];
		} while (i1 != i2);

		i1 = 0;

		while (i1 != i2)
		{
			i1 = nums[i1];
			i2 = nums[i2];
		}

		return i1;
	}
};


int main()
{
	//vector<int> v = { 4,3,1,4,2 };
	vector<int> v = { 2,2,2,2,2 };
	cout << Solution().findDuplicate(v) << endl;
    return 0;
}

