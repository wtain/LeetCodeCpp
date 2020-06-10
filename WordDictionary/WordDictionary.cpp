
#include <string>
#include <iostream>
#include <iomanip>
#include <unordered_map>

using namespace std;

class WordDictionary {

	struct TrieNode
	{
		unordered_map<char, TrieNode*> children;
		bool isend;

		TrieNode()
		{
			isend = false;
		}

		void addWord(string word)
		{
			if (word.empty())
			{
				isend = true;
				return;
			}
			if (!children[word[0]])
				children[word[0]] = new TrieNode();
			children[word[0]]->addWord(word.substr(1));
		}

		bool search(string word) const
		{
			if (word.empty())
				return isend;
			if (word[0] == '.')
			{
				auto s1 = word.substr(1);
				for (const auto& c : children)
					if (c.second->search(s1))
						return true;
				return false;
			}
			auto it = children.find(word[0]);
			if (it == end(children))
				return false;
			return it->second->search(word.substr(1));
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

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/

int main()
{
	WordDictionary d;
	/*
	d.addWord("bad");
	d.addWord("dad");
	d.addWord("mad");
	cout << boolalpha << d.search("pad") << endl;// -> false
	cout << boolalpha << d.search("bad") << endl;// -> true
	cout << boolalpha << d.search(".ad") << endl;// -> true
	cout << boolalpha << d.search("b..") << endl;// -> true
	*/

	d.addWord("at");
	d.addWord("and");
	d.addWord("an");
	d.addWord("add");
	cout << boolalpha << d.search("a") << endl; // false
	cout << boolalpha << d.search(".at") << endl; // false
	d.addWord("bat");
	cout << boolalpha << d.search(".at") << endl; // true
	cout << boolalpha << d.search("an.") << endl; // true
	cout << boolalpha << d.search("a.d.") << endl; // false
	cout << boolalpha << d.search("b.") << endl; // false
	cout << boolalpha << d.search("a.d") << endl; // true
	cout << boolalpha << d.search(".") << endl; // false

    return 0;
}

