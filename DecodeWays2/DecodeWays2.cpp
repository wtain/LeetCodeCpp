

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
https://leetcode.com/problems/decode-ways-ii/

A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.

*/

//Runtime: 108 ms, faster than 66.53% of C++ online submissions for Decode Ways II.
//Memory Usage : 21.8 MB, less than 20.98% of C++ online submissions for Decode Ways II.
class Solution {
public:
	int numDecodings(string s) {
		const auto n = s.length();
		vector<unsigned long long> dp(n + 1);

		const unsigned long long divisor = 1000000007;

		dp[0] = 1ull;
		dp[1] = s[0] == '0' ? 0 : (s[0] == '*' ? 9 : 1);
		for (size_t i = 1; i < n; ++i) {
			if (s[i] == '0')
				dp[i + 1] = 0;
			else if (s[i] == '*')
				dp[i + 1] = dp[i] * 9 % divisor;
			else
				dp[i + 1] = dp[i];

			if (s[i - 1] != '0') {
				if (s[i - 1] == '*') {
					if (s[i] == '*') {
						dp[i + 1] += (dp[i - 1] * (26 - 9 - 2)) % divisor;
					}
					else if (s[i] <= '6') {
						dp[i + 1] += dp[i - 1] * 2 % divisor;
					}
					else {
						dp[i + 1] += dp[i - 1] % divisor;
					}
				} else if (s[i] == '*') {
					if (s[i-1] == '2')
						dp[i + 1] += 6 * dp[i - 1] % divisor;
					else if (s[i - 1] == '1')
						dp[i + 1] += 9 * dp[i - 1] % divisor;
				} else if ((s[i - 1] - '0') * 10 + s[i] - '0' <= 26)
					dp[i + 1] += dp[i - 1];
			}

			dp[i + 1] %= divisor;
		}

		return dp[n];
	}
};

int main()
{
	cout << Solution().numDecodings("2*") << endl; // 15

	cout << Solution().numDecodings("**1298724395983474357983745987345**3*45435*345*45*35*435") << endl; // 711121831

	cout << Solution().numDecodings("**") << endl; // 15 + 81 = 96

	cout << Solution().numDecodings("*") << endl; // 9
	cout << Solution().numDecodings("1*") << endl; // 18

    return 0;
}

