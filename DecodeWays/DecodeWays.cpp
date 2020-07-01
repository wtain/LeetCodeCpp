
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
https://leetcode.com/problems/decode-ways
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

//Runtime: 4 ms, faster than 57.91% of C++ online submissions for Decode Ways.
//Memory Usage : 6.2 MB, less than 81.46% of C++ online submissions for Decode Ways.
class Solution {
public:
	int numDecodings(string s) {
		const auto n = s.length();
		vector<int> dp(n + 1);

		dp[0] = 1;
		dp[1] = s[0] == '0' ? 0 : 1;
		for (size_t i = 1; i < n; ++i) {
			dp[i+1] = s[i] == '0' ? 0 : dp[i];
			if ((s[i - 1] - '0') * 10 + s[i] - '0' <= 26 && s[i - 1] != '0')
				dp[i+1] += dp[i - 1];
		}

		return dp[n];
	}
};

int main()
{
	cout << Solution().numDecodings("101") << endl; // 1 =  10 1

	cout << Solution().numDecodings("12") << endl; // 2
	cout << Solution().numDecodings("226") << endl; // 3

	cout << Solution().numDecodings("266666") << endl; // 2
	
	cout << Solution().numDecodings("100000") << endl; // 0

    return 0;
}

