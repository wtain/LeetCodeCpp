
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/uncrossed-lines/
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3340/

We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.



Example 1:


Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
Example 2:

Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2


Note:

1 <= A.length <= 500
1 <= B.length <= 500
1 <= A[i], B[i] <= 2000
Hide Hint #1
Think dynamic programming. Given an oracle dp(i,j) that tells us how many lines A[i:], B[j:] [the sequence A[i], A[i+1], ... and B[j], B[j+1], ...] are uncrossed, can we write this as a recursion?

*/

//Runtime: 16 ms
//Memory Usage : 13 MB
//class Solution {
//public:
//	int maxUncrossedLines(vector<int>& A, vector<int>& B) {
//		const size_t n = A.size(), m = B.size();
//		vector<vector<int>> M(n + 1, vector<int>(m + 1));
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < m; ++j) {
//				if (A[i] == B[j])
//					M[i + 1][j + 1] = M[i][j] + 1;
//				else
//					M[i + 1][j + 1] = max(M[i + 1][j], M[i][j + 1]);
//			}
//		}
//		return M[n][m];
//	}
//};

//Runtime: 12 ms
//Memory Usage : 10 MB
class Solution {
public:
	int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		const size_t n = A.size(), m = B.size();
		if (n > m)
			return maxUncrossedLines(B, A);
		vector<vector<int>> M(n + 1, vector<int>(2));
		for (int j = 0; j < m; ++j) {
			int j1 = j % 2;
			int j2 = 1 - j1;
			for (int i = 0; i < n; ++i) {
				if (A[i] == B[j])
					M[i + 1][j2] = M[i][j1] + 1;
				else
					M[i + 1][j2] = max(M[i + 1][j1], M[i][j2]);
			}
		}
		return M[n][m % 2];
	}
};

int main()
{
	cout << Solution().maxUncrossedLines(vector<int>{1, 4, 2}, vector<int>{1, 2, 4}) << endl; // 2
	cout << Solution().maxUncrossedLines(vector<int>{2, 5, 1, 2, 5}, vector<int>{10, 5, 2, 1, 5, 2}) << endl; // 3
	cout << Solution().maxUncrossedLines(vector<int>{1, 3, 7, 1, 7, 5}, vector<int>{1, 9, 2, 5, 1}) << endl; // 2

    return 0;
}

