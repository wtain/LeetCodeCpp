
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/di-string-match/

Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]


Example 1:

Input: "IDID"
Output: [0,4,1,3,2]
Example 2:

Input: "III"
Output: [0,1,2,3]
Example 3:

Input: "DDI"
Output: [3,2,0,1]


Note:

1 <= S.length <= 10000
S only contains characters "I" or "D".

*/

//Runtime: 8 ms, faster than 92.09% of C++ online submissions for DI String Match.
//Memory Usage : 8.7 MB, less than 76.76% of C++ online submissions for DI String Match.
//class Solution {
//public:
//	vector<int> diStringMatch(string S) {
//		const auto n = S.length();
//		vector<int> result(n+1);
//
//		int vmin = 0, vmax = n;
//		if (S[0] == 'I')
//			result[0] = vmin++;
//		else
//			result[0] = vmax--;
//
//		for (int i = 1; i < n; ++i) {
//			if (S[i] == 'I')
//				result[i] = vmin++;
//			else
//				result[i] = vmax--;
//		}
//
//		result[n] = vmin;
//
//		return result;
//	}
//};

//Runtime: 12 ms, faster than 57.26% of C++ online submissions for DI String Match.
//Memory Usage : 8.5 MB, less than 88.73% of C++ online submissions for DI String Match.
class Solution {
public:
	vector<int> diStringMatch(string S) {
		const auto n = S.length();
		vector<int> result(n + 1);

		int vmin = 0, vmax = n;

		for (int i = 0; i < n; ++i) {
			if (S[i] == 'I')
				result[i] = vmin++;
			else
				result[i] = vmax--;
		}

		result[n] = vmin;

		return result;
	}
};

void print(const vector<int>& r) {
	copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().diStringMatch("IDID")); // [0,4,1,3,2]
	print(Solution().diStringMatch("III")); // [0,1,2,3]
	print(Solution().diStringMatch("DDI")); // [3,2,0,1]

    return 0;
}

