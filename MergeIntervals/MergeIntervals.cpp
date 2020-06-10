
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

/*
https://leetcode.com/problems/merge-intervals/

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

class Solution {
public:

	struct IntervalCompare {
		bool operator() (const vector<int>& i1, const vector<int>& i2) const {
			return i1[0] < i2[0];
		}
	};

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		
		const size_t n = intervals.size();
		if (!n)
			return{};

		sort(begin(intervals), end(intervals), IntervalCompare());

		vector<vector<int>> result;
		result.reserve(intervals.size());
		result.push_back(intervals[0]);
		
		for (size_t i = 1; i < n; ++i) {
			vector<int>& last = result.back();
			vector<int>& current = intervals[i];
			if (current[0] > last[1])
				result.push_back(current);
			else
				last[1] = max(current[1], last[1]);
		}

		return result;
	}
};

void printIntervals(const vector<vector<int>>& intervals) {
	for (const auto& in : intervals)
		cout << "[" << in[0] << " " << in[1] << "] ";
	cout << endl;
}

int main()
{
	printIntervals(Solution().merge(vector<vector<int>>{ {1, 3}, { 2, 6 }, { 8, 10 }, { 15, 18 }})); // [[1,6],[8,10],[15,18]]
	printIntervals(Solution().merge(vector<vector<int>>{ {1, 4}, { 4, 5 } })); // [[1,5]]
	printIntervals(Solution().merge(vector<vector<int>>{ {1, 4}, { 2, 3 } })); // [[1,4]]

    return 0;
}

