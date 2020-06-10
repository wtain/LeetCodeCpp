
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/edit-distance/
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3346/

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/

//Runtime: 24 ms, faster than 29.82% of C++ online submissions for Edit Distance.
//Memory Usage : 9.1 MB, less than 87.50% of C++ online submissions for Edit Distance.
class Solution {
public:
	int minDistance(string word1, string word2) {
		const size_t n1 = word1.length();
		const size_t n2 = word2.length();

		vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

		for (size_t i = 0; i <= n1; ++i)
			dp[i][0] = i;

		for (size_t i = 0; i <= n2; ++i)
			dp[0][i] = i;

		for (size_t i = 1; i <= n1; ++i)
			for (size_t j = 1; j <= n2; ++j) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min({ dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1 });
			}

		return dp[n1][n2];
	}
};

int main()
{
	cout << Solution().minDistance("horse", "ros") << endl; // 3
	cout << Solution().minDistance("intention", "execution") << endl; // 5

	cout << Solution().minDistance("intention", "") << endl; // 9
	cout << Solution().minDistance("", "execution") << endl; // 9
    return 0;
}

