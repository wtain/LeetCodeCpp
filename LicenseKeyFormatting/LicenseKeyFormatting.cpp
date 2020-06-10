
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
/*
https://leetcode.com/problems/license-key-formatting/

You are given a license key represented as a string S which consists only alphanumeric character and dashes. The string is separated into N+1 groups by N dashes.

Given a number K, we would want to reformat the strings such that each group contains exactly K characters, except for the first group which could be shorter than K, but still must contain at least one character. Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.

Given a non-empty string S and a number K, format the string according to the rules described above.

Example 1:
Input: S = "5F3Z-2e-9-w", K = 4

Output: "5F3Z-2E9W"

Explanation: The string S has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.
Example 2:
Input: S = "2-5g-3-J", K = 2

Output: "2-5G-3J"

Explanation: The string S has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
Note:
The length of string S will not exceed 12,000, and K is a positive integer.
String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
String S is non-empty.

*/

class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		const size_t n = S.length();
		const size_t nd = count(begin(S), end(S), '-');
		const size_t m = n - nd;
		int firstGroup = m % K;
		string rv;
		int c = firstGroup ? firstGroup : K;
		rv.reserve(S.length() + (m / K));
		for (int i = 0; i < S.length(); ++i) {
			if (S[i] == '-')
				continue;
			rv += toupper(S[i]);
			//rv += S[i];
			if (!--c && i != S.length() - 1) {
				rv += "-";
				c = K;
			}
		}
		if (rv.length() && rv[rv.length() - 1] == '-')
			rv.erase(begin(rv) + rv.length() - 1);
		//transform(begin(rv), end(rv), begin(rv), toupper);
		//transform(begin(rv), end(rv), begin(rv), [](auto c) => toupper(c));
		//transform(begin(rv), end(rv), begin(rv), (int(*)(int))toupper);
		return rv;
	}
};

int main()
{
	cout << Solution().licenseKeyFormatting("5F3Z-2e-9-w", 4) << endl; // "5F3Z-2E9W"
	cout << Solution().licenseKeyFormatting("2-5g-3-J", 2) << endl; // "2-5G-3J"
	cout << Solution().licenseKeyFormatting("a-a-a-a-", 1) << endl; // "A-A-A-A"
	cout << Solution().licenseKeyFormatting("---", 3) << endl; // ""

    return 0;
}

