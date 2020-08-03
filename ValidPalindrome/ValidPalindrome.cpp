
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <functional>

using namespace std;

/*
https://leetcode.com/problems/valid-palindrome/
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3411/
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false


Constraints:

s consists only of printable ASCII characters.
*/

#include <cctype>

//Runtime: 16 ms, faster than 55.88% of C++ online submissions for Valid Palindrome.
//Memory Usage : 7.2 MB, less than 77.08% of C++ online submissions for Valid Palindrome.
class Solution {
public:

	struct is_alnum : std::unary_function<int, bool>
	{
		bool operator()(int i) const { return isalnum(i); }
	};

	bool isPalindrome(string s) {
		s.erase(
			remove_if(
				begin(s),
				end(s),
				not1(is_alnum())
				)
			, end(s));
		size_t n = s.length();
		size_t n2 = n >> 1;
		for (size_t i = 0; i < n2; ++i)
		{
			if (toupper(s[i]) != toupper(s[n - 1 - i]))
				return false;
		}
		return true;
	}
};

int main()
{
	cout << boolalpha << Solution().isPalindrome("A man, a plan, a canal: Panama") << endl; // true
	cout << boolalpha << Solution().isPalindrome("race a car") << endl; // false

    return 0;
}

