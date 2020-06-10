
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

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

int main()
{
	cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl;

    return 0;
}

