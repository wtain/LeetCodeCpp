
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	struct Compare
	{
		bool operator() (const pair<int, int>& l, const pair<int, int>& r) const
		{
			return l.second < r.second;
		}
	};

	string frequencySort(string s) 
	{
		vector<pair<char, int>> h(256, make_pair(0, 0));
		for (int i = 0; i < 256; ++i)
			h[i].first = i;
		for (int i = 0; i < s.length(); ++i)
			++h[s[i]].second;
		
		make_heap(begin(h), end(h), Compare());

		string result;

		while (result.length() < s.length())
		{
			pop_heap(begin(h), end(h), Compare());
			const auto p = h.back(); h.pop_back();
			if (!p.second)
				continue;
			for (int i = 0; i < p.second; ++i)
				result += p.first;
		}
		return result;
	}
};

int main()
{
	cout << Solution().frequencySort("tree") << endl;
	cout << Solution().frequencySort("cccaaa") << endl;
	cout << Solution().frequencySort("Aabb") << endl;

    return 0;
}

