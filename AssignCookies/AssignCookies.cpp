
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) 
	{
		sort(begin(g), end(g));
		sort(begin(s), end(s));
		int c = 0;
		int i = 0, j = 0, n = g.size(), m = s.size();
		while (i < n && j < m)
		{
			if (s[j] >= g[i])
			{
				++c;
				++j;
				++i;
			}
			else
				++j;
		}

		return c;
	}
};

int main()
{
	vector<int> g1 = { 1, 2, 3 }, s1 = { 1, 1 };
	cout << Solution().findContentChildren(g1, s1) << endl; // 1
	vector<int> g2 = { 1, 2 }, s2 = { 1, 2, 3 };
	cout << Solution().findContentChildren(g2, s2) << endl; // 2

    return 0;
}

