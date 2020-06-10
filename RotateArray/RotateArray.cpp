
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
	// 1 2 3 4 5
	// 3 4 5 1 2
	// 1 2 3 4 5 6
	// 5 6 1 2 3 4
	void rotate(vector<int>& nums, int k) {
		if (nums.empty())
			return;
		k %= nums.size();
		if (!k)
			return;
		int n = nums.size();
		vector<bool> moved(n, false);
		int nMoved = 0;
		int j = 0;
		while (nMoved < n)
		{
			int i0 = j;
			int v = nums[i0];
			int i = i0;
			do
			{
				i += k;
				i %= n;
				int tmp = nums[i];
				++ nMoved;
				nums[i] = v;
				v = tmp;
			} 
			while (i != i0 && nMoved < n);
			++j;
		}
	}
};

void test(vector<int>& nums, int k)
{
	Solution().rotate(nums, k);
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	test(vector<int>{ 1, 2, 3, 4, 5 }, 3);
	test(vector<int>{ 1, 2, 3, 4, 5, 6 }, 2);


    return 0;
}

