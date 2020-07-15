
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/reverse-words-in-a-string/

Given an input string, reverse the string word by word.



Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.


Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

*/

//Runtime: 36 ms, faster than 15.59% of C++ online submissions for Reverse Words in a String.
//Memory Usage : 120.1 MB, less than 9.33% of C++ online submissions for Reverse Words in a String.
//class Solution {
//public:
//
//	void addWord(string& result, string& cw) {
//		if (!cw.empty()) {
//			if (!result.empty())
//				result = " " + result;
//			result = cw + result;
//			cw = "";
//		}
//	}
//
//	string reverseWords(string s) {
//		string result, cw;
//
//		for (auto c : s) {
//			if (c == ' ') {
//				addWord(result, cw);
//			}
//			else {
//				cw += c;
//			}
//		}
//		addWord(result, cw);
//
//		return result;
//	}
//};

//Runtime: 40 ms, faster than 12.37% of C++ online submissions for Reverse Words in a String.
//Memory Usage : 7.4 MB, less than 85.56% of C++ online submissions for Reverse Words in a String.
class Solution {
public:

	size_t reverseWord(string& s, size_t i, size_t j, size_t w) {
		auto m = j - i;
		--j;
		auto r = w + m;
		while (w < j) {
			swap(s[w++], s[j--]);
		}
		return r;
	}

	string reverseWords(string s) {
		
		const auto n = s.length();
		size_t i = 0;

		size_t w = 0;
		while (i < n) {
			while (i < n && s[i] == ' ')
				++i;
			if (i == n)
				break;
			auto j = s.find(' ', i);
			if (j == string::npos)
				j = n;
			w = reverseWord(s, i, j, w);

			s[w++] = ' ';

			i = j;
		}

		if (w > 0)
			--w;

		s.resize(w);

		reverse(begin(s), end(s));

		return s;
	}
};

int main()
{
	cout << Solution().reverseWords("the sky is blue") << endl; // "blue is sky the"
	cout << Solution().reverseWords("  hello world!  ") << endl; // "world! hello"
	cout << Solution().reverseWords("a good   example") << endl; // "example good a"

    return 0;
}

