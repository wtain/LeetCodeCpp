
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

/*
vector<int> r;
int i = 0;
int n = nums.size();
int cnt = 0;
while (cnt < n)
{
for (i = 0; i < n; ++i)
if (nums[i] > 0)
break;
while (nums[i] > 0)
{
int index = nums[i] - 1;
nums[i] = -nums[i];
++cnt;
i = index;
}
r.push_back(i + 1);
}
return r;
*/

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) 
	{
		vector<int> r;
		int i = 0;
		while (i < nums.size())
		{
			if (nums[i] != nums[nums[i] - 1])
				swap(nums[i], nums[nums[i] - 1]);
			else
				++i;
		}
		for (i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				r.push_back(nums[i]);
		return r;
	}
};

int main()
{
	vector<int> v = { 4,3,2,7,8,2,3,1 };
	auto r = Solution().findDuplicates(v);
	copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
	cout << endl;

    return 0;
}

