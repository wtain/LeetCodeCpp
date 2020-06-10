
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class NumArray {
	size_t n;
	vector<int> ps;
public:
	NumArray(vector<int> nums) 
		: n(nums.size())
		, ps(n)
	{
		partial_sum(begin(nums), end(nums), begin(ps));
	}

	int sumRange(int i, int j) {
		int s = ps[j];
		if (i > 0)
			s -= ps[i - 1];
		return s;
	}
};

int main()
{
	NumArray obj ({ -2, 0, 3, -5, 2, -1 });
	cout << obj.sumRange(0, 2) << endl;
	cout << obj.sumRange(2, 5) << endl;
	cout << obj.sumRange(0, 5) << endl;

    return 0;
}

