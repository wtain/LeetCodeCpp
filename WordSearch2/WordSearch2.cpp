
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
https://leetcode.com/problems/word-search-ii/
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/543/week-5-june-29th-june-30th/3376/

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



Example:

Input:
board = [
['o','a','a','n'],
['e','t','a','e'],
['i','h','k','r'],
['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]


Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/

//Runtime: 180 ms, faster than 52.46% of C++ online submissions for Word Search II.
//Memory Usage : 51.3 MB, less than 33.53% of C++ online submissions for Word Search II.
class Solution {

	class Trie {
	public:

		struct Node {
			bool isEnd;
			unordered_map<char, Node*> children;

			Node() : isEnd(false) {}

			Node* getChild(char c) const {
				auto it = children.find(c);
				return it == end(children) ? nullptr : it->second;
			}
		};

		Node root;

		/** Initialize your data structure here. */
		Trie() {

		}

		void insert(vector<string>& words) {
			for (const auto& w : words)
				insert(w);
		}

		/** Inserts a word into the trie. */
		void insert(string word) {
			Node* pRoot = &root;
			const size_t n = word.length();
			for (size_t i = 0; i < n; ++i) {
				const char c = word[i];
				auto it = pRoot->children.find(c);
				if (it == end(pRoot->children))
					pRoot->children.emplace_hint(it, make_pair(c, new Node()));
				pRoot = pRoot->children[c];
			}
			pRoot->isEnd = true;
		}

		/** Returns if the word is in the trie. */
		bool search(string word) {
			const Node* pNode = searchImpl(word);
			return !!pNode && pNode->isEnd;
		}

		/** Returns if there is any word in the trie that starts with the given prefix. */
		bool startsWith(string prefix) {
			return !!searchImpl(prefix);
		}

		const Node* searchImpl(const string& prefix) const {
			const Node* pCurrent = &root;
			const size_t n = prefix.length();
			for (size_t i = 0; i < n; ++i) {
				const char c = prefix[i];
				auto it = pCurrent->children.find(c);
				if (it == end(pCurrent->children))
					return nullptr;
				pCurrent = it->second;
			}
			return pCurrent;
		}
	};

	int w, h;
	vector<vector<bool>> visited;
	unordered_set<string> found;
	Trie trie;
public:

	void match(const int i, const int j, const vector<vector<char>>& board, Trie::Node* root, const string& word) {
		if (i < 0 || j < 0 || i >= h || j >= w)
			return;
		if (visited[i][j])
			return;

		const auto cnode = root->getChild(board[i][j]);

		if (!cnode)
			return;
		
		const auto newword = word + board[i][j];

		if (cnode->isEnd)
			found.insert(newword);

		visited[i][j] = true;
		match(i - 1, j, board, cnode, newword);
		match(i + 1, j, board, cnode, newword);
		match(i, j - 1, board, cnode, newword);
		match(i, j + 1, board, cnode, newword);
		visited[i][j] = false;
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> result;

		h = board.size();
		w = board[0].size();
		visited.resize(h, vector<bool>(w, false));
		trie.insert(words);
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				match(i, j, board, &trie.root, "");
				if (found.size() == words.size())
					break;
			}
			if (found.size() == words.size())
				break;
		}
		
		result.reserve(found.size());
		copy(begin(found), end(found), back_inserter(result));

		return result;
	}
};

int main()
{
	{
		vector<vector<char>> board = {
			{ 'a','b' },
			{ 'a','a' }
		};
		vector<string> words = { "aba", "baa", "bab", "aaab", "aaa", "aaaa", "aaba" };
		const auto r = Solution().findWords(board, words); // ["aaa","aaab","aaba","aba","baa"]
		copy(begin(r), end(r), ostream_iterator<string>(cout, " "));
		cout << endl;
	}

	{
		vector<vector<char>> board = {
			{ 'a','b' },
			{ 'a','a' }
		};
		//vector<string> words = { "aba", "baa", "bab", "aaab", "aaa", "aaaa", "aaba" };
		vector<string> words = { "aaab" };
		const auto r = Solution().findWords(board, words); // ["aaab"]
		copy(begin(r), end(r), ostream_iterator<string>(cout, " "));
		cout << endl;
	}

	{
		vector<vector<char>> board = {
			{ 'o','a','a','n' },
			{ 'e','t','a','e' },
			{ 'i','h','k','r' },
			{ 'i','f','l','v' }
		};
		vector<string> words = { "oath","pea","eat","rain" };
		const auto r = Solution().findWords(board, words); // "eat","oath"
		copy(begin(r), end(r), ostream_iterator<string>(cout, " "));
		cout << endl;
	}

    return 0;
}

