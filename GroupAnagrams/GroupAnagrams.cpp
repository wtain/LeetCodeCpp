
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution 
{
public:

	string weight(const string& s)
	{
		string rv = s;
		sort(begin(rv), end(rv));
		return rv;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		map<string, vector<string>> buckets;
		for (const auto& s : strs)
		{
			auto w = weight(s);
			buckets[w].push_back(s);
		}

		vector<vector<string>> rv;
		for (const auto& p : buckets)
			rv.push_back(p.second);
		return rv;
	}
};

int main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };

	auto buckets = Solution().groupAnagrams(strs);

	for (const auto& bucket : buckets)
	{
		copy(begin(bucket), end(bucket), ostream_iterator<string>(cout, " "));
		cout << endl;
	}

    return 0;
}

