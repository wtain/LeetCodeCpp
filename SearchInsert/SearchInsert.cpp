
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		auto b = begin(nums), e = end(nums);
		while (b != e)
		{
			auto m = b + distance(b, e) / 2;
			if (*m == target)
				return distance(begin(nums), m);
			if (*m > target)
				e = m;
			else
				b = m + 1;
		}
		return distance(begin(nums), b);
	}
};


int main()
{
	vector<int> v = { 1, 3, 5, 6 };
	cout << Solution().searchInsert(v, 2) << endl;

    return 0;
}

