
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.



Example 1:

Input: arr = [6,2,4]
Output: 32
Explanation:
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

24            24
/  \          /  \
12   4        6    8
/  \               / \
6    2             2   4


Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (ie. it is less than 2^31).

Do a DP, where dp(i, j) is the answer for the subarray arr[i]..arr[j].
For each possible way to partition the subarray i <= k < j, the answer is max(arr[i]..arr[k]) * max(arr[k+1]..arr[j]) + dp(i, k) + dp(k+1, j).
*/

//#pragma message("!!!!!!!!!!!!!!!!!!!!!!!! Not solved problem, MEDIUM")

//Runtime: 12 ms, faster than 43.01% of C++ online submissions for Minimum Cost Tree From Leaf Values.
//Memory Usage : 9.3 MB, less than 23.82% of C++ online submissions for Minimum Cost Tree From Leaf Values.
class Solution {
public:
	int mctFromLeafValues(vector<int>& arr) {
		const auto n = arr.size();
		vector<vector<int>> dp(n, vector<int>(n));
		vector<vector<int>> maxes(n, vector<int>(n));
		
		for (auto i = 0; i < n; ++i) {
			maxes[i][i] = arr[i];
		}

		for (auto i = 0; i < n; ++i) {
			for (auto j = i + 1; j < n; ++j) {
				maxes[i][j] = max(maxes[i][j - 1], arr[j]);
			}
		}

		for (auto l = 2; l <= n; ++l) {
			
			for (auto i = 0; i < n-l+1; ++i) {
				const auto j = i + l - 1;
				int minv = numeric_limits<int>::max();
				for (auto k = i; k < j; ++k) {
					auto v = dp[i][k] + dp[k+1][j] + maxes[i][k] * maxes[k+1][j];
					minv = min(v, minv);
				}
				dp[i][j] = minv;
			}
		}

		return dp[0][n - 1];
	}
};

int main()
{
	cout << Solution().mctFromLeafValues(vector<int>{6, 2, 4}) << endl; // 32
	cout << Solution().mctFromLeafValues(vector<int>{6, 2, 4, 5, 6, 7, 8, 9}) << endl; // 264

    return 0;
}

