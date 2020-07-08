
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <list>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/word-break-ii/

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
"cats and dog",
"cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
"pine apple pen apple",
"pineapple pen apple",
"pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]

*/

// TLE
//class Solution {
//public:
//	vector<string> wordBreak(string s, vector<string>& wordDict) {
//		const size_t n = s.length();
//		const size_t m = wordDict.size();
//		vector<int> dp(n+1, -1);
//		vector<vector<bool>> matrix(n, vector<bool>(m));
//		dp[0] = true;
//		string c;
//		for (size_t i = 0; i < n; ++i) {
//			for (size_t j = 0; j < m; ++j) {
//				const size_t m = wordDict[j].length();
//				int i0 = i - m + 1;
//				if (i >= m - 1 && s.substr(i0, m) == wordDict[j]) {
//					if (!i0 || dp[i0] != -1) {
//						dp[i + 1] = j;
//					}
//					matrix[i0][j] = true;
//				}
//			}
//		}
//		vector<string> result;
//		stack<pair<int, string>> toVisit;
//		toVisit.emplace(0, "");
//		while (!toVisit.empty()) {
//			auto p = toVisit.top();
//			toVisit.pop();
//			if (p.first == n) {
//				result.push_back(p.second);
//			}
//			else {
//				for (int j = 0; j < m; ++j) {
//					if (matrix[p.first][j]) {
//						auto pnext = p;
//						pnext.first += wordDict[j].length();
//						if (!pnext.second.empty())
//							pnext.second += " ";
//						pnext.second += wordDict[j];
//						toVisit.push(pnext);
//					}
//				}
//			}
//		}
//
//		return result;
//	}
//};

// TLE
//class Solution {
//public:
//	vector<string> wordBreak(string s, vector<string>& wordDict) {
//		const size_t n = s.length();
//		const size_t m = wordDict.size();
//		vector<int> dp(n + 1, -1);
//		vector<vector<bool>> forward_matrix(n, vector<bool>(m));
//		vector<vector<bool>> backward_matrix(n, vector<bool>(m));
//		dp[0] = true;
//		string c;
//		for (size_t i = 0; i < n; ++i) {
//			for (size_t j = 0; j < m; ++j) {
//				const size_t m = wordDict[j].length();
//				int i0 = i - m + 1;
//				if (i >= m - 1 && s.substr(i0, m) == wordDict[j]) {
//					if (!i0 || dp[i0] != -1) {
//						dp[i + 1] = j;
//					}
//					forward_matrix[i0][j] = true;
//					backward_matrix[i][j] = true;
//				}
//			}
//		}
//		vector<string> result;
//		stack<pair<int, string>> toVisit;
//		toVisit.emplace(n-1, "");
//		while (!toVisit.empty()) {
//			auto p = toVisit.top();
//			toVisit.pop();
//			for (int j = 0; j < m; ++j) {
//				if (backward_matrix[p.first][j]) {
//					auto pnext = p;
//					pnext.first -= wordDict[j].length();
//					if (!pnext.second.empty())
//						pnext.second = " " + pnext.second;
//					pnext.second = wordDict[j] + pnext.second;
//					if (pnext.first >= 0)
//						toVisit.push(pnext);
//					else
//						result.push_back(pnext.second);
//				}
//			}
//		}
//
//		return result;
//	}
//};

// TLE
//class Solution {
//public:
//	vector<string> wordBreak(string s, vector<string>& wordDict) {
//		const size_t n = s.length();
//		const size_t m = wordDict.size();
//		vector<int> dp(n + 1, -1);
//		vector<vector<string>> res(n + 1);
//		
//		res[0].emplace_back("");
//
//		string c;
//		for (size_t i = 0; i < n; ++i) {
//			for (size_t j = 0; j < m; ++j) {
//				const size_t lj = wordDict[j].length();
//				int i0 = i - lj + 1;
//				if (i >= lj - 1 && s.substr(i0, lj) == wordDict[j]) {
//					if (!i0 || dp[i0] != -1) {
//						dp[i + 1] = j;
//
//						for (const auto& ri : res[i0]) {
//							auto r = ri;
//							if (!r.empty())
//								r += " ";
//							r += wordDict[j];
//							res[i+1].push_back(r);
//						}
//					}
//				}
//			}
//		}
//
//		return res[n];
//	}
//};

