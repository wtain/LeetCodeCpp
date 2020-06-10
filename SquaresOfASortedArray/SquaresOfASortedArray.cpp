
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/squares-of-a-sorted-array/

Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.



Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]


Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
*/

class Solution {
public:

	static int sqr(int x) {
		return x * x;
	}

	vector<int> sortedSquares(vector<int>& A) {
		vector<int> result;
		const size_t n = A.size();
		result.reserve(n);
		auto it = lower_bound(begin(A), end(A), 0);
		int i = it - begin(A);
		int i_neg = i - 1;
		int i_pos = i;

		while (i_neg >= 0 || i_pos < n) {
			bool hasleft = i_neg >= 0;
			bool hasright = i_pos < n;

			if (hasleft && hasright) {
				if (abs(A[i_neg]) < abs(A[i_pos])) {
					result.push_back(sqr(A[i_neg--]));
				}
				else {
					result.push_back(sqr(A[i_pos++]));
				}
			} else if (hasleft) 
				result.push_back(sqr(A[i_neg--]));
			else
				result.push_back(sqr(A[i_pos++]));
		}

		return result;
	}
};

int main()
{
	{
		auto r = Solution().sortedSquares(vector<int>{-4, -1, 0, 3, 10});
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	{
		auto r = Solution().sortedSquares(vector<int>{-7, -3, 2, 3, 11});
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	{
		auto r = Solution().sortedSquares(vector<int>{-3, -2, -1});
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

    return 0;
}

