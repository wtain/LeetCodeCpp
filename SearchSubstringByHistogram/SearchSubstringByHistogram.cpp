
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Histogram
{
	unordered_map<char, int> m_hist;
	int m_dist;
public:
	Histogram()
		: m_dist(0)
	{

	}

	void Add(char c)
	{
		auto it = m_hist.find(c);
		if (it == end(m_hist))
		{
			m_hist.emplace_hint(it, make_pair(c, 1));
			++m_dist;
		}
		else
		{
			if (it->second >= 0)
				++m_dist;
			else
				--m_dist;
			++it->second;
			if (!it->second)
				m_hist.erase(it);
		}
	}

	void Remove(char c)
	{
		auto it = m_hist.find(c);
		if (it == end(m_hist))
		{
			m_hist.emplace_hint(it, make_pair(c, -1));
			++m_dist;
		}
		else
		{
			if (it->second >= 0)
				--m_dist;
			else
				++m_dist;
			--it->second;
			if (!it->second)
				m_hist.erase(it);
		}
	}

	void Add(const string& s)
	{
		for (int i = 0; i < s.length(); ++i)
			Add(s[i]);
	}

	void Remove(const string& s)
	{
		for (int i = 0; i < s.length(); ++i)
			Remove(s[i]);
	}

	bool IsZeroDistance() const
	{
		return !Distance();
	}

	int Distance() const
	{
		return m_dist;
	}
};

int SearchSubstringByHistogram(const string& s, const string& t)
{
	Histogram hist;
	hist.Remove(t);
	int n = s.length(), m = t.length();
	if (n < m)
		return -1;
	for (int i = 0; i < m; ++i)
		hist.Add(s[i]);
	if (hist.IsZeroDistance())
		return 0;
	for (int i1 = 0, i2 = m; i2 < n; ++i1, ++i2)
	{
		hist.Remove(s[i1]);
		hist.Add(s[i2]);
		if (hist.IsZeroDistance())
			return i1 + 1;
	}
	return -1;
}

int main()
{
	cout << SearchSubstringByHistogram("bbbcccaaayyyzzzbca", "abc") << endl;

    return 0;
}

