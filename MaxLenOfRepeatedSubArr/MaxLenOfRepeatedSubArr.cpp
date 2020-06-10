
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) 
	{
		vector<vector<int>> v(2, vector<int>(B.size()+1));
		int m = 0;
		for (int i = 0; i < A.size()+1; ++i)
		{
			int i1 = i % 2;
			int i2 = 1 - i1;
			for (int j = 0; j < B.size()+1; ++j)
			{
				if (i == 0 || j == 0)
					v[i1][j] = 0;
				else if (A[i - 1] == B[j - 1])
					v[i1][j] = v[i2][j - 1] + 1;
				else
					v[i1][j] = 0;
				m = max(v[i1][j], m);
			}
		}
		return m;
	}
};

int main()
{
	vector<int> a1 = { 1,2,3,2,1 };
	vector<int> a2 = { 3,2,1,4,7 };
	cout << Solution().findLength(a1, a2) << endl; // 3

    return 0;
}

