
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/minimum-cost-for-tickets/

In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.



Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation:
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation:
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total you spent $17 and covered all the days of your travel.


Note:

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000

*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Cost For Tickets.
//Memory Usage : 9.6 MB, less than 56.95% of C++ online submissions for Minimum Cost For Tickets.
//class Solution {
//public:
//	int mincostTickets(vector<int>& days, vector<int>& costs) {
//		const auto n = days.size();
//		const auto m = costs.size();
//
//		vector<bool> travels(366, false);
//		for (int i = 0; i < days.size(); ++i)
//			travels[days[i]] = true;
//
//		vector<int> dp(366 + 30);
//
//		for (int i = 1; i <= 365 + 30; ++i) {
//			int v = dp[i - 1] + costs[0];
//
//			if (i > 365 || !travels[i])
//				v = min(dp[i - 1], v);
//
//			if (i - 7 + 1 >= 1)
//				v = min(v, dp[i-7] + costs[1]);
//
//			if (i - 30 + 1 >= 1)
//				v = min(v, dp[i - 30] + costs[2]);
//
//			dp[i] = v;
//		}
//
//		return dp[365 + 30];
//	}
//};

//Runtime: 4 ms, faster than 91.69% of C++ online submissions for Minimum Cost For Tickets.
//Memory Usage : 9.5 MB, less than 73.62% of C++ online submissions for Minimum Cost For Tickets.
class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		const auto n = days.size();
		const auto m = costs.size();

		vector<bool> travels(366, false);
		for (int i = 0; i < days.size(); ++i)
			travels[days[i]] = true;

		vector<int> dp(366);

		for (int i = 1; i <= 365; ++i) {
			int v = dp[i - 1] + costs[0];

			if (!travels[i])
				v = min(dp[i - 1], v);

			if (i - 7 + 1 >= 1)
				v = min(v, dp[i - 7] + costs[1]);

			if (i - 30 + 1 >= 1)
				v = min(v, dp[i - 30] + costs[2]);

			dp[i] = v;
		}

		return dp[365];
	}
};

int main()
{
	cout << Solution().mincostTickets(vector<int>{1, 4, 6, 7, 8, 20}, vector<int>{2, 7, 15}) << endl; // 11
	cout << Solution().mincostTickets(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}, vector<int>{2, 7, 15}) << endl; // 17

    return 0;
}

