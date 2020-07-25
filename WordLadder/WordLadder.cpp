
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/word-ladder/

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*/

//Runtime: 1728 ms, faster than 5.01% of C++ online submissions for Word Ladder.
//Memory Usage : 234.3 MB, less than 5.09% of C++ online submissions for Word Ladder.
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		auto it = find(begin(wordList), end(wordList), endWord);
		if (it == end(wordList))
			return 0;
		int target = distance(begin(wordList), it);
		const int n = wordList.size();
		vector<vector<int>> M(n+1, vector<int>(n+1));
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			for (int j = 0; j < beginWord.length(); ++j)
				if (beginWord[j] != wordList[i][j])
					++cnt;
			if (cnt == 1)
				M[0][i+1] = M[i+1][0] = 1;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {

				int cnt = 0;
				for (int k = 0; k < beginWord.length(); ++k)
					if (wordList[j][k] != wordList[i][k])
						++cnt;
				if (cnt == 1)
					M[j + 1][i + 1] = M[i + 1][j + 1] = 1;

			}
		}

		vector<int> distances(n+1);
		vector<bool> visited(n + 1);
		queue<int> toVisit;
		toVisit.push(0);
		while (!toVisit.empty()) {
			int curr = toVisit.front();
			toVisit.pop();
			for (int i = 0; i < n + 1; ++i) {
				if (M[curr][i] && !visited[i]) {
					toVisit.push(i);
					visited[i] = true;
					distances[i] = distances[curr] + 1;
				}
			}
		}
		
		return distances[target + 1] ? (distances[target+1] + 1) : 0;
	}
};

int main()
{
	cout << Solution().ladderLength("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log", "cog"}) << endl; // 5
	cout << Solution().ladderLength("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log"}) << endl; // 0

    return 0;
}

