
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace std;

/*
https://leetcode.com/problems/goat-latin/
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3429/
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.

If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".

Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin.



Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"


Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.
*/

//Runtime: 4 ms, faster than 75.92% of C++ online submissions for Goat Latin.
//Memory Usage : 6.7 MB, less than 69.49% of C++ online submissions for Goat Latin.
class Solution {
public:
	string toGoatLatin(string S) {
		string result;
		const int n = S.length();
		int i = 0;
		vector<bool> vowels(256);
		vowels['a'] = vowels['e'] = vowels['i'] = vowels['o'] = vowels['u'] = true;
		vowels['A'] = vowels['E'] = vowels['I'] = vowels['O'] = vowels['U'] = true;
		string suffix;
		while (i < n) {
			string word;
			while (i < n && !isspace(S[i]))
				word += S[i++];
			while (i < n && isspace(S[i]))
				i++;
			if (!word.empty()) {
				if (!vowels[word[0]])
					word = word.substr(1) + word[0];
				word += "ma";
				suffix += "a";
				word += suffix;
				if (!result.empty())
					result += " ";
				result += word;
			}
		}
		return result;
	}
};

int main()
{
	cout << Solution().toGoatLatin("I speak Goat Latin") << endl; // "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
	cout << Solution().toGoatLatin("The quick brown fox jumped over the lazy dog") << endl; // "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"

    return 0;
}

