
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution 
{
public:
	bool isIsomorphic(string s, string t) 
	{
		int n = s.length();
		unordered_map<char, char> c;
		unordered_set<char> seen;
		for (int i = 0; i < n; ++i)
		{
			const char si = s[i];
			const char ti = t[i];
			auto sit = seen.find(ti);
			if (sit == seen.end())
			{
				auto cit = c.find(si);
				if (cit != c.end())
					return false;
				c.insert(make_pair(si, ti));
				seen.insert(sit, ti);
			}
			else
			{
				if (c[si] != ti)
					return false;
			}
		}
		return true;
	}
};


int main()
{
	vector<pair<string, string>> tests = 
	{ 
		{ "egg", "add" },  
		{ "foo", "bar" },
		{ "paper", "title" },
	};

	for (const auto& p : tests)
		cout << p.first << ", " << p.second << ": " << boolalpha << Solution().isIsomorphic(p.first, p.second) << endl;

    return 0;
}

