
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

/*
const int n = s.length(), n2 = n >> 1;
for (int l = n2; l >= 0; --l)
{
if ((n % l))
continue;
int i = 0, char c = s[0];
bool f = true;
for (i = i + l; i < n; ++i)
if (c != s[i])
{
f = false;
break;
}
if (!f)
continue;
}*/

class Solution {
public:

	vector<int> calculatePrefixFunction(const string& s)
	{
		const int n = s.length();
		vector<int> p(n);
		int k = 0;
		for (int i = 1; i < n; ++i)
		{
			while (k > 0 && s[k] != s[i])
				k = p[k - 1];
			if (s[k] == s[i])
				++k;
			p[i] = k;
		}
		return p;
	}

	bool repeatedSubstringPattern(string s) 
	{
		if (s.empty())
			return false;
		const auto p = calculatePrefixFunction(s);
		const int n = s.length();
		int len = n - p[n - 1];
		if (n == len || n % len > 0)
			return false;
		string t = s.substr(0, len);
		for (int i = 0; i + len < n; i += len)
		{
			string si = s.substr(i, len);
			if (si != t)
				return false;
		}
		return true;
	}
};

int main()
{
	cout << boolalpha << Solution().repeatedSubstringPattern("abab") << endl; // true
	cout << boolalpha << Solution().repeatedSubstringPattern("aba") << endl; // false
	cout << boolalpha << Solution().repeatedSubstringPattern("abcabcabcabc") << endl; // true
	cout << boolalpha << Solution().repeatedSubstringPattern("aaaaaaa") << endl; // true
	cout << boolalpha << Solution().repeatedSubstringPattern("") << endl; // false
	cout << boolalpha << Solution().repeatedSubstringPattern("a") << endl; // false
	cout << boolalpha << Solution().repeatedSubstringPattern("ababc") << endl; // false
	cout << boolalpha << Solution().repeatedSubstringPattern("abcab") << endl; // false
	cout << boolalpha << Solution().repeatedSubstringPattern("abcabcabcab") << endl; // false
	cout << boolalpha << Solution().repeatedSubstringPattern("abcababcabc") << endl; // false

    return 0;
}

