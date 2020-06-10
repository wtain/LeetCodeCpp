
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

	string longestCommonPrefix(vector<string>& strs) 
	{
		if (strs.empty())
			return "";
		vector<size_t> idx(0, strs.size());
		size_t N = strs[0].size();
		size_t max_len = 0;
		for (size_t i = 0; i < N; ++i)
		{
			for (size_t j = 1; j < strs.size(); ++j)
			{
				if (strs[j].size() == i)
					return strs[0].substr(0, max_len);
				if (strs[j][i] != strs[0][i])
					return strs[0].substr(0, max_len);
			}
			max_len = i + 1;
		}
		return strs[0].substr(0, max_len);
	}
};

int main()
{
    return 0;
}

