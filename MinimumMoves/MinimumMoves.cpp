
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
	int minMoves(vector<int>& nums) 
	{
		// n*x = sum(a) + (n-1) * m
		
		// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
		// x=4, n=3, m=3, sum(a)=6
		// 3*4 = 6 + 2 * 3
		// m = (n*x - sum(a)) / (n-1)
		// n*x - sum(a) = k*(n-1)
		// n*(x-k)=sum(a)-k

		// min(a) + m = x
		// n*(min(a)+m) = sum(a) + (n-1)*m
		// n*m+n*min(a) = sum(a) + (n-1)*m
		// m = sum(a)-n*min(a)

		int n = nums.size();
		int s = accumulate(begin(nums), end(nums), 0);
		int Amin = *minmax_element(begin(nums), end(nums)).first;
		return s - n * Amin;
	}
};

int main()
{
	vector<int> a = { 1,2,3 };
	cout << Solution().minMoves(a) << endl; // 3

    return 0;
}

