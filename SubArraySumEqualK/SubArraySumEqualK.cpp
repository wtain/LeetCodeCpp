
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>

using namespace std;

class Solution 
{
public:
	int subarraySum(vector<int>& nums, int k) 
	{
		const size_t n = nums.size();
		if (!n)
			return -1;
		vector<int> sums(n);
		partial_sum(begin(nums), end(nums), begin(sums));

		/*
			A: a1 a2 a3 ... aN
			S: s1 s2 s3 ... sN

			subarray(i1, i2) sum = S(i2) - S(i1-1) = K

			S(i2) = K + S(i1-1) -> count()
			S(-1) =def= 0
		
		*/
		int cnt = 0;
		for (size_t i = 0; i < n; ++i)
		{
			if (sums[i] == k)
				++cnt;
			int remainder = k + sums[i];
			cnt += count(begin(sums) + i + 1, end(sums), remainder);
		}
		return cnt;
	}
};

void PrintArray(const vector<int>& nums)
{
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ","));
	cout << endl;
}

void RunTest(vector<int>& nums, int k)
{
	PrintArray(nums);
	cout << Solution().subarraySum(nums, k) << endl;
}

typedef vector<int> V;

int main()
{
	RunTest(V({ 1, 1, 1 }), 2); // 2
	RunTest(V({ 1, 1, 1 }), 1); // 3
	RunTest(V({ 1, 0, 1 }), 1); // 4
	RunTest(V({ 1, 0, 1, -1 }), 1); // 5
	/*
			[1], 0, 1, -1
			[1, 0], 1, -1
			[1, 0, 1, -1]
			1, [0, 1], -1
			1, 0, [1], -1
	*/
		
    return 0;
}
