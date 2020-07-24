
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/string-matching-in-an-array/
Given an array of string words. Return all strings in words which is substring of another word in any order.

String words[i] is substring of words[j], if can be obtained removing some characters to left and/or right side of words[j].



Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
It's guaranteed that words[i] will be unique.
*/

//Runtime: 4 ms, faster than 98.29% of C++ online submissions for String Matching in an Array.
//Memory Usage : 8.5 MB, less than 78.16% of C++ online submissions for String Matching in an Array.
//Runtime: 4 ms, faster than 98.29% of C++ online submissions for String Matching in an Array.
//Memory Usage : 8.5 MB, less than 77.19% of C++ online submissions for String Matching in an Array.
//class Solution {
//public:
//	vector<string> stringMatching(vector<string>& words) {
//		vector<string> result;
//		const auto n = words.size();
//		vector<bool> added(n);
//		for (auto i = 0; i < n; ++i) {
//			for (auto j = 0; j < n; ++j) {
//				if (j == i || added[j] || words[j].length() > words[i].length())
//					continue;
//				if (string::npos != words[i].find(words[j])) {
//					result.push_back(words[j]);
//					added[j] = true;
//				}
//			}
//		}
//		return result;
//	}
//};

//Runtime: 20 ms, faster than 27.78% of C++ online submissions for String Matching in an Array.
//Memory Usage : 8.8 MB, less than 47.09% of C++ online submissions for String Matching in an Array.
class Solution {
public:

	vector<int> calcPrefix(const string& s) {
		vector<int> p(s.length());
		p[0] = 0;
		for (int i = 1; i < s.length(); ++i) {
			int k = p[i - 1];
			while (1) {
				if (s[i] == s[k]) {
					p[i] = k + 1;
					break;
				}
				else if (k == 0) {
					p[i] = 0;
					break;
				}
				else {
					k = p[k - 1];
				}
			}
		}
		return p;
	}

	vector<string> stringMatching(vector<string>& words) {
		vector<string> result;
		const auto n = words.size();
		vector<bool> added(n);
		vector<vector<int>> prefixes(n);
		for (auto i = 0; i < n; ++i)
			prefixes[i] = calcPrefix(words[i]);

		for (auto i = 0; i < n; ++i) {
			for (auto j = 0; j < n; ++j) {
				if (j == i || added[j] || words[j].length() > words[i].length())
					continue;

				for (int k = 0, l = 0; k < words[i].length(); ++k) {
					if (words[i][k] == words[j][l]) {
						++l;
						if (l == words[j].length()) {
							result.push_back(words[j]);
							added[j] = true;
							break;
						}
					}
					else {
						while (l && words[i][k] != words[j][l])
							l = prefixes[j][l - 1];
						if (words[i][k] == words[j][l])
							++l;
					}
				}
			}
		}
		return result;
	}
};

void print(const vector<string>& r) {
	copy(begin(r), end(r), ostream_iterator<string>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().stringMatching(vector<string>{"leetcoder", "leetcode", "od", "hamlet", "am"})); // "leetcode","od","am"
	print(Solution().stringMatching(vector<string>{"mass", "as", "hero", "superhero"})); // "as", "hero"
	print(Solution().stringMatching(vector<string>{"leetcode", "et", "code"})); // "et", "code"
	print(Solution().stringMatching(vector<string>{"blue", "green", "bu"})); // 

    return 0;
}

