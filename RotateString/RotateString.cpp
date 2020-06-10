
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
https://leetcode.com/problems/rotate-string/

We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
Note:

A and B will have length at most 100.
*/

class Solution {
public:
	bool rotateString(string A, string B) {
		const int n = A.length();
		if (B.length() != n)
			return false;
		string AA = A + A;
		return AA.find(B) != string::npos;
	}
};


int main()
{
	cout << boolalpha << Solution().rotateString("abcde", "cdeab") << endl; // true
	cout << boolalpha << Solution().rotateString("abcde", "abced") << endl; // false
    return 0;
}

