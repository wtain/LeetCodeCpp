
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

class Solution {
public:

	bool isValidComponent(const string& s)
	{
		if (s.empty())
			return false;
		if (s[0] == '0' && s.length() > 1)
			return false;
		istringstream stream(s);
		int v;
		stream >> v;
		return v >= 0 && v <= 255;
	}

	void restoreImpl(vector<string>& results, const string& s, int dots, const string& prefix)
	{
		if (!dots)
		{
			if (isValidComponent(s))
				results.push_back(prefix + s);
			return;
		}
		for (int i = 1; i <= s.length(); ++i)
		{
			auto s1 = s.substr(0, i);
			if (!isValidComponent(s1))
				break;
			restoreImpl(results, s.substr(i), dots - 1, prefix + s1 + ".");
		}
	}

	vector<string> restoreIpAddresses(string s) 
	{
		vector<string> results;
		restoreImpl(results, s, 3, "");
		return results;
	}
};

int main()
{
	//auto addrs = Solution().restoreIpAddresses("25525511135");
	auto addrs = Solution().restoreIpAddresses("010010");

	copy(begin(addrs), end(addrs), ostream_iterator<string>(cout, "\n"));
	cout << endl;

    return 0;
}

