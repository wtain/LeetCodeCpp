
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/interval-list-intersections/
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3338/

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)



Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.


Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

//Runtime: 64 ms
//Memory Usage : 18.7 MB
//class Solution {
//public:
//	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
//		vector<vector<int>> result;
//		
//		auto i1 = begin(A), e1 = end(A), i2 = begin(B), e2 = end(B);
//		while (i1 != e1 && i2 != e2) {
//			auto& j1 = (*i1)[0] < (*i2)[0] ? i1 : i2;
//			auto& j2 = (*i1)[0] < (*i2)[0] ? i2 : i1;
//
//			if ((*j1)[1] < (*j2)[1]) {
//				if ((*j2)[0] <= (*j1)[1])
//					result.push_back(vector<int>{ (*j2)[0], (*j1)[1] });
//				++j1;
//			}
//			else {
//				//if ((*j2)[0] <= (*j2)[1])
//					result.push_back(vector<int>{ (*j2)[0], (*j2)[1] });
//				++j2;
//			}
//		}
//
//		return result;
//	}
//};

//Runtime: 68 ms, faster than 56.07% of C++ online submissions for Interval List Intersections.
//Memory Usage : 18.8 MB, less than 8.00% of C++ online submissions for Interval List Intersections.
class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<vector<int>> result;

		const size_t n1 = A.size(), n2 = B.size();
		size_t i1 = 0, i2 = 0;
		while (i1 < n1 && i2 < n2) {
			int low = max(A[i1][0], B[i2][0]);
			int high = min(A[i1][1], B[i2][1]);

			if (low <= high)
				result.push_back(vector<int>{low, high});

			if (A[i1][1] < B[i2][1])
				++i1;
			else
				++i2;
		}

		return result;
	}
};

void printSolution(const vector<vector<int>>& intervals) {
	for (const auto& interval : intervals)
		cout << "[" << interval[0] << "," << interval[1] << "] ";
	cout << endl;
}

int main()
{
	printSolution(Solution().intervalIntersection(
		vector<vector<int>>{ {0, 2}, { 5,10 }, { 13,23 }, { 24,25 }}, 
		vector<vector<int>>{ { 1,5 },{ 8,12 },{ 15,24 },{ 25,26 } })); // [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

	printSolution(Solution().intervalIntersection(
		vector<vector<int>>{ { 3, 10} },
		vector<vector<int>>{ { 5, 10 } })); // [[5,10]]

    return 0;
}

