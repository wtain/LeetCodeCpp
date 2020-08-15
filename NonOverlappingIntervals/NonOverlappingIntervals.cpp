
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/non-overlapping-intervals/
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3425/
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.



Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.


Note:

You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
*/

//class Solution {
//public:
//
//	struct Node {
//		int i1, i2;
//		int cnt;
//
//		explicit Node(const vector<int>& v) 
//			: i1(v[0]), i2(v[1]), cnt(1) {
//
//		}
//
//		Node(int i1_, int i2_, int cnt_)
//			: i1(i1_), i2(i2_), cnt(cnt_) {}
//	};
//
//	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//		sort(begin(intervals), end(intervals), [](const auto& i1, const auto& i2) { return i1[0] != i2[0] ? i1[0] < i2[0] : i1[1] < i2[1]; });
//		const int n = intervals.size();
//		/ *const int m = 1 << n;
//		int maxIntervals = 0;
//		for (int i = 0; i < m; ++i) {
//			int mask = 1;
//			for (int j = 0; j < n; ++j, mask <<= 1) {
//				if (!(i & mask))
//					continue;
//
//			}
//		}
//		return n - maxIntervals; */
//		/ *int maxIntervals = 1;
//		int prev
//		for (int i = 1; i < n; ++i) {
//
//		}* /
//		vector<Node> nodes;
//		nodes.reserve(n);
//		for (int i = 0; i < n; ++i)
//			nodes.emplace_back(intervals[i]);
//		while (nodes.size() > 1) {
//			vector<Node> nextNodes;
//			nextNodes.reserve(nodes.size() / 2 + 1);
//			for (int i = 0; i < n; i += 2) {
//				int i1 = i, i2 = i + 1;
//				if (i2 == n) {
//					nextNodes.push_back(nodes[i1]);
//				}
//				else {
//					if (nodes[i2].i1 >= nodes[i1].i2)
//						nextNodes.emplace_back(nodes[i1].i1, nodes[i2].i2, nodes[i1].cnt + nodes[i2].cnt);
//					else { // MERGE!
//						cout << "!" << endl;
//					}
//				}
//			}
//			nodes.swap(nextNodes);
//		}
//		return n - nodes[0].cnt;
//	}
//};

// todo: segment tree!

//Runtime: 32 ms, faster than 81.27% of C++ online submissions for Non - overlapping Intervals.
//Memory Usage : 10.3 MB, less than 67.77% of C++ online submissions for Non - overlapping Intervals.
class Solution {
public:

	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		sort(begin(intervals), end(intervals), [](const auto& i1, const auto& i2) { return i1[0] != i2[0] ? i1[0] < i2[0] : i1[1] < i2[1]; });
		const int n = intervals.size();
		if (!n)
			return 0;
		int lastEnd = intervals[0][0];
		int maxNoOverIntervals = 0;
		for (int i = 0; i < n; ++i) {
			if (lastEnd > intervals[i][0])
				lastEnd = min(lastEnd, intervals[i][1]);
			else {
				++maxNoOverIntervals;
				lastEnd = intervals[i][1];
			}
		}
		return n - maxNoOverIntervals;
	}
};

int main()
{
	cout << Solution().eraseOverlapIntervals(vector<vector<int>>{
		{1,2}, { 2,3 }, { 3,4 }, { 1,3 }
	}) << endl; // 1

	cout << Solution().eraseOverlapIntervals(vector<vector<int>>{
		{1, 2}, { 1, 2 }, { 1, 2 }
	}) << endl; // 2

	cout << Solution().eraseOverlapIntervals(vector<vector<int>>{
		{1, 2}, { 2, 3 }
	}) << endl; // 0

    return 0;
}

