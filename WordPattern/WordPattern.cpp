// WordPattern.cpp : Defines the entry point for the console application.
//

#include <string>
#include <map>
#include <iostream>
#include <iomanip>

using namespace std;

/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/
class Solution {
public:
	bool wordPattern(string pattern, string str)
	{
		map<char, string> patternToStr;
		map<string, char> stringToPattern;
		size_t pos = 0;
		for (size_t i = 0; i < pattern.size(); ++i)
		{
			if (pos >= str.length())
				return false;
			size_t pos1 = str.find(' ', pos);
			string word;
			if (pos1 == string::npos)
			{
				word = str.substr(pos);
				pos = pos1;
			}
			else
			{
				word = str.substr(pos, pos1 - pos);
				pos = pos1 + 1;
			}
			auto it1 = patternToStr.find(pattern[i]);
			if (it1 == patternToStr.end())
			{
				patternToStr.insert(it1, make_pair(pattern[i], word));
				stringToPattern.insert(make_pair(word, pattern[i]));
			}
			else if (it1->second != word)
				return false;

			auto it2 = stringToPattern.find(word);
			if (it2 == stringToPattern.end())
			{
				stringToPattern.insert(it2, make_pair(word, pattern[i]));
				patternToStr.insert(make_pair(pattern[i], word));
			}
			else if (it2->second != pattern[i])
				return false;
		}
		return pos >= str.length();
	}
};


int main()
{
	cout << boolalpha << Solution().wordPattern("abba", "dog cat cat dog") << endl;
	cout << boolalpha << Solution().wordPattern("aaa", "aa aa aa aa") << endl;

    return 0;
}

