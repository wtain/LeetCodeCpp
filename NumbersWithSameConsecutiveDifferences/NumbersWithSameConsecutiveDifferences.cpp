
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/numbers-with-same-consecutive-differences/
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3428/
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.



Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]


Note:

1 <= N <= 9
0 <= K <= 9
*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Numbers With Same Consecutive Differences.
//Memory Usage : 7.3 MB, less than 76.62% of C++ online submissions for Numbers With Same Consecutive Differences.
class Solution {
public:

	vector<int> numsSameConsecDiff(int N, int K) {
		vector<int> result;
		for (int i = 0; i < 10; ++i)
			result.push_back(i);
		for (int n = 1; n < N; ++n) {
			vector<int> resultNext;
			for (auto x : result) {
				if (!x)
					continue;
				int d = x % 10;
				int d1 = d + K;
				int d2 = d - K;
				if (d1 <= 9)
					resultNext.emplace_back(10 * x + d1);
				if (d2 >= 0 && K)
					resultNext.emplace_back(10 * x + d2);
			}
			result.swap(resultNext);
		}

		return result;
	}
};

int main()
{
	{
		auto r = Solution().numsSameConsecDiff(3, 0);
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // 111 222 333 444 555 666 777 888 999
		cout << endl;
	}

	{
		auto r = Solution().numsSameConsecDiff(1, 0);
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // [0,1,2,3,4,5,6,7,8,9]
		cout << endl;
	}

	{
		auto r = Solution().numsSameConsecDiff(3, 7);
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // 181,292,707,818,929
		cout << endl;
	}

	{
		auto r = Solution().numsSameConsecDiff(2, 1);
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // 10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98
		cout << endl;
	}

	{
		auto r = Solution().numsSameConsecDiff(9, 9);
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // [909090909]
		cout << endl;
	}

    return 0;
}

