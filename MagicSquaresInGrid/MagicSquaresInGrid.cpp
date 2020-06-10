
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numMagicSquaresInside(vector<vector<int>>& grid) 
	{
		int n = grid.size();
		int m = grid[0].size();
		int cnt = 0;
		for (int i = 0; i < n-2; ++i)
		{
			for (int j = 0; j < m-2; ++j)
			{
				int d1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
				int d2 = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];

				if (d1 != d2)
					continue;

				bool f = true;

				vector<int> rs(3), cs(3);
				for (int i1 = 0; i1 < 3; ++i1)
				{
					for (int j1 = 0; j1 < 3; ++j1)
					{
						int v = grid[i + i1][j + j1];
						if (v < 1 || v > 9)
						{
							f = false;
							break;
						}
						rs[i1] += v;
						cs[j1] += v;
					}
				}
				
				if (!f)
					continue;

				for (int k = 0; k < 3; ++k)
				{
					if (cs[k] != d1 || rs[k] != d1)
					{
						f = false;
						break;
					}
				}
				if (f)
					++cnt;
			}
		}
		return cnt;
	}
};

int main()
{
	vector<vector<int>> v =
	{
		{4,3,8,4},
		{9,5,1,9},
		{2,7,6,2}
	};

	cout << Solution().numMagicSquaresInside(v) << endl; // 1

	vector<vector<int>> v1 =
	{
		{10,3,5},
		{1,6,11},
		{7,9,2}
	};

	cout << Solution().numMagicSquaresInside(v1) << endl; // 0

    return 0;
}

