
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <map>
#include <numeric>

using namespace std;

/*
https://leetcode.com/problems/h-index/

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N ? h papers have no more than h citations each."

Example:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had
received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining
two with no more than 3 citations each, her h-index is 3.
Note: If there are several possible values for h, the maximum one is taken as the h-index.

An easy approach is to sort the array first.
What are the possible values of h-index?
A faster approach is to use extra space.
*/

//Runtime: 8 ms, faster than 40.05% of C++ online submissions for H - Index.
//Memory Usage : 8.6 MB, less than 93.59% of C++ online submissions for H - Index.
//class Solution {
//public:
//	int hIndex(vector<int>& citations) {
//		sort(begin(citations), end(citations), greater<int>());
//		const auto n = citations.size();
//		int l = 0, r = n;
//		while (l < r) {
//			int m = l + (r - l) / 2;
//			if (citations[m] < m)
//				r = m;
//			else if (citations[m] > m)
//				l = m + 1;
//			else
//				return m;
//		}
//		return l;
//	}
//};

//Runtime: 4 ms, faster than 92.01% of C++ online submissions for H - Index.
//Memory Usage : 9.1 MB, less than 12.82% of C++ online submissions for H - Index.
class Solution {
public:
	int hIndex(vector<int>& citations) {
		const int n = citations.size();
		vector<int> hindex(n+1);
		//map<int, int> hindex;
		//unordered_map<int, int> hindex;
		for (int i = 0; i < n; ++i)
			hindex[n-min(citations[i], n)]++;

		partial_sum(begin(hindex), end(hindex), begin(hindex), plus<int>());

		for (int i = 0; i <= n; ++i) {
			int h = n - i;
			if (hindex[i] >= h)
				return h;
		}

		return 0;
	}
};

int main()
{
	cout << Solution().hIndex(vector<int>{3, 4, 5, 6, 7, 8, 4, 3, 6, 8, 5, 34, 6, 4}) << endl; // 6
	cout << Solution().hIndex(vector<int>{3}) << endl; // 1
	cout << Solution().hIndex(vector<int>{3, 0, 6, 1, 5}) << endl; // 3

    return 0;
}

