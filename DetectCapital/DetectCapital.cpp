
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
https://leetcode.com/problems/detect-capital/

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.


Example 1:

Input: "USA"
Output: True


Example 2:

Input: "FlaG"
Output: False

*/

class Solution {
public:
	bool detectCapitalUse(string word) {
		if (word.length() < 2)
			return true;
		bool allow_upper = isupper(word[0]);
		bool allow_lower = islower(word[1]);
		if (!allow_upper && !allow_lower)
			return false;
		if (allow_lower)
			allow_upper = false;
		for (int i = 2; i < word.length(); ++i) {
			if (!allow_upper && isupper(word[i]))
				return false;
			if (!allow_lower && islower(word[i]))
				return false;
		}
		return true;
	}
};

int main()
{
	cout << boolalpha << Solution().detectCapitalUse("USA") << endl; // true
	cout << boolalpha << Solution().detectCapitalUse("FlaG") << endl; // false
	cout << boolalpha << Solution().detectCapitalUse("leetcode") << endl; // true
	cout << boolalpha << Solution().detectCapitalUse("Google") << endl; // true
    return 0;
}

