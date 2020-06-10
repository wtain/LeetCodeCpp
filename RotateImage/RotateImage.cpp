
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
	/*

	(0 0) (0 1) (0 2) ... (0 N)
	(1 0) (1 1) (1 2) ... (1 N)
	(2 0) (2 1) (2 2) ... (2 N)
	...   ...   ...  ...  ...
	(N 0) (N 1) (N 2) ... (N N)

	*/
	void rotate(vector<vector<int>>& matrix)
	{
		const int N = matrix.size();
		if (N < 1)
			return;
		if (matrix[0].size() != N)
			return;
		const int N2 = N / 2;
		const int N22 = (N + 1) / 2;
		const int N1 = N - 1;
		for (int i = 0; i < N22; ++i)
		{
			for (int j = 0; j < N2; ++j)
			{
				// i j -> j n1-i -> n1-i n1-j -> n1-j i -> i j
				int tmp = matrix[i][j];
				swap(matrix[j][N1 - i], tmp);
				swap(matrix[N1 - i][N1 - j], tmp);
				swap(matrix[N1 - j][i], tmp);
				matrix[i][j] = tmp;
			}
		}
	}
};

void PrintMatrix(const vector<vector<int>>& matrix)
{
	for (auto i = 0; i < matrix.size(); ++i)
	{
		const auto& row = matrix[i];
		copy(begin(row), end(row), ostream_iterator<int>(cout, ","));
		cout << endl;
	}
	cout << endl;
}

void RunTest(vector<vector<int>>& matrix)
{
	PrintMatrix(matrix);
	Solution().rotate(matrix);
	PrintMatrix(matrix);
}

int main()
{
	vector<vector<int>> matrix1 = 
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	vector<vector<int>> matrix2 =
	{
		{  1, 2, 3, 4 },
		{  5, 6, 7, 8 },
		{  9,10,11,12 },
		{ 13,14,15,16 },
	};
	RunTest(matrix1);
	RunTest(matrix2);
    return 0;
}

