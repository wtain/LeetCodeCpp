
#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/possible-bipartition/
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3342/

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group.

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.



Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false


Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].
*/

// WRONG!
//class Solution {
//public:
//
//	struct Compare {
//		bool operator() (const vector<int>& v1, const vector<int>& v2) const {
//			return v1[0] < v2[0] || v1[0] == v2[0] && v1[1] < v2[1];
//		}
//	};
//
//	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
//		unordered_set<int> g1, g2;
//
//		sort(begin(dislikes), end(dislikes), Compare());
//
//		const size_t M = dislikes.size();
//		for (size_t i = 0; i < M; ++i) {
//			const auto& p = dislikes[i];
//			const int p1 = p[0];
//			const int p2 = p[1];
//
//			const bool p1_in_g1 = g1.find(p1) != end(g1);
//			const bool p1_in_g2 = g2.find(p1) != end(g2);
//			const bool p2_in_g1 = g1.find(p2) != end(g1);
//			const bool p2_in_g2 = g2.find(p2) != end(g2);
//
//			if (!p1_in_g1 && !p2_in_g1 &&
//				!p1_in_g2 && !p2_in_g2) {
//				g1.insert(p1);
//				g2.insert(p2);
//			}
//			else if (p1_in_g1 && !p2_in_g1 || 
//				    !p1_in_g2 && p2_in_g2) {
//				g1.insert(p1);
//				g2.insert(p2);
//			}
//			else if (p1_in_g2 && !p2_in_g2 ||
//				!p1_in_g1 && p2_in_g1) {
//				g1.insert(p2);
//				g2.insert(p1);
//			}
//			else
//				return false;
//		}
//		return true;
//	}
//};

//Runtime: 444 ms, faster than 38.62% of C++ online submissions for Possible Bipartition.
//Memory Usage : 69.7 MB, less than 14.29% of C++ online submissions for Possible Bipartition.
class Solution {
public:

	bool checkColor(int i, const unordered_map<int, vector<int>>& graph, unordered_map<int, int>& colors, int color) {
		auto it = colors.find(i);
		if (it != end(colors))
			return it->second == color;

		colors.emplace_hint(it, i, color);

		auto nit = graph.find(i);

		if (nit != end(graph)) {
			const auto& neighbors = nit->second;

			for (auto t : neighbors)
				if (!checkColor(t, graph, colors, 1 - color))
					return false;
		}

		return true;
	}

	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		unordered_map<int, vector<int>> graph;
		unordered_map<int, int> colors;

		for (const auto& edge : dislikes) {
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}

		for (int i = 1; i <= N; ++i)
			if (colors.find(i) == end(colors) && !checkColor(i, graph, colors, 0))
				return false;
		
		return true;
	}
};

