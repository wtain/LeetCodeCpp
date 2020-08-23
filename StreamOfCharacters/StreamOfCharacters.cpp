
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <list>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3434/
https://leetcode.com/problems/stream-of-characters/
Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.


Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist


Note:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.
*/

// TLE
//class StreamChecker {
//public:
//
//	class TrieNode {
//		vector<TrieNode*> children;
//		bool isEnd;
//	public:
//		TrieNode() : children(26), isEnd(false) {
//
//		}
//
//		void AddChild(char c) {
//			children[c - 'a'] = new TrieNode();
//		}
//
//		bool CanWalk(char c) const {
//			return !!children[c - 'a'];
//		}
//
//		TrieNode* Walk(char c) {
//			if (!CanWalk(c))
//				AddChild(c);
//			return children[c - 'a'];
//		}
//
//		bool IsEnd() const { return isEnd; }
//
//		void SetIsEnd() {
//			isEnd = true;
//		}
//	};
//
//	class Trie {
//		TrieNode root;
//	public:
//		Trie() {
//
//		}
//
//		void addWord(const string& w) {
//			TrieNode* current = &root;
//			for (auto c : w) {
//				current = current->Walk(c);
//			}
//			current->SetIsEnd();
//		}
//
//		TrieNode* GetRoot() { return &root; }
//	};
//
//	StreamChecker(vector<string>& words) {
//		for (const auto& w : words)
//			trie.addWord(w);
//	}
//
//	bool query(char letter) {
//		bool result = false;
//		pointers.emplace_back(trie.GetRoot());
//		for (auto it = begin(pointers); it != end(pointers);) {
//			if ((*it)->CanWalk(letter)) {
//				*it = (*it)->Walk(letter);
//				result = result || (*it)->IsEnd();
//				++it;
//			}
//			else
//				it = pointers.erase(it);
//		}
//		return result;
//	}
//
//private:
//	Trie trie;
//	list<TrieNode*> pointers;
//};

//Runtime: 1812 ms, faster than 5.12% of C++ online submissions for Stream of Characters.
//Memory Usage : 113.7 MB, less than 36.05% of C++ online submissions for Stream of Characters.
class StreamChecker {
public:

	class TrieNode {
		vector<TrieNode*> children;
		bool isEnd;
	public:
		TrieNode() : children(26), isEnd(false) {

		}

		TrieNode* WalkAdd(char c) {
			if (!children[c - 'a'])
				children[c - 'a'] = new TrieNode();
			return children[c - 'a'];
		}

		TrieNode* Walk(char c) {
			return children[c - 'a'];
		}

		bool IsEnd() const { return isEnd; }

		void SetIsEnd() {
			isEnd = true;
		}
	};

	class Trie {
		TrieNode root;
	public:
		Trie() {

		}

		void addWord(const string& w) {
			TrieNode* current = &root;
			for (auto c : w)
				current = current->WalkAdd(c);
			current->SetIsEnd();
		}

		TrieNode* GetRoot() { return &root; }
	};

	StreamChecker(vector<string>& words) {
		for (const auto& w : words)
			trie.addWord(w);
	}

	bool query(char letter) {
		bool result = false;
		pointers.emplace_back(trie.GetRoot());
		for (auto it = begin(pointers); it != end(pointers);) {
			if (*it = (*it)->Walk(letter)) {
				result = result || (*it)->IsEnd();
				++it;
			}
			else
				it = pointers.erase(it);
		}
		return result;
	}

private:
	Trie trie;
	list<TrieNode*> pointers;
};

/**
* Your StreamChecker object will be instantiated and called as such:
* StreamChecker* obj = new StreamChecker(words);
* bool param_1 = obj->query(letter);
*/

int main()
{
	StreamChecker streamChecker(vector<string>{"cd", "f", "kl"}); // init the dictionary.
	cout << boolalpha << streamChecker.query('a') << endl;          // return false
	cout << boolalpha << streamChecker.query('b') << endl;          // return false
	cout << boolalpha << streamChecker.query('c') << endl;          // return false
	cout << boolalpha << streamChecker.query('d') << endl;          // return true, because 'cd' is in the wordlist
	cout << boolalpha << streamChecker.query('e') << endl;          // return false
	cout << boolalpha << streamChecker.query('f') << endl;          // return true, because 'f' is in the wordlist
	cout << boolalpha << streamChecker.query('g') << endl;          // return false
	cout << boolalpha << streamChecker.query('h') << endl;          // return false
	cout << boolalpha << streamChecker.query('i') << endl;          // return false
	cout << boolalpha << streamChecker.query('j') << endl;          // return false
	cout << boolalpha << streamChecker.query('k') << endl;          // return false
	cout << boolalpha << streamChecker.query('l') << endl;          // return true, because 'kl' is in the wordlist

    return 0;
}

