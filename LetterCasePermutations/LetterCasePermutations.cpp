
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:

	vector<string> letterCasePermutation(string S) 
	{
		vector<string> res;
		res.push_back(S);
		for (int i = 0; i < S.length(); ++i)
		{
			if (isalpha(S[i]))
			{
				int m = res.size();
				res.reserve(2 * m);
				for (int j = 0; j < m; ++j)
				{
					auto s1 = res[j];
					if (isupper(s1[i]))
						s1[i] = tolower(s1[i]);
					else
						s1[i] = toupper(s1[i]);
					res.push_back(s1);
				}
			}
		}
		return res;
	}
};

void runTest(string s)
{
	auto r = Solution().letterCasePermutation(s);
	copy(begin(r), end(r), ostream_iterator<string>(cout, " "));
	cout << endl << endl;
}

int main()
{
	runTest("a1b2");
	runTest("3z4");
	runTest("12345");

    return 0;
}

