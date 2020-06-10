
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxRotateFunction(vector<int>& A) 
	{
		if (A.empty())
			return 0;
		const int N = A.size();
		const int sum = accumulate(begin(A), end(A), 0);
		int F0 = 0;
		for (int i = 1; i < N; ++i)
			F0 += i * A[i];
		int maxF = F0;

		int Fprev = F0;
		for (int i = 1; i < N; ++i)
		{
			int sum1 = sum - A[i - 1];
			int F1 = Fprev + A[i-1] * (N-1) - sum1;
			maxF = max(maxF, F1);
			Fprev = F1;
		}
		return maxF;
	}
};

int main()
{
	vector<int> v = { 4, 3, 2, 6 };
	vector<int> v1 = { 4 };
	vector<int> v0;
	vector<int> v2 = { 4,15,14,3,14,-8,12,-9,17,-1,15,1,10,19,-7,15,8,7,-8,11 };

	cout << Solution().maxRotateFunction(v) << endl; // 26
	cout << Solution().maxRotateFunction(v1) << endl;
	cout << Solution().maxRotateFunction(v0) << endl;
	cout << Solution().maxRotateFunction(v2) << endl; // 1511

    return 0;
}

