
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/longest-uncommon-subsequence-i/

Given two strings, you need to find the longest uncommon subsequence of this two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other string.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.



Example 1:

Input: a = "aba", b = "cdc"
Output: 3
Explanation: The longest uncommon subsequence is "aba",
because "aba" is a subsequence of "aba",
but not a subsequence of the other string "cdc".
Note that "cdc" can be also a longest uncommon subsequence.
Example 2:

Input: a = "aaa", b = "bbb"
Output: 3
Example 3:

Input: a = "aaa", b = "aaa"
Output: -1


Constraints:

Both strings' lengths will be between [1 - 100].
Only letters from a ~ z will appear in input strings.
*/

class Solution {
public:

	//class Matrix
	//{
	//	int n, m;
	//	vector<int> data;
	//public:
	//	Matrix(int n_, int m_) : n(n_), m(m_) {
	//		data.resize(n*m);
	//	}

	//	int& operator() (int i, int j)
	//	{
	//		return data[i*n + j];
	//	}
	//};

	int findLUSlength(string a, string b) {
		//int n = a.length();
		//int m = b.length();
		//Matrix M(n+1, m+1);
		if (a == b)
			return -1;
		return max(a.length(), b.length());
	}
};

int main()
{
	cout << Solution().findLUSlength("aba", "cdc") << endl; // 3
	cout << Solution().findLUSlength("aaa", "bbb") << endl; // 3
	cout << Solution().findLUSlength("aaa", "aaa") << endl; // -1

    return 0;
}

