
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Binary search
//class Solution {
//public:
//
//	bool searchMatrixImpl(vector<vector<int>>& matrix, int target, int i1, int i2, int j1, int j2)
//	{
//		if (i1 > i2 || j1 > j2)
//			return false;
//
//		int im = (i1 + i2) / 2;
//		int jm = (j1 + j2) / 2;
//
//		int mm = matrix[im][jm];
//
//		if (mm == target)
//			return true;
//		if (mm < target)
//			return searchMatrixImpl(matrix, target, i1, im, jm + 1, j2) ||
//			       searchMatrixImpl(matrix, target, im+1, i2, j1, j2);
//		return searchMatrixImpl(matrix, target, i1, im-1, j1, j2) ||
//			searchMatrixImpl(matrix, target, im, i2, j1, jm-1);
//	}
//
//	bool searchMatrix(vector<vector<int>>& matrix, int target) 
//	{
//		int N = matrix.size();
//		if (!N)
//			return false;
//		int M = matrix[0].size();
//
//		return searchMatrixImpl(matrix, target, 0, N - 1, 0, M - 1);
//	}
//};

// top-right
class Solution {
public:

	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int N = matrix.size();
		if (!N)
			return false;
		int M = matrix[0].size();

		int row = 0, col = M - 1;
		while (row < N && col >= 0)
		{
			if (matrix[row][col] == target)
				return true;
			if (matrix[row][col] > target)
				--col;
			else
				++row;
		}
		return false;
	}
};

// Binary-linear search
//class Solution {
//public:
//
//	class MatrixView
//	{
//	public:
//
//		virtual int operator() (int i, int j) const = 0;
//
//		virtual int Width() const = 0;
//		virtual int Height() const = 0;
//
//		//virtual const MatrixView& Transpose() const = 0;
//		virtual const MatrixView* Transpose() const = 0;
//	};
//
//	class TransposedView : public MatrixView
//	{
//		//const MatrixView& m_base;
//		const MatrixView* m_base;
//	public:
//
//		//explicit TransposedView(const MatrixView& base)
//		explicit TransposedView(const MatrixView* base)
//			: m_base(base)
//		{
//
//		}
//
//		int operator() (int i, int j) const override
//		{
//			//return m_base(j, i);
//			return (*m_base)(j, i);
//		}
//
//		//const MatrixView& Transpose() const override
//		const MatrixView* Transpose() const override
//		{
//			return m_base;
//		}
//
//		int Width() const override
//		{
//			//return m_base.Height();
//			return m_base->Height();
//		}
//
//		int Height() const override
//		{
//			//return m_base.Width();
//			return m_base->Width();
//		}
//	};
//
//	class Matrix : public MatrixView
//	{
//		const vector<vector<int>>& m_matrix;
//		int m_width, m_height;
//		//const MatrixView& m_transposed;
//		const MatrixView* m_transposed;
//	public:
//
//		explicit Matrix(const vector<vector<int>>& matrix)
//			: m_matrix(matrix)
//			, m_height(matrix.size())
//			, m_width(!matrix.empty() ? matrix[0].size() : 0)
//			//, m_transposed(TransposedView(*this))
//			, m_transposed(new TransposedView(this))
//		{
//
//		}
//
//		int operator() (int i, int j) const override
//		{
//			return m_matrix[i][j];
//		}
//
//		//const MatrixView& Transpose() const override
//		const MatrixView* Transpose() const override
//		{
//			return m_transposed;
//		}
//
//		int Width() const override { return m_width; }
//		int Height() const override { return m_height; }
//	};
//
//	//bool searchMatrixImpl(const MatrixView& matrix, int target)
//	bool searchMatrixImpl(const MatrixView* pmatrix, int target)
//	{
//		const MatrixView& matrix = *pmatrix;
//		if (matrix.Width() > matrix.Height())
//			//return searchMatrixImpl(matrix.Transpose(), target);
//			return searchMatrixImpl(pmatrix->Transpose(), target);
//
//		int minCol = 0;
//		int maxRow = matrix.Height() - 1;
//		int t = matrix.Height() / matrix.Width();
//		while (minCol < matrix.Width() && maxRow >= 0)
//		{
//			int luckyRow = max(maxRow - t, 0);
//			int value = matrix(luckyRow, minCol);
//			if (value == target)
//				return true;
//			if (value > target)
//			{
//				maxRow = luckyRow - 1;
//				continue;
//			}
//
//			int minRowInCol = luckyRow + 1;
//			int maxRowInCol = maxRow;
//			while (minRowInCol <= maxRowInCol)
//			{
//				int mid = minRowInCol + (maxRowInCol - minRowInCol+1) / 2;
//				int value = matrix(mid, minCol);
//				if (target == value)
//					return true;
//				if (target < value)
//					maxRow = maxRowInCol = mid - 1;
//				else
//					minRowInCol = mid + 1;
//			}
//			++minCol;
//		}
//		return false;
//	}
//
//	bool searchMatrix(vector<vector<int>>& matrix, int target)
//	{
//		if (matrix.empty() || matrix[0].empty())
//			return false;
//		//return searchMatrixImpl(Matrix(matrix), target);
//		return searchMatrixImpl(new Matrix(matrix), target);
//	}
//};

