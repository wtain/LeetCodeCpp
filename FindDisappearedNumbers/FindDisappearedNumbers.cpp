
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> rv;
		for (int i = 0; i < nums.size(); ++i)
		{
			int index = abs(nums[i]) - 1;
			if (nums[index] > 0)
				nums[index] = -nums[index];
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > 0)
				rv.push_back(i + 1);
		}
		return rv;
	}
};

int main()
{
	vector<int> v = { 4,3,2,7,8,2,3,1 };
	auto r = Solution().findDisappearedNumbers(v);
	copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
	cout << endl;

    return 0;
}

