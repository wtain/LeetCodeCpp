
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the 
two words do not share common letters. You may assume that each word will contain only 
lower case letters. If no such two words exist, return 0.
*/

class Solution {
public:

	/*bool containSameLetters(const string& s1, const string& s2)
	{
		vector<bool> h(256, false);
		for (const auto c : s1)
			h[c] = true;

		for (const auto c : s2)
			if (h[c])
				return true;
		return false;
	}

	int maxProduct(vector<string>& words) 
	{
		int maxP = 0;
		int n = words.size();
		for (int i = 0; i < n-1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (containSameLetters(words[i], words[j]))
					continue;
				int p = words[i].length() * words[j].length();
				if (p > maxP)
					maxP = p;
			}
		}
		return maxP;
	}*/

	bool containSameLetters(const vector<bool>& sh1, const vector<bool>& sh2)
	{
		for (int i = 0; i < 256; ++i)
			if (sh1[i] && sh2[i])
				return true;
		return false;
	}

	int maxProduct(vector<string>& words)
	{
		int maxP = 0;
		int n = words.size();

		vector<vector<bool>> wordsH(n, vector<bool>(256, false));

		for (int i = 0; i < n; ++i)
		{
			for (const auto c : words[i])
				wordsH[i][c] = true;
		}

		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (containSameLetters(wordsH[i], wordsH[j]))
					continue;
				int p = words[i].length() * words[j].length();
				if (p > maxP)
					maxP = p;
			}
		}
		return maxP;
	}
};

int main()
{
	vector<string> v1 = { "abcw","baz","foo","bar","xtfn","abcdef" },
		           v2 = { "a","ab","abc","d","cd","bcd","abcd" },
				   v3 = { "a","aa","aaa","aaaa" };
	cout << Solution().maxProduct(v1) << endl; // 16
	cout << Solution().maxProduct(v2) << endl; // 4
	cout << Solution().maxProduct(v3) << endl; // 0

    return 0;
}

