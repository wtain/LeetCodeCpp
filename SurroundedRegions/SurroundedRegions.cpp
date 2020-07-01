
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>
#include <unordered_set>

using namespace std;

/*
https://leetcode.com/problems/surrounded-regions/
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3363/

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

//Runtime: 744 ms, faster than 5.25% of C++ online submissions for Surrounded Regions.
//Memory Usage : 18.3 MB, less than 8.56% of C++ online submissions for Surrounded Regions.
//class Solution {
//public:
//
//	struct pairhash {
//	public:
//		template <typename T, typename U>
//		std::size_t operator()(const std::pair<T, U> &x) const
//		{
//			return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
//		}
//	};
//
//	void solve(vector<vector<char>>& board) {
//		if (board.empty())
//			return;
//		const int n = board.size();
//		const int m = board[0].size();
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < m; ++j) {
//				if (board[i][j] == 'X')
//					continue;
//				stack<pair<int, int>> toVisit;
//				toVisit.emplace(i, j);
//				unordered_set<pair<int, int>, pairhash> visited;
//				bool touchesBorder = false;
//				while (!toVisit.empty()) {
//					const auto p = toVisit.top(); toVisit.pop();
//					if (p.first == 0 || p.first == n - 1 ||
//						p.second == 0 || p.second == m - 1 || board[p.first][p.second] == 'B')
//						touchesBorder = true;
//					visited.insert(p);
//					auto down = p, right = p, up = p, left = p;
//					if (++down.first < n && board[down.first][down.second] == 'O' && visited.find(down) == end(visited)) {
//						toVisit.emplace(down);
//					}
//					if (++right.second < m && board[right.first][right.second] == 'O' && visited.find(right) == end(visited)) {
//						toVisit.emplace(right);
//					}
//					if (--up.first >= 0 && board[up.first][up.second] == 'O' && visited.find(up) == end(visited)) {
//						toVisit.emplace(up);
//					}
//					if (--left.second >= 0 && board[left.first][left.second] == 'O' && visited.find(left) == end(visited)) {
//						toVisit.emplace(left);
//					}
//				}
//				for (const auto& p : visited)
//					board[p.first][p.second] = touchesBorder ? 'B' : 'X';
//			}
//		}
//		for (int i = 0; i < n; ++i)
//			for (int j = 0; j < m; ++j)
//				if (board[i][j] == 'B')
//					board[i][j] = 'O';
//	}
//};

//Runtime: 32 ms, faster than 54.14% of C++ online submissions for Surrounded Regions.
//Memory Usage : 10.2 MB, less than 80.68% of C++ online submissions for Surrounded Regions.
class Solution {
public:

	void mark(vector<vector<char>>& board, int i, int j, const int n, const int m) {
		stack<pair<int, int>> toVisit;
		toVisit.emplace(i, j);
		while (!toVisit.empty()) {
			const auto p = toVisit.top(); toVisit.pop();
			board[p.first][p.second] = 'B';
			auto down = p, right = p, up = p, left = p;
			if (++down.first < n && board[down.first][down.second] == 'O') {
				toVisit.emplace(down);
			}
			if (++right.second < m && board[right.first][right.second] == 'O') {
				toVisit.emplace(right);
			}
			if (--up.first >= 0 && board[up.first][up.second] == 'O') {
				toVisit.emplace(up);
			}
			if (--left.second >= 0 && board[left.first][left.second] == 'O') {
				toVisit.emplace(left);
			}
		}
	}

	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;
		const int n = board.size();
		const int m = board[0].size();
		for (int i = 0; i < n; ++i) {
			if (board[i][0] == 'O')
				mark(board, i, 0, n, m);
			if (board[i][m-1] == 'O')
				mark(board, i, m-1, n, m);
		}

		for (int j = 0; j < m; ++j) {
			if (board[0][j] == 'O')
				mark(board, 0, j, n, m);
			if (board[n-1][j] == 'O')
				mark(board, n - 1, j, n, m);
		}

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (board[i][j] == 'B')
					board[i][j] = 'O';
				else
					board[i][j] = 'X';
	}
};

void print(const vector<vector<char>>& board) {
	for (const auto& row : board) {
		copy(begin(row), end(row), ostream_iterator<char>(cout));
		cout << endl;
	}
}

int main()
{
	{
		vector<vector<char>> board =
		{
			{ 'O','O','O','O','X','X' },
			{ 'O','O','O','O','O','O' },
			{ 'O','X','O','X','O','O' },
			{ 'O','X','O','O','X','O' },
			{ 'O','X','O','X','O','O' },
			{ 'O','X','O','O','O','O' }
		};
		Solution().solve(board);
		print(board);
	/*	["O", "O", "O", "O", "X", "X"],
		["O", "O", "O", "O", "O", "O"],
		["O", "X", "O", "X", "O", "O"],
		["O", "X", "O", "O", "X", "O"],
		["O", "X", "O", "X", "O", "O"],
		["O", "X", "O", "O", "O", "O"]*/
	}

	{
		vector<vector<char>> board =
		{
			{ 'O','O','O' },
			{ 'O','O','O' },
			{ 'O','O','O' }
		};
		Solution().solve(board);
		print(board);
		//O O O
		//O O O
		//O O O
	}


	{
		vector<vector<char>> board =
		{
			{ 'X', 'X', 'X', 'X' },
			{ 'X', 'O', 'O', 'X' },
			{ 'X', 'X', 'O', 'X' },
			{ 'X', 'O', 'X', 'X' }
		};
		Solution().solve(board);
		print(board);
		//X X X X
		//X X X X
		//X X X X
		//X O X X
	}

    return 0;
}

