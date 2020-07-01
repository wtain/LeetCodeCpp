
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
https://leetcode.com/problems/palindromic-substrings/

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Note:

The input string length won't exceed 1000.

*/

//Runtime: 48 ms, faster than 26.24% of C++ online submissions for Palindromic Substrings.
//Memory Usage : 7.6 MB, less than 47.22% of C++ online submissions for Palindromic Substrings.
class Solution {
public:
	int countSubstrings(string s) {
		const auto n = s.length();
		int cnt = n;
		vector<vector<bool>> dp(n, vector<bool>(n));

		for (int i = 0; i < n; ++i)
			dp[i][i] = true;

		for (int i = 0; i < n - 1; ++i)
			if (s[i] == s[i + 1]) {
				dp[i][i + 1] = true;
				++cnt;
			}

		for (int l = 3; l <= n; ++l) {
			for (int i = 0; i <= n - l; ++i) {
				if (!dp[i + 1][i + l - 1 - 1])
					continue;
				if (s[i] == s[i + l - 1]) {
					dp[i][i + l - 1] = true;
					++cnt;
				}
			}
		}

		return cnt;
	}
};

int main()
{
	cout << Solution().countSubstrings("abc") << endl; // 3
	cout << Solution().countSubstrings("aaa") << endl; // 6

	cout << Solution().countSubstrings("aaaa") << endl; // 10

    return 0;
}

