
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	struct Compare
	{
		vector<int> h;

		Compare(const string& S)
			: h(256, -1)
		{
			for (int i = 0; i < S.length(); ++i)
				h[S[i]] = i;
		}

		bool operator() (const char c1, const char c2) const
		{
			if (h[c1] == -1)
				return true;
			if (h[c2] == -1)
				return false;
			if (h[c1] == -1 || h[c2] == -1)
				return false;
			return h[c1] < h[c2];
		}
	};

	string customSortString(string S, string T) 
	{
		Compare comp(S);
		stable_sort(begin(T), end(T), comp);
		return T;
	}
};


int main()
{
	//auto r = Solution().customSortString("cba", "abcd"); // "cbad"
	auto r = Solution().customSortString("exv", "xwvee"); // "eexvw"
	cout << r << endl;
    return 0;
}

