
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/ones-and-zeroes/
Given an array, strs, with strings consisting of only 0s and 1s. Also two integers m and n.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.



Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are "10","0001","1","0".
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".


Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100
*/

/*
WRONG
["0001","0101","1000","1000"]
9
3*/
//class Solution {
//public:
//
//	vector<int> count(const string& s) {
//		vector<int> rv(2);
//		for (const auto si : s)
//			++rv[si - '0'];
//		return rv;
//	}
//
//	int findMaxForm(vector<string>& strs, int m, int n) {
//		sort(begin(strs), end(strs));
//		int cnt = 0;
//		for (const auto& s : strs) {
//			const auto c = count(s);
//			if (m >= c[0] && n >= c[1]) {
//				m -= c[0];
//				n -= c[1];
//				++cnt;
//			}
//		}
//		return cnt;
//	}
//};

// WILL BE TOO SLOW, DID NOT SUBMIT
//class Solution {
//public:
//
//	vector<int> count(const string& s) {
//		vector<int> rv(2);
//		for (const auto si : s)
//			++rv[si - '0'];
//		return rv;
//	}
//
//	int findMaxFormImpl(const vector<string>& strs, int m, int n, int mini) {
//		if (mini >= strs.size())
//			return 0;
//		const auto c = count(strs[mini]);
//		int r1 = findMaxFormImpl(strs, m, n, mini + 1);
//		if (m >= c[0] && n >= c[1])
//			return max(r1, findMaxFormImpl(strs, m - c[0], n - c[1], mini+1) + 1);
//		return r1;
//	}
//
//	int findMaxForm(vector<string>& strs, int m, int n) {
//		return findMaxFormImpl(strs, m, n, 0);
//	}
//};

// TLE?
//class Solution {
//public:
//
//	vector<int> count(const string& s) {
//		vector<int> rv(2);
//		for (const auto si : s)
//			++rv[si - '0'];
//		return rv;
//	}
//
//	int findMaxForm(vector<string>& strs, int m, int n) {
//
//		const auto c = strs.size();
//		vector<vector<int>> dp; // count, n0, n1
//
//		dp.push_back({ 0, 0, 0 });
//
//		int result = 0;
//
//		for (size_t i = 0; i < c; ++i) {
//			vector<vector<int>> nextState;
//			const auto ci = count(strs[i]);
//			nextState.reserve(2 * dp.size());
//			for (size_t j = 0; j < dp.size(); ++j) {
//				auto state = dp[j];
//				nextState.push_back(state);
//				++state[0];
//				state[1] += ci[0];
//				state[2] += ci[1];
//				if (state[1] <= m && state[2] <= n) {
//					nextState.push_back(state);
//					result = max(result, state[0]);
//				}
//			}
//			dp = nextState;
//		}
//
//		return result;
//	}
//};

//Runtime: 300 ms, faster than 45.84% of C++ online submissions for Ones and Zeroes.
//Memory Usage : 9.8 MB, less than 69.14% of C++ online submissions for Ones and Zeroes.
class Solution {
public:

	vector<int> count(const string& s) {
		vector<int> rv(2);
		for (const auto si : s)
			++rv[si - '0'];
		return rv;
	}

	int findMaxForm(vector<string>& strs, int m, int n) {

		const auto c = strs.size();
		vector<vector<int>> dp(m+1, vector<int>(n+1));

		int result = 0;

		for (const auto& si: strs) {
			const auto ci = count(si);
			for (int i = m; i >= ci[0]; --i) {
				for (int j = n; j >= ci[1]; --j) {
					dp[i][j] = max(dp[i][j], dp[i-ci[0]][j-ci[1]] + 1);
				}
			}
		}

		return dp[m][n];
	}
};

int main()
{
	/*
	["0001","0101","1000","1000"]
9
3*/

	/*
	["0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"]
9
80
	*/

	cout << Solution().findMaxForm(vector<string>{"0", "11", "1000", "01", "0", "101", "1", "1", "1", "0", "0", "0", "0", "1", "0", "0110101", "0", "11", "01", "00", "01111", "0011", "1", "1000", "0", "11101", "1", "0", "10", "0111"}, 9, 80) << endl; // 17

	cout << Solution().findMaxForm(vector<string>{"0001", "0101", "1000", "1000"}, 9, 3) << endl; // 3

	cout << Solution().findMaxForm(vector<string>{"10", "0001", "111001", "1", "0"}, 5, 3) << endl; // 4
	cout << Solution().findMaxForm(vector<string>{"10", "0001", "111001", "1", "0"}, 4, 3) << endl; // 3
	cout << Solution().findMaxForm(vector<string>{"10", "0", "1"}, 1, 1) << endl; // 2

    return 0;
}

