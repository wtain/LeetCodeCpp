
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:

	void combinationSum3Impl(vector<vector<int>>& results, int k, int n, vector<int>& r, int min)
	{
		if (n < 0)
			return;
		if (!k)
		{
			if (!n)
				results.push_back(r);
			return;
		}
		for (int i = min; i <= 9; ++i)
		{
			r.push_back(i);
			combinationSum3Impl(results, k - 1, n - i, r, i+1);
			r.pop_back();
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) 
	{
		vector<vector<int>> results;
		vector<int> r;
		combinationSum3Impl(results, k, n, r, 1);
		return results;
	}
};

int main()
{
	//const auto combinations = Solution().combinationSum3(3, 7);	// [[1,2,4]]
	const auto combinations = Solution().combinationSum3(3, 9);	// [[1,2,6], [1,3,5], [2,3,4]]
	for (const auto& comb : combinations)
	{
		cout << "[";
		copy(begin(comb), end(comb), ostream_iterator<int>(cout, ","));
		cout << "]";
		cout << endl;
	}
    return 0;
}

