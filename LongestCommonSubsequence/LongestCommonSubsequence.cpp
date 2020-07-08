
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/longest-common-subsequence/

Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.



If there is no common subsequence, return 0.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.


Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.

*/

//Runtime: 44 ms, faster than 16.81% of C++ online submissions for Longest Common Subsequence.
//Memory Usage : 13 MB, less than 7.68% of C++ online submissions for Longest Common Subsequence.
//class Solution {
//public:
//	int longestCommonSubsequence(string text1, string text2) {
//		const auto n1 = text1.length();
//		const auto n2 = text2.length();
//
//		vector<vector<int>> dp(n1+1, vector<int>(n2+1));
//
//		for (int i = 0; i < n1; ++i) {
//			for (int j = 0; j < n2; ++j) {
//				if (text1[i] == text2[j])
//					dp[i + 1][j + 1] = dp[i][j] + 1;
//				else
//					dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
//			}
//		}
//
//		return dp[n1][n2];
//	}
//};

//Runtime: 36 ms, faster than 24.68% of C++ online submissions for Longest Common Subsequence.
//Memory Usage : 6.6 MB, less than 94.68% of C++ online submissions for Longest Common Subsequence.
//class Solution {
//public:
//	int longestCommonSubsequence(string text1, string text2) {
//
//		const auto n1 = text1.length();
//		const auto n2 = text2.length();
//
//		vector<vector<int>> dp(n1 + 1, vector<int>(2));
//
//		for (int j = 0; j < n2; ++j) {
//			int j1 = j % 2;
//			int j2 = 1 - j1;
//			for (int i = 0; i < n1; ++i) {
//				if (text1[i] == text2[j])
//					dp[i + 1][j2] = dp[i][j1] + 1;
//				else
//					dp[i + 1][j2] = max(dp[i + 1][j1], dp[i][j2]);
//			}
//		}
//
//		return dp[n1][n2 % 2];
//	}
//};

//Runtime: 36 ms, faster than 24.68% of C++ online submissions for Longest Common Subsequence.
//Memory Usage : 6.4 MB, less than 96.53% of C++ online submissions for Longest Common Subsequence.
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {

		if (text2.length() > text1.length())
			text2.swap(text1);

		const auto n1 = text1.length();
		const auto n2 = text2.length();

		vector<vector<int>> dp(2, vector<int>(n2 + 1));

		for (int i = 0; i < n1; ++i) {
			int i1 = i % 2;
			int i2 = 1 - i1;
			for (int j = 0; j < n2; ++j) {
				if (text1[i] == text2[j])
					dp[i2][j+1] = dp[i1][j] + 1;
				else
					dp[i2][j+1] = max(dp[i2][j], dp[i1][j+1]);
			}
		}

		return dp[n1 % 2][n2];
	}
};

int main()
{
	cout << Solution().longestCommonSubsequence("abcde", "ace") << endl; // 3
	cout << Solution().longestCommonSubsequence("abc", "abc") << endl; // 3
	cout << Solution().longestCommonSubsequence("abc", "def") << endl; // 0


	cout << Solution().longestCommonSubsequence("ezupkr", "ubmrapg") << endl; // 2

    return 0;
}

