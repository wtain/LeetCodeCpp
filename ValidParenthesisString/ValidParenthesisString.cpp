
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/valid-parenthesis-string/

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
*/

// WRONG
//class Solution {
//public:
//	bool checkValidString(string s) {
//		int balanse = 0;
//		int stars = 0;
//		const int n = s.length();
//		for (int i = 0; i < n; ++i) {
//			if (s[i] == '(')
//				++balanse;
//			else if (s[i] == '*')
//				++stars;
//			else if (s[i] == ')') {
//				if (balanse > 0) {
//					if (!--balanse)
//						stars = 0;
//				} else if (stars > 0) {
//					--stars;
//				}
//				else {
//					return false;
//				}
//			}
//		}
//		return stars >= balanse;
//	}
//};

class Solution {
public:
	bool checkValidString(string s) {
		int lo = 0;
		int hi = 0;
		const int n = s.length();
		for (int i = 0; i < n; ++i) {
			lo += s[i] == '(' ? 1 : -1;
			hi += s[i] != ')' ? 1 : -1;
			if (hi < 0)
				return false;
			lo = max(lo, 0);
		}
		return lo == 0;
	}
};

int main()
{
	cout << boolalpha << Solution().checkValidString("(())((())()()(*)(*()(())())())()()((()())((()))(*") << endl; // false

	cout << boolalpha << Solution().checkValidString("()") << endl; // true
	cout << boolalpha << Solution().checkValidString("(*)") << endl; // true
	cout << boolalpha << Solution().checkValidString("(*))") << endl; // true

	cout << boolalpha << Solution().checkValidString("*)") << endl; // true
	cout << boolalpha << Solution().checkValidString("*") << endl; // true
	cout << boolalpha << Solution().checkValidString(")") << endl; // false
	cout << boolalpha << Solution().checkValidString("*)") << endl; // true
	cout << boolalpha << Solution().checkValidString(")*") << endl; // false
	cout << boolalpha << Solution().checkValidString("") << endl; // true
	
    return 0;
}

