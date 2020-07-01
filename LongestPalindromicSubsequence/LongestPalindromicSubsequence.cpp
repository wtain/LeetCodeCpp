
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/longest-palindromic-subsequence/
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".


Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".


Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

// FOR SUBSTRING, NOT SUBSEQUENCE
//class Solution {
//public:
//	int longestPalindromeSubseq(string s) {
//		const auto n = s.length();
//		if (!n)
//			return 0;
//		int maxLen = 1;
//		vector<vector<bool>> dp(n, vector<bool>(n));
//
//		for (int i = 0; i < n; ++i)
//			dp[i][i] = true;
//
//		for (int i = 0; i < n - 1; ++i)
//			if (s[i] == s[i + 1]) {
//				dp[i][i + 1] = true;
//				maxLen = 2;
//			}
//
//		for (int l = 3; l <= n; ++l) {
//			for (int i = 0; i <= n - l; ++i) {
//				if (!dp[i + 1][i + l - 1 - 1])
//					continue;
//				if (s[i] == s[i + l - 1]) {
//					dp[i][i + l - 1] = true;
//					maxLen = l;
//				}
//			}
//		}
//
//		return maxLen;
//	}
//};

// #pragma message("!!!!!!!!!!!!!!!!!!!!!!!! Not solved problem, MEDIUM")

//Runtime: 220 ms, faster than 12.59% of C++ online submissions for Longest Palindromic Subsequence.
//Memory Usage : 67 MB, less than 40.13% of C++ online submissions for Longest Palindromic Subsequence.
//class Solution {
//public:
//	int longestPalindromeSubseq(string s) {
//		const auto n = s.length();
//		if (!n)
//			return 0;
//		string r = s;
//		reverse(begin(r), end(r));
//
//		vector<vector<int>> dp(n+1, vector<int>(n+1));
//
//		for (int i = 0; i < s.length(); ++i) {
//			for (int j = 0; j < r.length(); ++j) {
//				if (s[i] == r[j]) {
//					dp[i + 1][j + 1] = dp[i][j] + 1;
//				}
//				else {
//					dp[i + 1][j + 1] = max(dp[i+1][j], dp[i][j+1]);
//				}
//			}
//		}
//
//		return dp[n][n];
//	}
//};

//Runtime: 208 ms, faster than 15.81% of C++ online submissions for Longest Palindromic Subsequence.
//Memory Usage : 6.5 MB, less than 97.70% of C++ online submissions for Longest Palindromic Subsequence.
//class Solution {
//public:
//	int longestPalindromeSubseq(string s) {
//		const auto n = s.length();
//		if (!n)
//			return 0;
//		string r = s;
//		reverse(begin(r), end(r));
//
//		vector<vector<int>> dp(2, vector<int>(n + 1));
//
//		for (int i = 0; i < s.length(); ++i) {
//			for (int j = 0; j < r.length(); ++j) {
//				if (s[i] == r[j]) {
//					dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + 1;
//				}
//				else {
//					dp[(i + 1) % 2][j + 1] = max(dp[(i + 1) % 2][j], dp[i % 2][j + 1]);
//				}
//			}
//		}
//
//		return dp[n % 2][n];
//	}
//};

//Runtime: 252 ms, faster than 9.00% of C++ online submissions for Longest Palindromic Subsequence.
//Memory Usage : 6.5 MB, less than 97.81% of C++ online submissions for Longest Palindromic Subsequence.
//class Solution {
//public:
//	int longestPalindromeSubseq(string s) {
//		const auto n = s.length();
//		if (!n)
//			return 0;
//		string r = s;
//		reverse(begin(r), end(r));
//
//		vector<vector<int>> dp(2, vector<int>(n + 1));
//
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < n; ++j) {
//				if (s[i] == r[j]) {
//					dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + 1;
//				}
//				else {
//					dp[(i + 1) % 2][j + 1] = max(dp[(i + 1) % 2][j], dp[i % 2][j + 1]);
//				}
//			}
//		}
//
//		return dp[n % 2][n];
//	}
//};

//Runtime: 148 ms, faster than 32.88% of C++ online submissions for Longest Palindromic Subsequence.
//Memory Usage : 66.9 MB, less than 56.98% of C++ online submissions for Longest Palindromic Subsequence.
//class Solution {
//	vector<vector<int>> dp;
//public:
//	int longestPalindromeSubseq(string s) {
//		const auto n = s.length();
//		if (!n)
//			return 0;
//
//		dp.resize(n, vector<int>(n));
//
//		for (int i = n-1; i >= 0; --i) {
//			dp[i][i] = 1;
//			for (int j = i + 1; j < n; ++j) {
//				if (s[i] == s[j]) {
//					dp[i][j] = 2 + dp[i + 1][j - 1];
//				}
//				else {
//					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//				}
//			}
//		}
//
//		return dp[0][n-1];
//	}
//};

//Runtime: 168 ms, faster than 25.89% of C++ online submissions for Longest Palindromic Subsequence.
//Memory Usage : 66.9 MB, less than 54.17% of C++ online submissions for Longest Palindromic Subsequence.
class Solution {
	vector<vector<int>> dp;
public:
	int longestPalindromeSubseq(string s) {
		const auto n = s.length();
		if (!n)
			return 0;

		dp.resize(n, vector<int>(n));

		for (int i = 0; i < n; ++i)
			dp[i][i] = 1;

		for (int l = 2; l <= n; ++l) {
			for (int i = 0; i < n - l + 1; ++i) {
				int j = i + l - 1;
				if (2 == l && s[i] == s[j])
					dp[i][j] = 2;
				else if (s[i] == s[j])
					dp[i][j] = 2 + dp[i + 1][j - 1];
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}

		return dp[0][n - 1];
	}
};

int main()
{
	cout << Solution().longestPalindromeSubseq("bbbab") << endl; // 4
	cout << Solution().longestPalindromeSubseq("cbbd") << endl; // 2

    return 0;
}

