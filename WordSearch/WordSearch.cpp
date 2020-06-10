
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

/*
https://leetcode.com/problems/word-search/

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.


Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

// Runtime: 64 ms, faster than 60.05% of C++ online submissions for Word Search.
// Memory Usage : 11.8 MB, less than 52.94% of C++ online submissions for Word Search.
//class Solution {
//public:
//
//	bool in(const int i, const int j, const int h, const int w) {
//		return i >= 0 && j >= 0 && i < h && j < w;
//	}
//
//	bool check(const int i, const int j, const int h, const int w, const vector<vector<char>>& board, const string& word, vector<vector<bool>>& visited, int startIndex) {
//		if (in(i, j, h, w) && !visited[i][j])
//			if (match(i, j, h, w, board, word, visited, startIndex + 1))
//				return true;
//		return false;
//	}
//
//	bool match(const int i, const int j, const int h, const int w, const vector<vector<char>>& board, const string& word, vector<vector<bool>>& visited, int startIndex) {
//		if (startIndex == word.length())
//			return true;
//		if (word[startIndex] != board[i][j])
//			return false;
//		if (startIndex+1 == word.length())
//			return true;
//		visited[i][j] = true;
//		if (
//			check(i - 1, j, h, w, board, word, visited, startIndex) ||
//			check(i + 1, j, h, w, board, word, visited, startIndex) ||
//			check(i, j - 1, h, w, board, word, visited, startIndex) ||
//			check(i, j + 1, h, w, board, word, visited, startIndex))
//			return true;
//		visited[i][j] = false;
//		return false;
//	}
//
//	bool exist(vector<vector<char>>& board, string word) {
//		const int h = board.size();
//		const int w = board[0].size();
//		vector<vector<bool>> visited(h, vector<bool>(w, false));
//		for (int i = 0; i < h; ++i)
//			for (int j = 0; j < w; ++j)
//				if (match(i, j, h, w, board, word, visited, 0))
//					return true;
//		return false;
//	}
//};

// Runtime: 64 ms, faster than 60.05% of C++ online submissions for Word Search.
// Memory Usage : 11.4 MB, less than 52.94% of C++ online submissions for Word Search.
//class Solution {
//public:
//
//	bool in(const int i, const int j, const int h, const int w) {
//		return i >= 0 && j >= 0 && i < h && j < w;
//	}
//
//	bool match(const int i, const int j, const int h, const int w, const vector<vector<char>>& board, const string& word, vector<vector<bool>>& visited, int startIndex) {
//		if (startIndex == word.length())
//			return true;
//		if (!in(i, j, h, w))
//			return false;
//		if (visited[i][j])
//			return false;
//		if (word[startIndex] != board[i][j])
//			return false;
//		if (startIndex + 1 == word.length())
//			return true;
//		visited[i][j] = true;
//		if (
//			match(i - 1, j, h, w, board, word, visited, startIndex+1) ||
//			match(i + 1, j, h, w, board, word, visited, startIndex+1) ||
//			match(i, j - 1, h, w, board, word, visited, startIndex+1) ||
//			match(i, j + 1, h, w, board, word, visited, startIndex+1))
//			return true;
//		visited[i][j] = false;
//		return false;
//	}
//
//	bool exist(vector<vector<char>>& board, string word) {
//		const int h = board.size();
//		const int w = board[0].size();
//		vector<vector<bool>> visited(h, vector<bool>(w, false));
//		for (int i = 0; i < h; ++i)
//			for (int j = 0; j < w; ++j)
//				if (match(i, j, h, w, board, word, visited, 0))
//					return true;
//		return false;
//	}
//};

// Runtime: 56 ms, faster than 62.01% of C++ online submissions for Word Search.
// Memory Usage : 11.4 MB, less than 54.41% of C++ online submissions for Word Search.
class Solution {
	int w, h;
	vector<vector<bool>> visited;
	string word;
public:

	bool match(const int i, const int j, const vector<vector<char>>& board, int startIndex) {
		if (startIndex == word.length())
			return true;
		if (i < 0 || j < 0 || i >= h || j >= w)
			return false;
		if (visited[i][j])
			return false;
		if (word[startIndex] != board[i][j])
			return false;
		if (startIndex + 1 == word.length())
			return true;
		visited[i][j] = true;
		if (
			match(i - 1, j, board, startIndex + 1) ||
			match(i + 1, j, board, startIndex + 1) ||
			match(i, j - 1, board, startIndex + 1) ||
			match(i, j + 1, board, startIndex + 1))
			return true;
		visited[i][j] = false;
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		h = board.size();
		w = board[0].size();
		visited.resize(h, vector<bool>(w, false));
		this->word = word;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (match(i, j, board, 0))
					return true;
		return false;
	}
};

int main()
{
	cout << boolalpha << Solution().exist(vector<vector<char>>{ {'a', 'a' }}, "aaa") << endl; // false
	cout << boolalpha << Solution().exist(vector<vector<char>>{ {'A', 'B', 'C', 'E'}, { 'S','F','C','S' }, { 'A','D','E','E' }}, "ABCCED") << endl; // true
	cout << boolalpha << Solution().exist(vector<vector<char>>{ {'A', 'B', 'C', 'E'}, { 'S','F','C','S' }, { 'A','D','E','E' }}, "SEE") << endl; // true
	cout << boolalpha << Solution().exist(vector<vector<char>>{ {'A', 'B', 'C', 'E'}, { 'S','F','C','S' }, { 'A','D','E','E' }}, "ABCB") << endl; // false
	cout << boolalpha << Solution().exist(vector<vector<char>>{ {'a' }}, "a") << endl; // true
    return 0;
}

