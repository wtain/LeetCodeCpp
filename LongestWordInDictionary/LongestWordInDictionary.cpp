
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

/*
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input:
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation:
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input:
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation:
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Note:

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].
*/

// 39.47%
class Solution {
public:

	struct Trie {

		struct TrieNode {
			bool isEnd;
			unordered_map<char, TrieNode*> children;

			explicit TrieNode() : isEnd(false) {
			}
		};

		TrieNode root;

		explicit Trie(const vector<string>& words) {
			for (const auto& word : words)
				addWord(word);
		}

		void addWord(const string& word) {
			int i = 0;
			TrieNode* node = &root;
			for (int i = 0; i < word.length(); ++i) {
				auto it = node->children.find(word[i]);
				if (it == end(node->children))
					it = node->children.emplace_hint(it, word[i], new TrieNode());
				node = it->second;
			}
			node->isEnd = true;
		}
	};

	string longestWord(vector<string>& words) {
		Trie trie{ words };
		stack<pair<Trie::TrieNode*, string>> toVisit;
		toVisit.emplace(&trie.root, "");
		string longest;
		while (!toVisit.empty()) {
			//auto [pNode, w] = toVisit.top(); // C++ 17
			auto pNode = toVisit.top().first;
			auto w = toVisit.top().second;
			toVisit.pop();
			if (longest.length() < w.length() || longest.length() == w.length() && longest > w)
				longest = w;
			for (const auto& p : pNode->children) {
				if (!p.second->isEnd)
					continue;
				toVisit.emplace(p.second, w + p.first);
			}
		}
		return longest;
	}
};

//38.18% 
//class Solution {
//public:
//
//	struct Trie {
//
//		struct TrieNode {
//			bool isEnd;
//			unordered_map<char, TrieNode*> children;
//
//			explicit TrieNode() : isEnd(false) {
//			}
//
//			TrieNode* addWord(const std::string& word, int i) {
//				if (i == word.length())
//					isEnd = true;
//				else {
//					auto it = children.find(word[i]);
//					if (it == end(children))
//						it = children.emplace_hint(it, word[i], new TrieNode());
//					it->second->addWord(word, i + 1);
//				}
//				return this;
//			}
//		};
//
//		TrieNode root;
//
//		explicit Trie(const vector<string>& words) {
//			for (const auto& word : words)
//				addWord(word);
//		}
//
//		void addWord(const string& word) {
//			root.addWord(word, 0);
//		}
//	};
//
//	string longestWord(vector<string>& words) {
//		Trie trie{ words };
//		stack<pair<Trie::TrieNode*, string>> toVisit;
//		toVisit.emplace(&trie.root, "");
//		string longest;
//		while (!toVisit.empty()) {
//			//auto [pNode, w] = toVisit.top(); // C++ 17
//			auto pNode = toVisit.top().first;
//			auto w = toVisit.top().second;
//			toVisit.pop();
//			if (longest.length() < w.length() || longest.length() == w.length() && longest > w)
//				longest = w;
//			for (const auto& p : pNode->children) {
//				if (!p.second->isEnd)
//					continue;
//				toVisit.emplace(p.second, w + p.first);
//			}
//		}
//		return longest;
//	}
//};

int main()
{
	cout << Solution().longestWord(vector<string>{ "w","wo","wor","worl", "world" }) << endl; // "world"
	cout << Solution().longestWord(vector<string>{ "a", "banana", "app", "appl", "ap", "apply", "apple" }) << endl; // "apple"
	cout << Solution().longestWord(vector<string>{ "m", "mo", "moc", "moch", "mocha", "l", "la", "lat", "latt", "latte", "c", "ca", "cat" }) << endl; // "latte"

    return 0;
}

