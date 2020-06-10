
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) 
//	{
//		unordered_set<char> chars;
//		if (s.empty())
//			return 0;
//		int maxlen = 1;
//		const int n = s.length();
//		int i1 = 0, i2 = 1;
//		chars.insert(s[0]);
//		while (i2 < n)
//		{
//			auto it = chars.find(s[i2]);
//			while (it != end(chars))
//			{
//				chars.erase(s[i1++]);
//				it = chars.find(s[i2]);
//			}
//			int len = i2 - i1 + 1;
//			chars.emplace_hint(it, s[i2]);
//			maxlen = max(maxlen, len);
//			++i2;
//		}
//		return maxlen;
//	}
//};

/*
// Faster?
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
		vector<int> p(s.size(), 0);
		p[0] = 1;
		for (size_t i = 1; i < s.size(); ++i)
		{
			int k = p[i - 1];
			int off = i - k;
			string st = s.substr(off, k);
			int pos = off + st.rfind(s[i]);
			if (string::npos != pos)
				p[i] = i - pos;
			else
				p[i] = p[i - 1] + 1;
		}
		return *max_element(begin(p), end(p));
	}
};
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		unordered_map<char, int> chars;
		const int n = s.length();
		int result = 0;
		for (int i = 0, j = 0; j < n; ++j)
		{
			auto it = chars.find(s[j]);
			if (it != end(chars))
				i = max(i, it->second);
			result = max(j - i + 1, result);
			chars[s[j]] = j+1;
		}
		return result;
	}
};

int main()
{
	cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl; // 3
	cout << Solution().lengthOfLongestSubstring("bbbbb") << endl; // 1
	cout << Solution().lengthOfLongestSubstring("pwwkew") << endl; // 3
	cout << Solution().lengthOfLongestSubstring("") << endl; // 0
	cout << Solution().lengthOfLongestSubstring("a") << endl; // 1

    return 0;
}

