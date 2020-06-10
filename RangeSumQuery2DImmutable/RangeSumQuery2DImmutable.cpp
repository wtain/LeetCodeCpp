
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class NumMatrix {

public:
	vector<vector<int>> ps;
	size_t n, m;

	NumMatrix(vector<vector<int>> matrix) 
	{
		n = matrix.size();
		if (!n)
			return;
		m = matrix[0].size();
		ps.resize(n, vector<int>(m));
		ps[0][0] = matrix[0][0];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int v = matrix[i][j];
				int s00 = 0;
				int s01 = 0;
				int s10 = 0;
				if (i > 0 && j > 0)
					s00 = ps[i - 1][j - 1];
				if (i > 0)
					s01 = ps[i - 1][j];
				if (j > 0)
					s10 = ps[i][j - 1];
				ps[i][j] = s01 + s10 - s00 + v; // s00 + s01 - s00 + s10 - s00 + v
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) 
	{
		int s0 = 0, s1 = 0, s2 = 0, s3 = 0;
		s0 = ps[row2][col2];
		if (row1 > 0 && col1 > 0)
			s3 = ps[row1 - 1][col1 - 1];
		if (row1 > 0)
			s2 = ps[row1 - 1][col2];
		if (col1 > 0)
			s1 = ps[row2][col1 - 1];
		return s0 - s1 - s2 + s3;
	}
};

void printMatrix(const vector<vector<int>>& matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		copy(begin(matrix[i]), end(matrix[i]), ostream_iterator<int>(cout, ", "));
		cout << endl;
	}
	cout << endl;
}

int main()
{
	NumMatrix matrix(
	{ { 3,0,1,4,2 },
	  { 5,6,3,2,1 },
	  { 1,2,0,1,5 },
	  { 4,1,0,1,7 },
	  { 1,0,3,0,5 } 
	});

	printMatrix(matrix.ps);

	cout << matrix.sumRegion(2, 1, 4, 3) << endl; // 8
	cout << matrix.sumRegion(1, 1, 2, 2) << endl; // 11
	cout << matrix.sumRegion(1, 2, 2, 4) << endl; // 12

    return 0;
}

