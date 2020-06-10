
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/reverse-string-ii/

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]

*/

// SLOW (15%)
class Solution {
public:

	void reverse(string& s, int i, int i1) {
		int m = i + (i1 - i) / 2;
		for (int j = i; j < m; ++j)
			swap(s[j], s[i1 - 1 - (j-i)]);
	}

	string reverseStr(string s, int k) {
		int n = s.length();
		int i = 0;
		while (i < n) {
			int i1 = min(i + k, n);
			int i2 = i + 2 * k;
			reverse(s, i, i1);
			i = i2;
		}
		return s;
	}
};

// SLOWER?? 7 %
//class Solution {
//public:
//
//	string reverseStr(string s, int k) {
//		int n = s.length();
//		int i = 0;
//		while (i < n) {
//			int i1 = min(i + k, n);
//			int i2 = i + 2 * k;
//			
//			int m = i + (i1 - i) / 2;
//			for (int j = i; j < m; ++j)
//				swap(s[j], s[i1 - 1 - (j - i)]);
//
//			i = i2;
//		}
//		return s;
//	}
//};

int main()
{
	cout << Solution().reverseStr("abcdefg", 2) << endl; // "bacdfeg"

    return 0;
}

