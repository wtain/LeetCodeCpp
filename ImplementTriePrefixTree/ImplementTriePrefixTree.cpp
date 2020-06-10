
#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

class Trie {
public:

	struct Node {
		bool isEnd;
		unordered_map<char, Node*> children;

		Node() : isEnd(false) {}
	};

	Node root;

	/** Initialize your data structure here. */
	Trie() {
		
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

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/

int main()
{
	Trie trie = Trie();

	trie.insert("apple");
	cout << boolalpha << trie.search("apple") << endl;   // returns true
	cout << boolalpha << trie.search("app") << endl;     // returns false
	cout << boolalpha << trie.startsWith("app") << endl; // returns true
	trie.insert("app");
	cout << boolalpha << trie.search("app") << endl;     // returns true

    return 0;
}

