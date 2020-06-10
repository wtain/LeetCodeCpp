
#include <iostream>
#include <vector>

using namespace std;

/*
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
*/

/*
if (direction) // i1
{
if (i1 < i2)
{
p /= nums[i1++];
++cnt;
cout << i1 << " " << i2 << endl;
}
else
direction = false;
}
else // i2
{
if (i2 < n - 1 && nums[i2 + 1] * p < k)
{
p *= nums[i2 + 1];
++i2;
cout << i1 << " " << i2 << endl;
++cnt;
}
else
direction = true;
}
*/

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) 
	{
		int cnt = 0;
		const size_t n = nums.size();
		int i1 = 0, i2 = 0;
		int p = 1;
		for (int i1 = 0, i2 = 0; i2 < n; i2++)
		{
			p *= nums[i2];
			while (p >= k && i1 < i2)
				p /= nums[i1++];
			if (p < k)
				cnt += 1 + (i2 - i1);
		}
		return cnt;
	}
};

int main()
{
	vector<int> nums = { 10, 5, 2, 6 };
	/*
					     10				   10
						 10 5			   50
						    5				5
							5   2		   10
							5   2  6	   60
							    2  6	   12
								   6		6
							    2			2
	*/
	cout << Solution().numSubarrayProductLessThanK(nums, 100) << endl;
    return 0;
}

