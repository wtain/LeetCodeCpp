
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		vector<string> v(numRows);
		int j = 0, dj = 1;
		for (size_t i = 0; i < s.size(); ++i)
		{
			v[j] += s[i];
			if (j + dj == numRows)
				dj = -1;
			if (j + dj == -1)
				dj = 1;
			if (numRows > 1)
				j += dj;
		}
		string rv;
		for (size_t j = 0; j < numRows; ++j)
			rv += v[j];
		return rv;
	}
};

int main()
{
	cout << Solution().convert("AB", 1) << endl;

    return 0;
}

