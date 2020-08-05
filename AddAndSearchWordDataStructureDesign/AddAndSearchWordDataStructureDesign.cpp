
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3413/
https://leetcode.com/problems/add-and-search-word-data-structure-design/
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

//Runtime: 296 ms, faster than 23.05% of C++ online submissions for Add and Search Word - Data structure design.
//Memory Usage : 36.6 MB, less than 90.06% of C++ online submissions for Add and Search Word - Data structure design.
class WordDictionary {

	struct TrieNode
	{
		unordered_map<char, TrieNode*> children;
		bool isend;

		TrieNode()
		{
			isend = false;
		}

		void addWord(const string& word) {
			addWordImpl(word, 0, word.length());
		}

		void addWordImpl(const string& word, const size_t i0, const size_t n)
		{
			if (i0 == n)
			{
				isend = true;
				return;
			}
			if (!children[word[i0]])
				children[word[i0]] = new TrieNode();
			children[word[i0]]->addWordImpl(word, i0+1, n);
		}

		bool search(const string& word) const {
			return searchImpl(word, 0, word.length());
		}

		bool searchImpl(const string& word, const size_t i0, const size_t n) const
		{
			if (i0 == n)
				return isend;
			if (word[i0] == '.')
			{
				for (const auto& c : children)
					if (c.second->searchImpl(word, i0+1, n))
						return true;
				return false;
			}
			auto it = children.find(word[i0]);
			if (it == end(children))
				return false;
			return it->second->searchImpl(word, i0+1, n);
		}
	};

	TrieNode root;
	bool hasEmpty;


public:
	/** Initialize your data structure here. */
	WordDictionary()
	{
		hasEmpty = false;
	}

	/** Adds a word into the data structure. */
	void addWord(string word)
	{
		if (word.empty())
			hasEmpty = true;
		else
			root.addWord(word);
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word)
	{
		if (word.empty())
			return hasEmpty;
		return root.search(word);
	}
};

int main()
{
	WordDictionary dic;

	dic.addWord("bad");
	dic.addWord("dad");
	dic.addWord("mad");
	cout << boolalpha << dic.search("pad") << endl; // -> false
	cout << boolalpha << dic.search("bad") << endl; // -> true
	cout << boolalpha << dic.search(".ad") << endl; // -> true
	cout << boolalpha << dic.search("b..") << endl; // -> true

    return 0;
}

