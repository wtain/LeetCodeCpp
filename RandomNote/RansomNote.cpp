
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

/*
https://leetcode.com/problems/ransom-note/

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

//class Solution {
//public:
//
//	vector<int> buidlHist(const string& s) {
//		vector<int> rv;
//		rv.resize(256);
//		for (int i = 0; i < s.length(); ++i)
//			++rv[s[i]];
//		return rv;
//	}
//
//	bool canConstruct(string ransomNote, string magazine) {
//		auto h1 = buidlHist(ransomNote);
//		auto h2 = buidlHist(magazine);
//		for (int i = 0; i < 256; ++i)
//			if (h1[i] > h2[i])
//				return false;
//		return true;
//	}
//};

class Solution {
public:

	bool canConstruct(string ransomNote, string magazine) {
		vector<int> h;
		h.resize(256);

		int n = magazine.length();

		for (int i = 0; i < n; ++i)
			++h[magazine[i]];

		n = ransomNote.length();

		for (int i = 0; i < n; ++i)
			if (--h[ransomNote[i]] < 0)
				return false;

		return true;
	}
};

int main()
{
	cout << boolalpha << Solution().canConstruct("a", "b") << endl; // -> false
	cout << boolalpha << Solution().canConstruct("aa", "ab") << endl; // -> false
	cout << boolalpha << Solution().canConstruct("aa", "aab") << endl; // -> true

    return 0;
}

