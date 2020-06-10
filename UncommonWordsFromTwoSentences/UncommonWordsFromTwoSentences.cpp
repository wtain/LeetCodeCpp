
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
https://leetcode.com/problems/uncommon-words-from-two-sentences/

We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words.

You may return the list in any order.



Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]


Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.
*/

class Solution {
public:

	void fillWords(unordered_set<string>& words, unordered_set<string>& seen, const string& str) {
		const size_t n = str.length();
		size_t i = 0;
		while (i < n) {
			size_t j = str.find(' ', i);
			auto word = j != string::npos ? str.substr(i, j - i) : str.substr(i);
			i = j != string::npos ? j + 1 : n;
			auto sit = seen.find(word);
			if (sit != end(seen)) {
				words.erase(word);
				continue;
			}
			seen.emplace_hint(sit, word);
			words.insert(word);
		}
	}

	vector<string> uncommonFromSentences(string A, string B) {
		unordered_set<string> words, seen;
		fillWords(words, seen, A);
		fillWords(words, seen, B);

		vector<string> result;
		result.reserve(words.size());
		copy(begin(words), end(words), back_inserter(result));
		return result;
	}
};

int main()
{
	{
		auto a = Solution().uncommonFromSentences("this apple is sweet", "this apple is sour");
		copy(begin(a), end(a), ostream_iterator<string>(cout, " ")); // ["sweet","sour"]
		cout << endl;
	}
	{
		auto a = Solution().uncommonFromSentences("apple apple", "banana");
		copy(begin(a), end(a), ostream_iterator<string>(cout, " ")); //  ["banana"]
		cout << endl;
	}
    return 0;
}

