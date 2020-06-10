
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

	int commonSubsequence(const string& word1, const string& word2)
	{
		vector<vector<int>> v(2, vector<int>(word2.length()+1));
		int longest = 0;
		for (int i = 0; i < word1.length()+1; ++i)
		{
			int i1 = i % 2;
			for (int j = 0; j < word2.length()+1; ++j)
			{
				if (i == 0 || j == 0)
					v[i1][j] = 0;
				else if (word1[i - 1] == word2[j - 1])
					v[i1][j] = v[1 - i1][j - 1] + 1;
				else
					v[i1][j] = max(v[1 - i1][j], v[i1][j - 1]);
				longest = max(longest, v[i1][j]);
			}
		}
		return longest;
	}

	int minDistance(string word1, string word2) 
	{
		int n = commonSubsequence(word1, word2);

		return word1.length() - n + word2.length() - n;
	}
};

int main()
{
	cout << Solution().minDistance("sea", "eat") << endl; // 1
    return 0;
}