// TLE
//class Solution {
//public:
//	vector<string> wordBreak(string s, vector<string>& wordDict) {
//		const size_t n = s.length();
//		const size_t m = wordDict.size();
//		vector<int> dp(n + 1, -1);
//		vector<vector<string>> res(n + 1);
//
//		res[0].emplace_back("");
//
//		// prefix! ps[i] > 0 => dp[i] in dp[i-ps[i]]
//
//		string c;
//		for (size_t i = 0; i < n; ++i) {
//			for (size_t j = 0; j < m; ++j) {
//				const size_t lj = wordDict[j].length();
//				int i0 = i - lj + 1;
//				if (i >= lj - 1 && s.substr(i0, lj) == wordDict[j]) {
//					if (!i0 || dp[i0] != -1) {
//						dp[i + 1] = j;
//
//						for (const auto& ri : res[i0]) {
//							auto r = ri;
//							if (!r.empty())
//								r += " ";
//							r += wordDict[j];
//							res[i + 1].push_back(r);
//						}
//					}
//				}
//			}
//		}
//
//		return res[n];
//	}
//};

// Prefix?

//Runtime: 36 ms, faster than 33.86% of C++ online submissions for Word Break II.
//Memory Usage : 8.9 MB, less than 96.30% of C++ online submissions for Word Break II.
//Runtime: 32 ms, faster than 41.23% of C++ online submissions for Word Break II.
//Memory Usage : 9.1 MB, less than 92.99% of C++ online submissions for Word Break II.
//class Solution {
//public:
//	vector<string> wordBreak(string s, vector<string>& wordDict) {
//		const size_t n = s.length();
//		const size_t m = wordDict.size();
//		vector<int> dp(n+1, -1);
//		vector<vector<bool>> matrix(n, vector<bool>(m));
//		dp[0] = m + 1;
//		for (size_t i = 0; i < n; ++i) {
//			for (size_t j = 0; j < m; ++j) {
//				const size_t m = wordDict[j].length();
//				int i0 = i - m + 1;
//				if (i >= m - 1 && s.substr(i0, m) == wordDict[j]) {
//					if (dp[i0] != -1) {
//						dp[i + 1] = j;
//					}
//					matrix[i0][j] = true;
//				}
//			}
//		}
//		if (dp[n] == -1)
//			return{};
//		vector<string> result;
//		stack<pair<int, string>> toVisit;
//		toVisit.emplace(0, "");
//		while (!toVisit.empty()) {
//			auto p = toVisit.top();
//			toVisit.pop();
//			if (p.first == n) {
//				result.push_back(p.second);
//			}
//			else {
//				for (int j = 0; j < m; ++j) {
//					if (matrix[p.first][j]) {
//						auto pnext = p;
//						pnext.first += wordDict[j].length();
//						if (!pnext.second.empty())
//							pnext.second += " ";
//						pnext.second += wordDict[j];
//						toVisit.push(pnext);
//					}
//				}
//			}
//		}
//
//		return result;
//	}
//};

//Runtime: 28 ms, faster than 49.57% of C++ online submissions for Word Break II.
//Memory Usage : 11.2 MB, less than 64.65% of C++ online submissions for Word Break II.
class Solution {
	unordered_map<string, vector<string>> cache;
public:

	unordered_set<string> buildDictionary(const vector<string>& wordDict) {
		unordered_set<string> result;
		copy(begin(wordDict), end(wordDict), inserter(result, end(result)));
		return result;
	}

