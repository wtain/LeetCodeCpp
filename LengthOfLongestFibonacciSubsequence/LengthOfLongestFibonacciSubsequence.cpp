
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

A sequence X_1, X_2, ..., X_n is fibonacci-like if:

n >= 3
X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
Given a strictly increasing array A of positive integers forming a sequence, find the length of the longest fibonacci-like subsequence of A.  If one does not exist, return 0.

(Recall that a subsequence is derived from another sequence A by deleting any number of elements (including none) from A, without changing the order of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)



Example 1:

Input: [1,2,3,4,5,6,7,8]
Output: 5
Explanation:
The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Example 2:

Input: [1,3,7,11,12,14,18]
Output: 3
Explanation:
The longest subsequence that is fibonacci-like:
[1,11,12], [3,11,14] or [7,11,18].


Note:

3 <= A.length <= 1000
1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
(The time limit has been reduced by 50% for submissions in Java, C, and C++.)

*/

// WRONG
//class Solution {
//public:
//	int lenLongestFibSubseq(vector<int>& A) {
//		const auto n = A.size();
//
//		unordered_map<int, int> prevs;
//
//		prevs.emplace(0, 0);
//
//		int maxl = 2;
//
//		// a{i-1}, L
//		for (int i = 0; i < n; ++i) {
//			// A[i]
//			int l = 1;
//			for (int j = 0; j < i; ++j) {
//				// A[j], j < i
//				int a2 = A[i] - A[j];
//				auto it = prevs.find(a2);
//				if (end(prevs) == it || it->first >= A[j])
//					continue;
//				l = max(l, it->second + 2);
//				maxl = max(maxl, l);
//			}
//			prevs.emplace(A[i], l);
//		}
//
//		return maxl;
//	}
//};

//#pragma message("!!!!!!!!!!!!!!!!!!!!!!!! Not solved problem, MEDIUM")

//class Solution {
//public:
//	int lenLongestFibSubseq(vector<int>& A) {
//		const auto n = A.size();
//
//		// aj x a2 -> L, prev
//		//vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, { 2, -1 }));
//		vector<vector<int>> dp(n, vector<int>(n, 2));
//		unordered_map<int, int> index;
//
//		/*vector<vector<vector<int>>> debug(n, vector<vector<int>>(n));
//
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < i; ++j) {
//				debug[i][j].push_back(A[j]);
//				debug[i][j].push_back(A[i]);
//			}
//		}*/
//
//		int maxl = 2;
//
//		for (int i = 0; i < n; ++i) {
//			// A[i]
//			for (int j = 0; j < i; ++j) {
//				int l = 2;
//				// A[j], j < i
//				int a2 = A[i] - A[j];
//				if (a2 >= A[j])
//					continue;
//				auto it = index.find(a2);
//				if (end(index) == it)
//					continue;
//				/*if (dp[j][it->second].second != -1 && a2 != dp[j][it->second].second)
//					continue;*/
//				//if (dp[j][it->second].first + 1 > l) {
//				//	debug[i][j] = debug[j][it->second];
//				//	debug[i][j].push_back(A[i]);
//				//}
//				// l = max(l, dp[j][it->second].first + 1);
//				l = max(l, dp[j][it->second] + 1);
//				maxl = max(maxl, l);
//				//dp[i][j] = { l, a2 };
//				dp[i][j] = l;
//			}
//			index.emplace(A[i], i);
//		}
//
//		return maxl;
//	}
//};

//Runtime: 268 ms, faster than 78.74% of C++ online submissions for Length of Longest Fibonacci Subsequence.
//Memory Usage : 62 MB, less than 13.11% of C++ online submissions for Length of Longest Fibonacci Subsequence.
class Solution {
public:
	int lenLongestFibSubseq(vector<int>& A) {
		const auto n = A.size();

		// aj x a2 -> L
		vector<vector<int>> dp(n, vector<int>(n, 2));
		unordered_map<int, int> index;

		int maxl = 0;

		for (int i = 0; i < n; ++i) {
			// A[i]
			for (int j = 0; j < i; ++j) {
				int l = 2;
				// A[j], j < i
				int a2 = A[i] - A[j];
				if (a2 >= A[j])
					continue;
				auto it = index.find(a2);
				if (end(index) == it)
					continue;
				l = max(l, dp[j][it->second] + 1);
				maxl = max(maxl, l);
				dp[i][j] = l;
			}
			index.emplace(A[i], i);
		}

		return maxl;
	}
};

int main()
{
	cout << Solution().lenLongestFibSubseq(vector<int>{1, 3, 5}) << endl; // 0
	cout << Solution().lenLongestFibSubseq(vector<int>{3, 5, 7, 8, 13, 15, 28}) << endl; // 4
	cout << Solution().lenLongestFibSubseq(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 13, 15, 28, 31, 41}) << endl; // 6
	cout << Solution().lenLongestFibSubseq(vector<int>{1, 2, 3, 4, 5, 6, 7, 8}) << endl; // 5
	cout << Solution().lenLongestFibSubseq(vector<int>{1, 3, 7, 11, 12, 14, 18}) << endl; // 3

    return 0;
}

