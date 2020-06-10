
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/k-closest-points-to-origin/
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3345/

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)



Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)


Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
*/

//Runtime: 400 ms, faster than 56.10% of C++ online submissions for K Closest Points to Origin.
//Memory Usage : 50.9 MB, less than 28.13% of C++ online submissions for K Closest Points to Origin.
//class Solution {
//public:
//
//	struct Compare {
//
//		static long dist2(const pair<int, int>& p) {
//			return p.first * p.first + p.second * p.second;
//		}
//
//		bool operator() (const pair<int, int>& l, const pair<int, int>& r) const {
//			return dist2(l) < dist2(r);
//		}
//
//	};
//
//	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> closest;
//
//		for (const auto& p : points) {
//			closest.emplace(p[0], p[1]);
//			if (closest.size() > K)
//				closest.pop();
//		}
//
//		vector<vector<int>> result;
//		result.reserve(closest.size());
//		while (!closest.empty()) {
//			const auto& r = closest.top();
//			result.emplace_back(vector<int>{r.first, r.second});
//			closest.pop();
//		}
//		return result;
//	}
//};

//Runtime: 504 ms, faster than 38.43% of C++ online submissions for K Closest Points to Origin.
//Memory Usage : 51.6 MB, less than 28.13% of C++ online submissions for K Closest Points to Origin.
//class Solution {
//public:
//
//	struct Compare {
//
//		static long dist2(const vector<int>& p) {
//			return p[0] * p[0] + p[1] * p[1];
//		}
//
//		bool operator() (const vector<int>& l, const vector<int>& r) const {
//			return dist2(l) < dist2(r);
//		}
//
//	};
//
//	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//		vector<vector<int>> result;
//		result.reserve(K + 1);
//		auto cmp = Compare();
//		for (const auto& p : points) {
//			
//			result.push_back(p);
//			push_heap(begin(result), end(result), cmp);
//
//			if (result.size() > K) {
//				pop_heap(begin(result), end(result), cmp);
//				result.pop_back();
//			}
//		}
//		return result;
//	}
//};

//Runtime: 508 ms, faster than 37.91% of C++ online submissions for K Closest Points to Origin.
//Memory Usage : 49.2 MB, less than 34.38% of C++ online submissions for K Closest Points to Origin.
class Solution {
public:

	struct Compare {

		static long dist2(const vector<int>& p) {
			return p[0] * p[0] + p[1] * p[1];
		}

		bool operator() (const vector<int>& l, const vector<int>& r) const {
			return dist2(l) < dist2(r);
		}

	};

	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

		partial_sort(begin(points), begin(points) + K, end(points), Compare());

		vector<vector<int>> result;
		result.reserve(K);
		copy_n(begin(points), K, back_inserter(result));
		return result;
	}
};

void print(const vector<vector<int>>& result) {
	for (const auto& r : result)
		cout << "(" << r[0] << " " << r[1] << ")";
	cout << endl;
}

int main()
{
	print(Solution().kClosest(vector<vector<int>>{ {1, 3}, { -2, 2 } }, 1)); // [[-2,2]]
	print(Solution().kClosest(vector<vector<int>>{ {3, 3}, { 5, -1 }, {-2, 4 } }, 2)); // [[3,3],[-2,4]]

    return 0;
}

