
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
https://leetcode.com/problems/repeated-dna-sequences/

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]

*/

class Solution {
public:

	/*
	vector<int> calcPrefixF(const string& s)
	{
		int n = s.length();
		vector<int> p(n);
		p[0] = 0;
		for (int i = 1; i < n; ++i)
		{
			int k = p[i - 1];
			while (1)
			{
				if (s[k] == s[i])
				{
					p[i] = k + 1;
					break;
				}
				else if (0 == k)
				{
					p[i] = 0;
					break;
				}
				else
				{
					k = p[k - 1];
				}
			}
		}
		return p;
	}
	*/

	vector<string> findRepeatedDnaSequences(string s) 
	{
		//auto p = calcPrefixF(s);

		//hash<string>().operator()()

		int n = s.length();
		const int m = 10;

		unordered_map<size_t, int> hashes;
		string t = s.substr(0, m);

		vector<string> result;
		unordered_set<string> seen;

		size_t h0 = hash<string>().operator()(t);
		hashes.emplace(h0, 0);
		for (int i1 = 1, i2 = m; i2 < n; ++i1, ++i2)
		{
			t = t.substr(1);
			t += s[i2];
			size_t h = hash<string>().operator()(t);
			
			auto it = hashes.find(h);
			if (it == end(hashes))
				hashes.emplace_hint(it, h, i1);
			else
			{
				bool f = true;
				for (int i = 0; i < m; ++i)
				{
					if (s[i1 + i] != s[it->second + i])
					{
						f = false;
						break;
					}
				}
				if (f)
				{
					auto tt = seen.find(t);
					if (tt == end(seen))
					{
						seen.emplace_hint(tt, t);
						result.push_back(t);
					}
				}
			}
		}

		return result;
	}
};

int main()
{
	//auto r = Solution().findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"); // "AAAAACCCCC", "CCCCCAAAAA"
	auto r = Solution().findRepeatedDnaSequences("AAAAAAAAAAAA"); // "AAAAAAAAAA"
	copy(begin(r), end(r), ostream_iterator<string>(cout, " "));
	cout << endl;
    return 0;
}

