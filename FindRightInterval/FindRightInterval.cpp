
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>

using namespace std;

/*
https://leetcode.com/problems/find-right-interval/
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3438/
Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:

You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.


Example 1:

Input: [ [1,2] ]

Output: [-1]

Explanation: There is only one interval in the collection, so it outputs -1.


Example 2:

Input: [ [3,4], [2,3], [1,2] ]

Output: [-1, 0, 1]

Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.


Example 3:

Input: [ [1,4], [2,3], [3,4] ]

Output: [-1, 2, -1]

Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

//Runtime: 156 ms, faster than 89.38% of C++ online submissions for Find Right Interval.
//Memory Usage : 28 MB, less than 57.71% of C++ online submissions for Find Right Interval.
class Solution {
public:

	class Interval {
		int p_start, p_end;
		int index;
	public:
		Interval(int s, int e, int idx) : p_start(s), p_end(e), index(idx) {}

		bool operator< (const Interval& right) const {
			return p_start < right.p_start;
		}

		int Start() const { return p_start; }

		int End() const { return p_end; }

		int Index() const { return index; }
	};

	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		const int n = intervals.size();
		vector<int> result(n, -1);

		/*for (int i = 0; i < n; ++i) {
			int idx = -1;
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				if (intervals[i][1] <= intervals[j][0] && (idx == -1 || idx != -1 && j < idx))
					idx = j;
			}
			result[i] = idx;
		}*/

		//set<Interval> ints;
		map<int, Interval> ints;
		//transform(begin(intervals), end(intervals), back_inserter(ints), (const auto& v) { return Interval() })
		for (int i = 0; i < n; ++i) {
			//ints.emplace(intervals[i][0], intervals[i][1], i);
			ints.emplace(make_pair(intervals[i][0], Interval(intervals[i][0], intervals[i][1], i)));
		}

		for (auto it = begin(ints); it != end(ints); ++it) {
			/*auto it2 = it;
			if (++it2 == end(ints))
				continue;

			if (it2->Start() < it->End())
				continue;

			result[it->Index()] = it2->Index();*/

			auto it2 = ints.lower_bound(it->second.End());
			if (it2 == end(ints))
				continue;

			result[it->second.Index()] = it2->second.Index();
		}

		return result;
	}
};

void print(const vector<int>& v) {
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	
	print(Solution().findRightInterval(vector<vector<int>>{ {1, 12}, { 2, 9 }, { 3, 10 }, { 13, 14 }, { 15, 16 }, { 16, 17 }})); // [3,3,3,4,5,-1]
	print(Solution().findRightInterval(vector<vector<int>>{ {1, 4 }, { 2,3 }, {3,4} })); // -1 2 -1
	print(Solution().findRightInterval(vector<vector<int>>{ {1,2 } })); // -1
	print(Solution().findRightInterval(vector<vector<int>>{ {3, 4}, { 2,3 }, {1,2} })); // -1 0 1
	print(Solution().findRightInterval(vector<vector<int>>{ {1, 4}, { 2,3 }, { 3,4 } })); // -1 2 -1

    return 0;
}

