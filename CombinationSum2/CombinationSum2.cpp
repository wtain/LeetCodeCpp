
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/combination-sum-ii/

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
[1,2,2],
[5]
]
*/

class Solution {
public:

	void combinationSum2impl(vector<vector<int>>& result, const vector<int>& candidates, vector<int>& current, int target, int startIndex) {
		if (!target) {
			result.push_back(current);
			return;
		}
		for (int i = startIndex; i < candidates.size(); ++i) {
			if (target < candidates[i])
				continue;
			if (i > startIndex && candidates[i - 1] == candidates[i])
				continue;
			current.push_back(candidates[i]);
			combinationSum2impl(result, candidates, current, target - candidates[i], i + 1);
			current.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		sort(begin(candidates), end(candidates));
		vector<int> current;
		combinationSum2impl(result, candidates, current, target, 0);
		return result;
	}
};

void printSolution(const vector<vector<int>>& v) {
	for (const auto& c : v) {
		copy(begin(c), end(c), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << endl;
}

int main()
{
	printSolution(Solution().combinationSum2(vector<int>{10, 1, 2, 7, 6, 1, 5}, 8));
	/*
	[1, 7],
	[1, 2, 5],
	[2, 6],
	[1, 1, 6]
	*/
	printSolution(Solution().combinationSum2(vector<int>{2, 5, 2, 1, 2}, 5));
	/*
	[1,2,2],
	[5]
	*/
    return 0;
}

