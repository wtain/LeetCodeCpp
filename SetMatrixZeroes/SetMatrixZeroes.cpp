
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) 
	{
		bool row0Z = false;
		bool col0Z = false;
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			if (!matrix[0][j])
			{
				row0Z = true;
				break;
			}
		}
		for (int i = 0; i < matrix.size(); ++i)
		{
			if (!matrix[i][0])
			{
				col0Z = true;
				break;
			}
		}
		for (int i = 1; i < matrix.size(); ++i)
		{
			for (int j = 1; j < matrix[i].size(); ++j)
			{
				if (!matrix[i][j])
				{
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		for (int i = 1; i < matrix.size(); ++i)
		{
			for (int j = 1; j < matrix[i].size(); ++j)
			{ 
				if (!matrix[0][j] || !matrix[i][0])
					matrix[i][j] = 0;
			}
		}
		if (row0Z)
			for (int j = 0; j < matrix[0].size(); ++j)
				matrix[0][j] = 0;
		if (col0Z)
			for (int i = 0; i < matrix.size(); ++i)
				matrix[i][0] = 0;
	}
};

ostream& operator << (ostream& stream, const vector<vector<int>>& m)
{
	for (const auto& r : m)
	{
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return stream;
}

int main()
{
	vector<vector<int>> test1 = 
	{
		{ 1, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 1, 1 }
	};

	vector<vector<int>> test2 =
	{
		{ 0, 1, 2, 0 },
		{ 3, 4, 5, 2 },
		{ 1, 3, 1, 5 }
	};

	Solution().setZeroes(test1);
	Solution().setZeroes(test2);

	cout << test1 << endl;
	cout << test2 << endl;

    return 0;
}