	vector<string> wordBreakImpl(const string& s, const unordered_set<string>& wordDict) {
		auto wit = cache.find(s);
		if (wit != end(cache))
			return wit->second;
		const size_t n = s.length();
		if (!n)
			return{ "" };
		vector<string> res;
		string c;
		for (size_t i = 0; i < n; ++i) {
			c += s[i];
			if (wordDict.find(c) != end(wordDict)) {
				auto r = wordBreakImpl(s.substr(i + 1), wordDict);

				for (const auto& ri : r) {
					auto r = c;
					if (!ri.empty())
						r += " " + ri;
					res.push_back(r);
				}
			}
		}

		return cache[s] = res;
	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {
		return wordBreakImpl(s, buildDictionary(wordDict));
	}
};

// NOT FINISHED
//class Solution {
//public:
//	vector<string> wordBreak(string s, vector<string>& wordDict) {
//		const size_t n = s.length();
//		const size_t m = wordDict.size();
//		vector<int> dp(n + 1, -1);
//		vector<vector<bool>> matrix(n, vector<bool>(m));
//		unordered_map<string, int> cache;
//		dp[0] = m + 1;
//		string c;
//		for (size_t i = 0; i < n; ++i) {
//			c += s[i];
//			for (size_t j = 0; j < m; ++j) {
//				const size_t m = wordDict[j].length();
//				int i0 = i - m + 1;
//				if (i >= m - 1 && s.substr(i0, m) == wordDict[j]) {
//					if (dp[i0] != -1) {
//						dp[i + 1] = j;
//					}
//					matrix[i0][j] = true;
//					cache[c] = i;
//					const auto si = s.substr(i+1);
//					auto it = cache.find(si);
//					if (it != end(cache)) {
//						for (; i < n; ++i) {
//							for (size_t j = 0; j < m; ++j);
//						}
//					}
//				}
//			}
//		}
//		if (dp[n] == -1)
//			return{};
//		vector<string> result;
//		stack<pair<int, string>> toVisit;
//		toVisit.emplace(0, "");
//		while (!toVisit.empty()) {
//			auto p = toVisit.top();
//			toVisit.pop();
//			if (p.first == n) {
//				result.push_back(p.second);
//			}
//			else {
//				for (int j = 0; j < m; ++j) {
//					if (matrix[p.first][j]) {
//						auto pnext = p;
//						pnext.first += wordDict[j].length();
//						if (!pnext.second.empty())
//							pnext.second += " ";
//						pnext.second += wordDict[j];
//						toVisit.push(pnext);
//					}
//				}
//			}
//		}
//
//		return result;
//	}
//};

//#pragma message("!!!!!!!!!!!!!!!!!!!!!!!! Not solved problem, HARD")

void print(const vector<string>& s) {
	copy(begin(s), end(s), ostream_iterator<string>(cout, "\n"));
	cout << endl;
}

int main()
{
	/*
	Example 1:

	Input:
	s = "catsanddog"
	wordDict = ["cat", "cats", "and", "sand", "dog"]
	Output:
	[
	"cats and dog",
	"cat sand dog"
	]
	*/
	print(Solution().wordBreak("catsanddog", vector<string>{"cat", "cats", "and", "sand", "dog"}));

	/*
	Example 2:

	Input:
	s = "pineapplepenapple"
	wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
	Output:
	[
	"pine apple pen apple",
	"pineapple pen apple",
	"pine applepen apple"
	]
	Explanation: Note that you are allowed to reuse a dictionary word.
	*/
	print(Solution().wordBreak("pineapplepenapple", vector<string>{"apple", "pen", "applepen", "pine", "pineapple"}));

	/*
	Example 3:

	Input:
	s = "catsandog"
	wordDict = ["cats", "dog", "sand", "and", "cat"]
	Output:
	[]
	*/
	print(Solution().wordBreak("catsandog", vector<string>{"cats", "dog", "sand", "and", "cat"}));


	print(Solution().wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", vector<string>{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"}));

    return 0;
}

