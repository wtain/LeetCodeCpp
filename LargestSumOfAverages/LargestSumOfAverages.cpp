
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/largest-sum-of-averages/
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input:
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation:
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.


Note:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
Answers within 10^-6 of the correct answer will be accepted as correct.
*/

//#pragma message("!!!!!!!!!!!!!!!!!!!!!!!! Not solved problem, MEDIUM")

//class Solution {
//public:
//	double largestSumOfAverages(vector<int>& A, int K) {
//		const double s = accumulate(begin(A), end(A), 0.0);
//		const double avg = s / K;
//		vector<vector<int>> buckets(K);
//
//		for (const auto n : A) {
//
//		}
//
//		double result = 0.0;
//		for (int i = 0; i < K; ++i) {
//			const double s = accumulate(begin(buckets[i]), end(buckets[i]), 0.0);
//			result += s / buckets[i].size();
//		}
//
//		return result;
//	}
//};

//Runtime: 28 ms, faster than 31.79% of C++ online submissions for Largest Sum of Averages.
//Memory Usage : 7.7 MB, less than 73.44% of C++ online submissions for Largest Sum of Averages.
class Solution {
public:
	double largestSumOfAverages(vector<int>& A, int K) {
		
		const auto n = A.size();

		vector<double> ps(n + 1);
		for (int i = 0; i < n; ++i)
			ps[i + 1] = ps[i] + A[i];
		
		vector<double> dp(n);

		for (int i = 0; i < n; ++i)
			dp[i] = (ps[n] - ps[i]) / (n - i);

		for (int k = 1; k < K; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j)
					dp[i] = max(dp[i], (ps[j] - ps[i]) / (j - i) + dp[j]);
			}
		}

		return dp[0];
	}
};

int main()
{
	cout << Solution().largestSumOfAverages(vector<int>{9, 1, 2, 3, 9}, 3) << endl; // 20

    return 0;
}

