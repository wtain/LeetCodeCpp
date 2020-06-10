
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>

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

	bool checkInclusion(string s1, string s2) 
	{
		int n = s2.length(), m = s1.length();
		if (n < m)
			return false;
		Hist h;
		for (int i = 0; i < m; ++i)
		{
			h.Remove(s1[i]);
			h.Add(s2[i]);
		}
		if (h.IsZeroDistance())
			return true;
		for (int i1 = 0, i2 = m; i2 < n; ++i1, ++i2)
		{
			h.Remove(s2[i1]);
			h.Add(s2[i2]);
			if (h.IsZeroDistance())
				return true;
		}
		return false;
	}
};

int main()
{
	cout << boolalpha << Solution().checkInclusion("ab", "eidbaooo") << endl; // true
	cout << boolalpha << Solution().checkInclusion("ab", "eidboaoo") << endl; // false

    return 0;
}

