
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

*/

//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		const auto n = prices.size();
//		
//		vector<int> dp(n), dp1(n), mins(n);
//		mins[0] = prices[0];
//
//		dp[0] = 0;
//		dp1[0] = 0;
//		for (int i = 1; i < n; ++i) {
//			
//			int v1 = dp1[i - 1] + max(prices[i] - mins[i-1], 0);
//			int v2 = dp[i - 1];
//
//			if (v1 > v2) {
//				dp[i] = v1;
//				mins[i] = prices[i];
//			}
//			else {
//				dp[i] = v2;
//				mins[i] = min(mins[i - 1], prices[i]);
//			}
//
//			//dp[i] = max(dp1[i - 1] + max(prices[i] - prices[i - 1], 0), dp[i - 1]);
//			
//			dp1[i] = dp[i - 1];
//		}
//
//		return dp[n-1];
//	}
//};

//#pragma message("!!!!!!!!!!!!!!!!!!!!!!!! Not solved problem, MEDIUM")

//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		const auto n = prices.size();
//
//		vector<vector<int>> dp(n, vector<int>(n));
//
//		for (int i = 0; i < n; ++i) {
//			for (int j = i+1; j < n; ++j) {
//
//			}
//		}
//		
//		return dp[0][n - 1];
//	}
//};

//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		const auto n = prices.size();
//
//		vector<int> dp(n);
//		vector<pair<int, int>> buyprice(n);
//
//		buyprice[0] = { prices[0], 0 };
//		dp[0] = 0;
//
//		for (int i = 1; i < n; ++i) {
//			int v_yield = prices[i] - buyprice[i - 1].first;
//			int v_sell = v_yield;
//			if (buyprice[i - 1].second >= 1)
//				v_sell += dp[buyprice[i - 1].second - 1];
//
//			int v_notsell = dp[i - 1];
//
//			if (v_sell > v_notsell) {
//				dp[i] = v_sell;
//				buyprice[i] = { prices[i], i };
//			}
//			else {
//				dp[i] = v_notsell;
//				if (prices[i] < buyprice[i - 1].first)
//					buyprice[i] = { prices[i], i };
//				else
//					buyprice[i] = buyprice[i - 1];
//			}
//		}
//
//		return dp[n - 1];
//	}
//};

//Runtime: 4 ms, faster than 83.63% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
//Memory Usage : 11.8 MB, less than 12.52% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		const auto n = prices.size();

		if (!n)
			return 0;

		vector<vector<int>> dp(n, vector<int>(2));

		dp[0][0] = 0;
		dp[0][1] = -prices[0];

		for (int i = 1; i < n; ++i) {

			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);

			if (i >= 2)
				dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
			else
				dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}

		return dp[n - 1][0];
	}
};

int main()
{
	cout << Solution().maxProfit(vector<int>{1, 2, 3, 0, 2}) << endl; // 3
	cout << Solution().maxProfit(vector<int>{1, 2, 3, 0, 2, 1, 2, 3, 0, 2, 1, 2, 3, 0, 2}) << endl; // 7
	cout << Solution().maxProfit(vector<int>{1, 2, 3, 0, 2, 1, 2, 3, 0, 2, 1, 2, 3, 0, 2, 1, 2, 3, 0, 2}) << endl; // 9

	cout << Solution().maxProfit(vector<int>{}) << endl; // 0

    return 0;
}

