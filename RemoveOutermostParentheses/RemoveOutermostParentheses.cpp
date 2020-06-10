
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

/*
https://leetcode.com/problems/remove-outermost-parentheses/

A valid parentheses string is either empty (""), "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.  For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.

A valid parentheses string S is primitive if it is nonempty, and there does not exist a way to split it into S = A+B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string S, consider its primitive decomposition: S = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.

Return S after removing the outermost parentheses of every primitive string in the primitive decomposition of S.



Example 1:

Input: "(()())(())"
Output: "()()()"
Explanation:
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: "(()())(())(()(()))"
Output: "()()()()(())"
Explanation:
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: "()()"
Output: ""
Explanation:
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".


Note:

S.length <= 10000
S[i] is "(" or ")"
S is a valid parentheses string
*/

class Solution {
public:
	string removeOuterParentheses(string S) {
		ostringstream result;
		const size_t n = S.length();
		int balanse = 0;
		for (size_t i = 0; i < n; ++i) {
			if (balanse > 1 || balanse == 1 && S[i] == '(')
				result << S[i];
			if (S[i] == '(')
				++balanse;
			else
				--balanse;
		}
		return result.str();
	}
};

int main()
{
	cout << Solution().removeOuterParentheses("(()())(())") << endl; // "()()()"
	cout << Solution().removeOuterParentheses("(()())(())(()(()))") << endl; // "()()()()(())"
	cout << Solution().removeOuterParentheses("()()") << endl; // ""
    return 0;
}

