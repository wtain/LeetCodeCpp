
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/h-index-ii/
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3364/

Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N ? h papers have no more than h citations each."

Example:

Input: citations = [0,1,3,5,6]
Output: 3
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had
received 0, 1, 3, 5, 6 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining
two with no more than 3 citations each, her h-index is 3.
Note:

If there are several possible values for h, the maximum one is taken as the h-index.

Follow up:

This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
Could you solve it in logarithmic time complexity?

*/

//Runtime: 44 ms
//Memory Usage : 18.9 MB
// 47.92%
class Solution {
public:
	int hIndex(vector<int>& citations) {
		const int n = citations.size();
		int l = 0, r = n;
		while (l < r) {
			int m = l + (r - l) / 2;
			int h = n - m;
			if (citations[m] >= h)
				r = m;
			else if (citations[m] < h)
				l = m + 1;
		}
		return n - l;
	}
};

int main()
{
	cout << Solution().hIndex(vector<int>{0, 1, 3, 5, 6}) << endl; // 3 
	cout << Solution().hIndex(vector<int>{0, 1, 3, 3, 6}) << endl; // 3 

    return 0;
}

