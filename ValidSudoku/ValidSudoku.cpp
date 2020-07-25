
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/valid-sudoku/

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
["8","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being
modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.

*/

//Runtime: 60 ms, faster than 20.72% of C++ online submissions for Valid Sudoku.
//Memory Usage : 19.8 MB, less than 21.16% of C++ online submissions for Valid Sudoku.
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> columns(9, vector<bool>(9));
		vector<vector<bool>> rows(9, vector<bool>(9));
		vector<vector<bool>> boxes(9, vector<bool>(9));
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.')
					continue;
				int celli = i / 3;
				int cellj = j / 3;
				int cell = 3 * celli + cellj;
				int v = board[i][j] - '1';
				
				if (columns[i][v])
					return false;
				columns[i][v] = true;

				if (rows[j][v])
					return false;
				rows[j][v] = true;

				if (boxes[cell][v])
					return false;
				boxes[cell][v] = true;
			}
		}
		return true;
	}
};

int main()
{
	cout << boolalpha << Solution().isValidSudoku(vector<vector<char>>{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{ '6','.','.','1','9','5','.','.','.' },
		{ '.','9','8','.','.','.','.','6','.' },
		{ '8','.','.','.','6','.','.','.','3' },
		{ '4','.','.','8','.','3','.','.','1' },
		{ '7','.','.','.','2','.','.','.','6' },
		{ '.','6','.','.','.','.','2','8','.' },
		{ '.','.','.','4','1','9','.','.','5' },
		{ '.','.','.','.','8','.','.','7','9' }
	}) << endl; // true

	cout << boolalpha << Solution().isValidSudoku(vector<vector<char>>{
		{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
		{ '6','.','.','1','9','5','.','.','.' },
		{ '.','9','8','.','.','.','.','6','.' },
		{ '8','.','.','.','6','.','.','.','3' },
		{ '4','.','.','8','.','3','.','.','1' },
		{ '7','.','.','.','2','.','.','.','6' },
		{ '.','6','.','.','.','.','2','8','.' },
		{ '.','.','.','4','1','9','.','.','5' },
		{ '.','.','.','.','8','.','.','7','9' }
	}) << endl; // false

    return 0;
}

