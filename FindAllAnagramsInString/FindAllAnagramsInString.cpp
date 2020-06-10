
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:

	class Hist
	{
		vector<int> m_hist;
		int m_dist;
	public:
		Hist()
			: m_hist(256, 0)
			, m_dist(0)
		{

		}

		void Add(char c)
		{
			m_dist -= abs(m_hist[c]);
			++m_hist[c];
			m_dist += abs(m_hist[c]);
		}

		void Remove(char c)
		{
			m_dist -= abs(m_hist[c]);
			--m_hist[c];
			m_dist += abs(m_hist[c]);
		}

		bool IsZeroDistance() const
		{
			return 0 == m_dist;
		}
	};

	vector<int> findAnagrams(string s, string p)
	{
		vector<int> result;
		int n = s.length(), m = p.length();
		if (n < m)
			return{};
		Hist h;
		for (int i = 0; i < m; ++i)
		{
			h.Remove(p[i]);
			h.Add(s[i]);
		}
		if (h.IsZeroDistance())
			result.push_back(0);
		for (int i1 = 0, i2 = m; i2 < n; ++i1, ++i2)
		{
			h.Remove(s[i1]);
			h.Add(s[i2]);
			if (h.IsZeroDistance())
				result.push_back(i1 + 1);
		}
		return result;
	}
};

int main()
{
	auto r1 = Solution().findAnagrams("cbaebabacd", "abc");
	copy(begin(r1), end(r1), ostream_iterator<int>(cout, " "));
	cout << endl;

	auto r2 = Solution().findAnagrams("abab", "ab");
	copy(begin(r2), end(r2), ostream_iterator<int>(cout, " "));
	cout << endl;

    return 0;
}

