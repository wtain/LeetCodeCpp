
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

/*
// Recursive
class Solution 
{
public:

	void combineImpl(vector<vector<int>>& results, int n, int k, const vector<int>& result, int start)
	{
		if (!k)
		{
			results.push_back(result);
			return;
		}
		for (int i = start; i < n; ++i)
		{
			auto r = result;
			r.push_back(i+1);
			combineImpl(results, n, k-1, r, i+1);
		}
	}

	vector<vector<int>> combine(int n, int k) 
	{
		vector<vector<int>> results;
		vector<int> result;
		combineImpl(results, n, k, result, 0);
		return results;
	}
};
*/

// Iterative
class Solution
{
public:

	void combineImpl(vector<vector<int>>& results, int n, int k, const vector<int>& result, int start)
	{
		if (!k)
		{
			results.push_back(result);
			return;
		}
		for (int i = start; i < n; ++i)
		{
			auto r = result;
			r.push_back(i + 1);
			combineImpl(results, n, k - 1, r, i + 1);
		}
	}

	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> results;
		vector<int> result;
		combineImpl(results, n, k, result, 0);
		return results;
	}
};

/*
         1 2 3 4
		 V V
		 V   V
		 V     V
		   V V
		   V   V
		     V V
*/

int main()
{
	const auto combinations = Solution().combine(4, 2);
	for (const auto& comb : combinations)
	{
		cout << "[";
		copy(begin(comb), end(comb), ostream_iterator<int>(cout, ","));
		cout << "]";
		cout << endl;
	}
    return 0;
}

