
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/image-smoother/

Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
[1,0,1],
[1,1,1]]
Output:
[[0, 0, 0],
[0, 0, 0],
[0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].

*/

class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		if (M.empty())
			return{};
		int n = M.size();
		int m = M[0].size();
		vector<vector<int>> result(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int sum = 0;
				int cnt = 0;
				for (int a = -1; a <= 1; ++a) {
					int i1 = i + a;
					if (i1 < 0 || i1 >= n)
						continue;
					for (int b = -1; b <= 1; ++b) {
						int j1 = j + b;
						if (j1 < 0 || j1 >= m)
							continue;
						sum += M[i1][j1];
						++cnt;
					}
				}
				result[i][j] = sum / cnt;
			}
		}
		return result;
	}
};

int main()
{
	{
		vector<vector<int>> image 
		{
			{ 1, 1, 1 },
			{ 1, 0, 1 },
			{ 1, 1, 1 }
		};

		auto r = Solution().imageSmoother(image);
		for (const auto& row : r)
		{
			copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}
    return 0;
}