// Balanced binary search - will not work
//class Solution {
//public:
//
//	bool searchMatrixImpl(const vector<vector<int>>& matrix, int i1, int i2, int j1, int j2, int target)
//	{
//		cout << i1 << " " << i2 << " " << j1 << " " << j2 << endl;
//		const int N = i2 - i1;
//		const int M = j2 - j1;
//
//		if (i1 >= i2 || j1 >= j2)
//			return false;
//
//		if (1 == N)
//		{
//			while (j1 < j2)
//			{
//				int jm = j1 + (j2 - j1) / 2;
//				if (matrix[i1][jm] == target)
//					return true;
//				if (matrix[i1][jm] > target)
//					j1 = jm + 1;
//				else
//					j2 = jm;
//			}
//			return false;
//		}
//
//		if (1 == M)
//		{
//			while (i1 < i2)
//			{
//				int im = i1 + (i2 - i1) / 2;
//				if (matrix[im][j1] == target)
//					return true;
//				if (matrix[im][j1] > target)
//					i1 = im + 1;
//				else
//					i2 = im;
//			}
//			return false;
//		}
//
//		if (N > M)
//		{
//			int im = i1 + (i2 - i1) / 2;
//			if (matrix[im][j2 - 1] == target)
//				return true;
//			else if (matrix[im][j2 - 1] > target)
//				return searchMatrixImpl(matrix, i1, im + 1, j1, j2, target);
//			else
//				return searchMatrixImpl(matrix, im, i2, j1, j2, target);
//		}
//		else
//		{
//			int jm = j1 + (j2 - j1) / 2;
//			if (matrix[i2 - 1][jm] == target)
//				return true;
//			else if (matrix[i2 - 1][jm] < target)
//				return searchMatrixImpl(matrix, i1, i2, jm + 1, j2, target);
//			else
//				return searchMatrixImpl(matrix, i1, i2, j1, jm, target);
//		}
//	}
//
//	bool searchMatrix(vector<vector<int>>& matrix, int target)
//	{
//		const int N = matrix.size();
//		if (!N)
//			return false;
//		const int M = matrix[0].size();
//
//		return searchMatrixImpl(matrix, 0, N, 0, M, target);
//	}
//};

int main()
{
	vector<vector<int>> M = 
	{
		{ 1,   4,  7, 11, 15 },
		{ 2,   5,  8, 12, 19 },
		{ 3,   6,  9, 16, 22 },
		{ 10, 13, 14, 17, 24 },
		{ 18, 21, 23, 26, 30 }
	}, Me, M2 = { {1,3,5} }, M3 = { {-5} }, M4 = { {-1, 3} }, 
	M5 = 
	{ 
		{1,4},
		{2,5}
	},
	M6 = 
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25}
	};

	cout << boolalpha << Solution().searchMatrix(M, 5) << endl; // true
	cout << boolalpha << Solution().searchMatrix(M, 20) << endl; // false

	cout << boolalpha << Solution().searchMatrix(Me, 5) << endl; // false

	cout << boolalpha << Solution().searchMatrix(M2, 1) << endl; // true
	
	cout << boolalpha << Solution().searchMatrix(M3, -10) << endl; // false
	
	cout << boolalpha << Solution().searchMatrix(M4, 1) << endl; // false

	cout << boolalpha << Solution().searchMatrix(M5, 0) << endl; // false

	cout << boolalpha << Solution().searchMatrix(M5, 2) << endl; // true
	cout << boolalpha << Solution().searchMatrix(M6, 19) << endl; // true

    return 0;
}

