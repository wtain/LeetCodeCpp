
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/coin-change/
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/

//Runtime: 52 ms, faster than 97.04% of C++ online submissions for Coin Change.
//Memory Usage : 14 MB, less than 69.49% of C++ online submissions for Coin Change.
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		const auto n = coins.size();
		vector<int> dp(amount + 1, -1);
		dp[0] = 0;

		for (int amt = 1; amt <= amount; ++amt) {
			int v = -1;
			for (int i = 0; i < n; ++i) {
				int amt1 = amt - coins[i];
				if (amt1 < 0)
					continue;
				if (dp[amt1] == -1)
					continue;
				int newv = dp[amt1] + 1;
				if (v == -1 || newv < v)
					v = newv;
			}
			dp[amt] = v;
		}

		return dp[amount];
	}
};

int main()
{
	cout << Solution().coinChange(vector<int>{1, 2, 5}, 11) << endl; // 3
	cout << Solution().coinChange(vector<int>{2}, 3) << endl; // -1

    return 0;
}

