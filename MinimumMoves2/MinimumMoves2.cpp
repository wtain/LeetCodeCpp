
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
	int minMoves2(vector<int>& nums) 
	{
		sort(begin(nums), end(nums));
		int n = nums.size();
		int n2 = n / 2;
		int m = nums[n2];
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			cnt += abs(nums[i] - m);
		return cnt;
	}
};

int main()
{
	vector<int> a = { 1,2,3 };
	cout << Solution().minMoves2(a) << endl; // 2
    return 0;
}

