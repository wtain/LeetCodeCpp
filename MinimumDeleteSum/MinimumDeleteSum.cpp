
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minimumDeleteSum(string s1, string s2) 
	{
		int l1 = s1.length(), l2 = s2.length();
		vector<vector<int>> M(l1+1, vector<int>(l2+1, 0));
		for (int i = 0; i < l1; ++i)
			M[i + 1][0] = M[i][0] + s1[i];
		for (int i = 0; i < l2; ++i)
			M[0][i + 1] = M[0][i] + s2[i];
		for (int i = 0; i < l1; ++i)
		{
			for (int j = 0; j < l2; ++j)
			{
				if (s1[i] == s2[j])
				{
					M[i + 1][j + 1] = M[i][j];
				}
				else
				{
					int v1 = M[i][j + 1] + s1[i];
					int v2 = M[i + 1][j] + s2[j];
					M[i + 1][j + 1] = min(v1, v2);
				}
			}
		}
		return M[l1][l2];
	}
};

int main()
{
	cout << Solution().minimumDeleteSum("sea", "eat") << endl; // 231
	cout << Solution().minimumDeleteSum("delete", "leet") << endl; // 403
	cout << Solution().minimumDeleteSum("d", "l") << endl;
	cout << Solution().minimumDeleteSum("de", "l") << endl;
	cout << Solution().minimumDeleteSum("del", "l") << endl;
	
    return 0;
}

