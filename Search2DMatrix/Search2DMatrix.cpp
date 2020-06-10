
#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//
//	pair<int, int> translate(int i, int M)
//	{
//		return{ i / M, i % M };
//	}
//
//	bool searchMatrix(vector<vector<int>>& matrix, int target) 
//	{
//		int N = matrix.size();
//		if (!N)
//			return false;
//		int M = matrix[0].size();
//		if (!M)
//			return false;
//
//		int l = 0, r = M*N;
//		while (l < r)
//		{
//			int m = (l + r) >> 1;
//			auto p = translate(m, M);
//			int v = matrix[p.first][p.second];
//			if (v == target)
//				return true;
//			else if (v < target)
//				l = m + 1;
//			else
//				r = m;
//		}
//		return false;
//	}
//};

class Solution {
public:

	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int N = matrix.size();
		if (!N)
			return false;
		int M = matrix[0].size();
		if (!M)
			return false;

		int l = 0, r = N;
		while (l < r)
		{
			int m = (l + r) >> 1;
			int v = matrix[m][M-1];
			if (v == target)
				return true;
			else if (v < target)
				l = m + 1;
			else
				r = m;
		}
		if (l >= N)
			return false;
		int row = l;
		l = 0, r = M;
		while (l < r)
		{
			int m = (l + r) >> 1;
			int v = matrix[row][m];
			if (v == target)
				return true;
			else if (v < target)
				l = m + 1;
			else
				r = m;
		}
		return false;
	}
};

int main()
{
	vector<vector<int>> m1 =
	{
		{ 1,   3,  5,  7 },
		{ 10, 11, 16, 20 },
		{ 23, 30, 34, 50}
	};

	vector<vector<int>> m2 = { {1} };

	cout << boolalpha << Solution().searchMatrix(m1, 3) << endl; // true
	cout << boolalpha << Solution().searchMatrix(m1, 13) << endl; // false
	cout << boolalpha << Solution().searchMatrix(m2, 1) << endl; // true
	cout << boolalpha << Solution().searchMatrix(m2, 0) << endl; // false
	cout << boolalpha << Solution().searchMatrix(m2, 2) << endl; // false

    return 0;
}

