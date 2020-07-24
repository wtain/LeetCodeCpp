
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.



Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation:
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation:
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.


Note:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.

*/

//Runtime: 96 ms, faster than 88.90% of C++ online submissions for Find Words That Can Be Formed by Characters.
//Memory Usage : 20.4 MB, less than 67.18% of C++ online submissions for Find Words That Can Be Formed by Characters.
class Solution {
public:

	vector<int> getHist(const string& s) {
		vector<int> result(26);
		for (const auto c : s)
			result[c - 'a']++;
		return result;
	}

	int countCharacters(vector<string>& words, string chars) {
		const auto H = getHist(chars);
		int result = 0;
		for (const auto& w : words) {
			auto h = H;
			bool add = true;
			for (const auto c: w)
				if (--h[c - 'a'] < 0) {
					add = false;
					break;
				}
			if (add)
				result += w.length();
		}
		return result;
	}
};

int main()
{
	cout << Solution().countCharacters(vector<string>{"cat", "bt", "hat", "tree"}, "atach") << endl; // 6
	cout << Solution().countCharacters(vector<string>{"hello", "world", "leetcode"}, "welldonehoneyr") << endl; // 10

    return 0;
}

