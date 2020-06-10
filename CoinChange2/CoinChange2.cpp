
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/coin-change-2/
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3353/

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.



Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1


Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
*/

// TLE
//class Solution {
//public:
//
//	int changeImpl(int amount, const vector<int>& coins, size_t minCoinI) {
//		if (!amount)
//			return 1;
//		int cnt = 0;
//		for (size_t i = minCoinI; i < coins.size(); ++i) {
//			int newAmount = amount - coins[i];
//			if (newAmount >= 0)
//				cnt += changeImpl(newAmount, coins, i);
//		}
//		return cnt;
//	}
//
//	int change(int amount, vector<int>& coins) {
//		return changeImpl(amount, coins, 0);
//	}
//};

//Runtime: 1676 ms, faster than 5.05% of C++ online submissions for Coin Change 2.
//Memory Usage : 18.1 MB, less than 30.59% of C++ online submissions for Coin Change 2.
//class Solution {
//public:
//
//	int change(int amount, vector<int>& coins) {
//		if (coins.empty())
//			return amount ? 0 : 1;
//		const size_t M = coins.size();
//		const size_t N = amount + 1;
//		vector<vector<int>> dp(M, vector<int>(N));
//
//		for (size_t i = 0; i < M; ++i)
//			dp[i][0] = 1;
//
//		for (size_t i = 0; i < M; ++i) {
//			for (size_t j = 1; j < N; ++j) {
//				int currAmount = j;
//				int cnt = 0;
//				for (size_t k = 0; k <= i; ++k) {
//					int coin = coins[k];
//					int newAmount = currAmount - coin;
//					if (newAmount >= 0)
//						cnt += dp[k][newAmount];
//				}
//				dp[i][j] = cnt;
//			}
//		}
//
//
//		return dp[M-1][amount];
//	}
//};

//Runtime: 28 ms, faster than 39.55% of C++ online submissions for Coin Change 2.
//Memory Usage : 18.4 MB, less than 23.92% of C++ online submissions for Coin Change 2.
//class Solution {
//public:
//
//	int change(int amount, vector<int>& coins) {
//		if (coins.empty())
//			return amount ? 0 : 1;
//		const size_t M = coins.size();
//		const size_t N = amount + 1;
//		vector<vector<int>> dp(M + 1, vector<int>(N));
//
//		dp[0][0] = 1;
//
//		for (size_t i = 1; i <= M; ++i) {
//			dp[i][0] = 1;
//			int coin = coins[i-1];
//			for (size_t j = 1; j < N; ++j) {
//				int currAmount = j;
//				int newAmount = currAmount - coin;
//				dp[i][j] = dp[i - 1][j];
//				if (newAmount >= 0)
//					dp[i][j] += dp[i][newAmount];
//			}
//		}
//
//		return dp[M][amount];
//	}
//};

//Runtime: 4 ms, faster than 99.30% of C++ online submissions for Coin Change 2.
//Memory Usage : 7 MB, less than 78.32% of C++ online submissions for Coin Change 2.
class Solution {
public:

	int change(int amount, vector<int>& coins) {
		if (coins.empty())
			return amount ? 0 : 1;
		const size_t M = coins.size();
		const size_t N = amount + 1;
		vector<int> dp(N);

		dp[0] = 1;

		for (size_t i = 1; i <= M; ++i) {
			int coin = coins[i - 1];
			for (size_t j = 1; j < N; ++j) {
				int currAmount = j;
				int newAmount = currAmount - coin;
				if (newAmount >= 0)
					dp[j] += dp[newAmount];
			}
		}

		return dp[amount];
	}
};

int main()
{
	cout << Solution().change(5, vector<int>{1, 2, 5}) << endl; // 4
	cout << Solution().change(3, vector<int>{2}) << endl; // 0
	cout << Solution().change(10, vector<int>{10}) << endl; // 1

	cout << Solution().change(500, vector<int>{3, 5, 7, 8, 9, 10, 11}) << endl; // 35502874

	cout << Solution().change(0, vector<int>{}) << endl; // 1
	cout << Solution().change(10, vector<int>{}) << endl; // 0

    return 0;
}

