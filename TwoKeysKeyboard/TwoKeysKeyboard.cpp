
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/2-keys-keyboard/

nitially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.


Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:

Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.


Note:

The n will be in the range [1, 1000].
*/

//Runtime: 1040 ms, faster than 5.22% of C++ online submissions for 2 Keys Keyboard.
//Memory Usage : 155.5 MB, less than 5.15% of C++ online submissions for 2 Keys Keyboard.
//class Solution {
//public:
//	int minSteps(int n) {
//		const int BigNumber = n * n + 1;
//		vector<vector<int>> dp(n + 1, vector<int>(n + 1, BigNumber));
//		
//		dp[0][1] = 0; // initially nothing copied, 'A' printed
//
//		/*
//		copy: (a, b) -> (b, b)
//		paste: (a, b) -> (a, b + a)
//		*/
//
//		for (int i = 0; i <= n; ++i) {
//			// i - copied
//			for (int j = 1; j <= n; ++j) {
//				// j - printed
//
//				// paste: i,j -> i, j+i
//
//				int j2 = i + j;
//				if (j2 <= n)
//					dp[i][j2] = min(1 + dp[i][j], dp[i][j2]);
//
//				// copy: i,j -> j,j
//
//				dp[j][j] = min(dp[j][j], dp[i][j] + 1);
//			}
//		}
//
//		int mn = dp[0][n];
//		for (int i = 1; i <= n; ++i)
//			mn = min(mn, dp[i][n]);
//		return mn;
//	}
//};

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for 2 Keys Keyboard.
//Memory Usage : 5.9 MB, less than 93.86% of C++ online submissions for 2 Keys Keyboard.
class Solution {
public:
	int minSteps(int n) {
		int result = 0, d = 2;
		while (n > 1) {
			while (n %d == 0) {
				result += d;
				n /= d;
			}
			++d;
		}
		return result;
	}
};

int main()
{
	cout << Solution().minSteps(3) << endl; // 3
	cout << Solution().minSteps(1) << endl; // 0
	cout << Solution().minSteps(1000) << endl; // 21

    return 0;
}

