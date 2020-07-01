
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/dungeon-game/
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3367/

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.



Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)


Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/

//class Solution {
//public:
//	int calculateMinimumHP(vector<vector<int>>& dungeon) {
//		const size_t n = dungeon.size();
//		const size_t m = dungeon[0].size();
//		const int MIN = numeric_limits<int>::min();
//
//		vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {0, 0})); // v, min
//		dp[0][0] = { dungeon[0][0], dungeon[0][0] };
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < m; ++j) {
//				if (i == 0 && j == 0)
//					continue;
//				pair<int, int> v1 = { MIN, MIN }, v2 = { MIN, MIN };
//				if (i > 0) {
//					int v = dp[i - 1][j].first + dungeon[i][j];
//					v1 = { v, min(dp[i - 1][j].second, v) };
//				}
//				if (j > 0) {
//					int v = dp[i][j - 1].first + dungeon[i][j];
//					v2 = {v, min(dp[i][j - 1].second, v)};
//				}
//				dp[i][j] = v1.first >= v2.first ? v1 : v2;
//			}
//		}
//		return max(1, -dp[n - 1][m - 1].second);
//	}
//};

//Runtime: 8 ms, faster than 95.86% of C++ online submissions for Dungeon Game.
//Memory Usage : 9.1 MB, less than 26.72% of C++ online submissions for Dungeon Game.
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		const size_t n = dungeon.size();
		const size_t m = dungeon[0].size();

		vector<vector<int>> dp(n, vector<int>(m));
		for (int i = n-1; i >= 0; --i) {
			for (int j = m-1; j >= 0; --j) {
				if (i < n-1 && j < m-1)
					dp[i][j] = min(0, dungeon[i][j] + max(dp[i + 1][j], dp[i][j + 1]));
				else if (i < n-1)
					dp[i][j] = min(0, dungeon[i][j] + dp[i + 1][j]);
				else if (j < m-1)
					dp[i][j] = min(0, dungeon[i][j] + dp[i][j + 1]);
				else
					dp[i][j] = min(0, dungeon[i][j]);
			}
		}
		return 1 - dp[0][0];
	}
};

int main()
{
	{
		vector<vector<int>> dungeon = {
			{ -2, -3,  3 },
			{ -5, -10, 1 },
			{ 10,  30, -5 }
		};
		cout << Solution().calculateMinimumHP(dungeon) << endl; // 7
	}
	
	{
		vector<vector<int>> dungeon = {
			{ 0 }
		};
		cout << Solution().calculateMinimumHP(dungeon) << endl; // 1
	}

	{
		vector<vector<int>> dungeon = {
			{ -200 }
		};
		cout << Solution().calculateMinimumHP(dungeon) << endl; // 201
	}

    return 0;
}

