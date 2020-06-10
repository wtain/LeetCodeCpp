
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:

	class CharSet
	{
		unordered_map<char, size_t> counts;
		unordered_set<char> chars;
	public:
		explicit CharSet(const string& s)
		{
			for (auto c : s)
				chars.insert(c);
		}

		void AddChar(const char c)
		{
			if (chars.find(c) == chars.end())
				return;
			auto it = counts.find(c);
			if (it == counts.end())
				counts.insert(it, make_pair(c, 1));
			else
				it->second++;
		}

		void RemoveChar(const char c)
		{
			if (chars.find(c) == chars.end())
				return;
			auto it = counts.find(c);
			it->second--;
			if (!it->second)
				counts.erase(it);
		}

		size_t Size() const
		{
			return counts.size();
		}

		bool Matches(const CharSet& target) const
		{
			for (const auto& p : target.counts)
			{
				auto i = counts.find(p.first);
				if (i == counts.end())
					return false;
				if (i->second < p.second)
					return false;
			}
			return true;
		}
	};

	string minWindow(string s, string t) {
		if (s.empty())
			return "";
		if (t.empty())
			return "";
		if (s.length() < t.length())
			return "";
		size_t b = 0, e = t.length() - 1;
		CharSet counts(t), target(t);

		for (size_t i = b; i <= e; ++i)
			counts.AddChar(s[i]);

		for (auto c : t)
			target.AddChar(c);

		size_t minLength = numeric_limits<size_t>::max();
		string rv;

		while (e < s.length())
		{
			while (counts.Matches(target) && b <= e)
			{
				size_t len = e - b + 1;
				if (len < minLength)
				{
					rv = s.substr(b, len);
					minLength = rv.length();
				}
				counts.RemoveChar(s[b++]);
			}
			if (e == s.length() - 1)
				break;
			counts.AddChar(s[++e]);
			if (counts.Matches(target))
			{
				size_t len = e - b + 1;
				if (len < minLength)
				{
					rv = s.substr(b, len);
					minLength = rv.length();
				}
			}
		}

		return rv;
	}
};


int main()
{
	cout << Solution().minWindow("ab", "b") << endl;

    return 0;
}

