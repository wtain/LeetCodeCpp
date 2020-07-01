
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/unique-binary-search-trees/
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3370/

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3

*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.
//Memory Usage : 6 MB, less than 76.26% of C++ online submissions for Unique Binary Search Trees.
class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1);
		dp[0] = 1;
		dp[1] = 1;
		
		for (int i = 2; i <= n; ++i) {
			int cnt = 0;
			for (int j = 0; j < i; ++j)
				cnt += dp[j] * dp[i - 1 - j];
			dp[i] = cnt;
		}

		return dp[n];
	}
};

int main()
{
	cout << Solution().numTrees(1) << endl; // 1
	cout << Solution().numTrees(2) << endl; // 2
	cout << Solution().numTrees(3) << endl; // 5
	cout << Solution().numTrees(10) << endl; // 16796

    return 0;
}