int main()
{
	cout << boolalpha << Solution().possibleBipartition(50, vector<vector<int>>{ {21, 47}, { 4,41 }, { 2,41 }, { 36,42 }, { 32,45 }, { 26,28 }, { 32,44 }, { 5,41 }, { 29,44 }, { 10,46 }, { 1,6 }, { 7,42 }, { 46,49 }, { 17,46 }, { 32,35 }, { 11,48 }, { 37,48 }, { 37,43 }, { 8,41 }, { 16,22 }, { 41,43 }, { 11,27 }, { 22,44 }, { 22,28 }, { 18,37 }, { 5,11 }, { 18,46 }, { 22,48 }, { 1,17 }, { 2,32 }, { 21,37 }, { 7,22 }, { 23,41 }, { 30,39 }, { 6,41 }, { 10,22 }, { 36,41 }, { 22,25 }, { 1,12 }, { 2,11 }, { 45,46 }, { 2,22 }, { 1,38 }, { 47,50 }, { 11,15 }, { 2,37 }, { 1,43 }, { 30,45 }, { 4,32 }, { 28,37 }, { 1,21 }, { 23,37 }, { 5,37 }, { 29,40 }, { 6,42 }, { 3,11 }, { 40,42 }, { 26,49 }, { 41,50 }, { 13,41 }, { 20,47 }, { 15,26 }, { 47,49 }, { 5,30 }, { 4,42 }, { 10,30 }, { 6,29 }, { 20,42 }, { 4,37 }, { 28,42 }, { 1,16 }, { 8,32 }, { 16,29 }, { 31,47 }, { 15,47 }, { 1,5 }, { 7,37 }, { 14,47 }, { 30,48 }, { 1,10 }, { 26,43 }, { 15,46 }, { 42,45 }, { 18,42 }, { 25,42 }, { 38,41 }, { 32,39 }, { 6,30 }, { 29,33 }, { 34,37 }, { 26,38 }, { 3,22 }, { 18,47 }, { 42,48 }, { 22,49 }, { 26,34 }, { 22,36 }, { 29,36 }, { 11,25 }, { 41,44 }, { 6,46 }, { 13,22 }, { 11,16 }, { 10,37 }, { 42,43 }, { 12,32 }, { 1,48 }, { 26,40 }, { 22,50 }, { 17,26 }, { 4,22 }, { 11,14 }, { 26,39 }, { 7,11 }, { 23,26 }, { 1,20 }, { 32,33 }, { 30,33 }, { 1,25 }, { 2,30 }, { 2,46 }, { 26,45 }, { 47,48 }, { 5,29 }, { 3,37 }, { 22,34 }, { 20,22 }, { 9,47 }, { 1,4 }, { 36,46 }, { 30,49 }, { 1,9 }, { 3,26 }, { 25,41 }, { 14,29 }, { 1,35 }, { 23,42 }, { 21,32 }, { 24,46 }, { 3,32 }, { 9,42 }, { 33,37 }, { 7,30 }, { 29,45 }, { 27,30 }, { 1,7 }, { 33,42 }, { 17,47 }, { 12,47 }, { 19,41 }, { 3,42 }, { 24,26 }, { 20,29 }, { 11,23 }, { 22,40 }, { 9,37 }, { 31,32 }, { 23,46 }, { 11,38 }, { 27,29 }, { 17,37 }, { 23,30 }, { 14,42 }, { 28,30 }, { 29,31 }, { 1,8 }, { 1,36 }, { 42,50 }, { 21,41 }, { 11,18 }, { 39,41 }, { 32,34 }, { 6,37 }, { 30,38 }, { 21,46 }, { 16,37 }, { 22,24 }, { 17,32 }, { 23,29 }, { 3,30 }, { 8,30 }, { 41,48 }, { 1,39 }, { 8,47 }, { 30,44 }, { 9,46 }, { 22,45 }, { 7,26 }, { 35,42 }, { 1,27 }, { 17,30 }, { 20,46 }, { 18,29 }, { 3,29 }, { 4,30 }, { 3,46 }}) << endl; // true

	cout << boolalpha << Solution().possibleBipartition(10, vector<vector<int>>{ {4, 7}, { 4, 8 }, { 2, 8 }, { 8, 9 }, { 1, 6 }, { 5, 8 }, { 1, 2 }, { 6, 7 }, { 3, 10 }, { 8, 10 }, { 1, 5 }, { 7, 10 }, { 1, 10 }, { 3, 5 }, { 3, 6 }, { 1, 4 }, { 3, 9 }, { 2, 3 }, { 1, 9 }, { 7, 9 }, { 2, 7 }, { 6, 8 }, { 5, 7 }, { 3, 4 }}) << endl; // true

	cout << boolalpha << Solution().possibleBipartition(4, vector<vector<int>>{ { 1,2 },{ 1,3 },{ 2,4 } }) << endl; // true
	cout << boolalpha << Solution().possibleBipartition(3, vector<vector<int>>{ { 1,2 },{ 1,3 },{ 2,3 } }) << endl; // false
	cout << boolalpha << Solution().possibleBipartition(5, vector<vector<int>>{ { 1,2 },{ 2,3 },{ 3,4 },{ 4,5 },{ 1,5 } }) << endl; // false
	cout << boolalpha << Solution().possibleBipartition(1, vector<vector<int>>{ }) << endl; // true
		

    return 0;
}

