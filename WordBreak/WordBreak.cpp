
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

/*
https://leetcode.com/problems/word-break/

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/

// TLE
//class Solution {
//public:
//
//	bool wordBreakImpl(const string& s, const unordered_set<string>& wordDict, const size_t i0, const size_t n) {
//		if (i0 == n)
//			return true;
//		string c;
//		for (size_t i = i0; i < n; ++i) {
//			c += s[i];
//			if (wordDict.find(c) != end(wordDict) && wordBreakImpl(s, wordDict, i+1, n))
//				return true;
//		}
//		return false;
//	}
//
//	unordered_set<string> buildDictionary(const vector<string>& wordDict) {
//		unordered_set<string> result;
//		copy(begin(wordDict), end(wordDict), inserter(result, end(result)));
//		return result;
//	}
//
//	bool wordBreak(string s, vector<string>& wordDict) {
//		return wordBreakImpl(s, buildDictionary(wordDict), 0, s.length());
//	}
//};

// TLE
//class Solution {
//public:
//
//	bool wordBreakImpl(const string& s, const unordered_set<string>& wordDict, unordered_set<string>& accepted, const size_t i0, const size_t n) {
//		auto it = accepted.find(s.substr(i0));
//		if (it != end(accepted))
//			return true;
//		if (i0 == n)
//			return true;
//		string c;
//		for (size_t i = i0; i < n; ++i) {
//			c += s[i];
//			if (wordDict.find(c) != end(wordDict)) {
//				accepted.insert(s.substr(0, i + 1));
//				if (wordBreakImpl(s, wordDict, accepted, i + 1, n))
//					return true;
//			}
//		}
//		return false;
//	}
//
//	unordered_set<string> buildDictionary(const vector<string>& wordDict) {
//		unordered_set<string> result;
//		copy(begin(wordDict), end(wordDict), inserter(result, end(result)));
//		return result;
//	}
//
//	bool wordBreak(string s, vector<string>& wordDict) {
//		return wordBreakImpl(s, buildDictionary(wordDict), unordered_set<string>{}, 0, s.length());
//	}
//};

//Runtime: 16 ms, faster than 66.53% of C++ online submissions for Word Break.
//Memory Usage : 7.4 MB, less than 98.52% of C++ online submissions for Word Break.
class Solution {
public:

	bool wordBreak(string s, vector<string>& wordDict) {
		const size_t n = s.length();
		vector<bool> dp(n);
		string c;
		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < wordDict.size(); ++j) {
				const size_t m = wordDict[j].length();
				int i0 = i - m + 1;
				if (i >= m - 1 && s.substr(i0, m) == wordDict[j]) {
					if (!i0 || dp[i0 - 1])
						dp[i] = true;
				}
			}
		}
		return dp[n - 1];
	}
};

int main()
{
	cout << boolalpha << Solution().wordBreak("leetcode", vector<string>{"leet", "code"}) << endl; // true
	cout << boolalpha << Solution().wordBreak("applepenapple", vector<string>{"apple", "pen"}) << endl; // true
	cout << boolalpha << Solution().wordBreak("catsandog", vector<string>{"cats", "dog", "sand", "and", "cat"}) << endl; // false

	cout << boolalpha << Solution().wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", vector<string>{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"}) << endl; // false

    return 0;
}

