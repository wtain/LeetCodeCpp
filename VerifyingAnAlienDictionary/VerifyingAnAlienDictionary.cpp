
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/verifying-an-alien-dictionary/

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.



Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '?', where '?' is defined as the blank character which is less than any other character (More info).


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
*/

//Runtime: 12 ms, faster than 45.61% of C++ online submissions for Verifying an Alien Dictionary.
//Memory Usage : 9.4 MB, less than 98.93% of C++ online submissions for Verifying an Alien Dictionary.
class Solution {
public:

	vector<int> getOrder(const string& s) {
		vector<int> result(26);
		for (int i = 0; i < s.length(); ++i)
			result[s[i] - 'a'] = i;
		return result;
	}

	// s1 < s2
	bool compare(const string& s1, const string& s2, const vector<int>& order) {
		const auto n1 = s1.length();
		const auto n2 = s2.length();
		const auto n = min(n1, n2);
		for (auto i = 0; i < n; ++i) {
			if (order[s1[i] - 'a'] > order[s2[i] - 'a'])
				return false;
			if (order[s1[i] - 'a'] < order[s2[i] - 'a'])
				return true;
		}
		return n1 <= n2;
	}

	bool isAlienSorted(vector<string>& words, string order) {
		const auto vorder = getOrder(order);
		const auto m = words.size();
		for (auto i = 1; i < m; ++i) {
			if (!compare(words[i - 1], words[i], vorder))
				return false;
		}
		return true;
	}
};

int main()
{
	cout << boolalpha << Solution().isAlienSorted(vector<string>{"hello", "leetcode"}, "hlabcdefgijkmnopqrstuvwxyz") << endl; // true
	cout << boolalpha << Solution().isAlienSorted(vector<string>{"word", "world", "row"}, "worldabcefghijkmnpqstuvxyz") << endl; // false
	cout << boolalpha << Solution().isAlienSorted(vector<string>{"apple", "app"}, "abcdefghijklmnopqrstuvwxyz") << endl; // false

    return 0;
}

