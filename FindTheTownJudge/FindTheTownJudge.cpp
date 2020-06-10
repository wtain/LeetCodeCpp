
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.



Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3


Note:

1 <= N <= 1000
trust.length <= 10000
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N

*/

class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		//vector<vector<bool>> t(N, vector<bool>(N, false));
		//for (const auto& p : trust)
		//	t[p[0] - 1][p[1] - 1] = true;

		vector<int> trust1(N);
		vector<int> trust2(N);

		for (const auto& p : trust) {
			++trust1[p[0] - 1];
			++trust2[p[1] - 1];
		}
		
		int result = -1;
		for (int i = 0; i < N; ++i) {
			if (!trust1[i] && trust2[i] == N - 1) {
				if (result != -1)
					return -1;
				result = i + 1;
			}
		}
		return result;
	}
};


int main()
{
	cout << Solution().findJudge(2, vector<vector<int>>({ {1, 2} })) << endl; // 2
	cout << Solution().findJudge(3, vector<vector<int>>({ { 1, 3 }, {2,3} })) << endl; // 3
	cout << Solution().findJudge(3, vector<vector<int>>({ { 1, 3 },{ 2,3 }, {3,1} })) << endl; // -1
	cout << Solution().findJudge(3, vector<vector<int>>({ { 1, 2 },{ 2,3 } })) << endl; // -1
	cout << Solution().findJudge(4, vector<vector<int>>({ { 1, 3 },{ 1,4 },{2,3},{2,4},{4,3} })) << endl; // 3

    return 0;
}

