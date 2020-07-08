
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/prison-cells-after-n-days/
https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3379/

There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)



Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation:
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]


Note:

cells.length == 8
cells[i] is in {0, 1}
1 <= N <= 10^9

*/

//Runtime: 12 ms, faster than 33.77% of C++ online submissions for Prison Cells After N Days.
//Memory Usage : 12.9 MB, less than 12.05% of C++ online submissions for Prison Cells After N Days.
class Solution {
public:

	int hash(const vector<int>& cells) {
		int v = 0;
		for (auto ci : cells)
			v = 2 * v + ci;
		return v;
	}
	
	vector<int> getNextState(const vector<int>& cells) {
		vector<int> nextState = cells;
		nextState[0] = nextState[7] = 0;
		for (int i = 1; i < 7; ++i)
			nextState[i] = (cells[i - 1] == cells[i + 1]) ? 1 : 0;
		return nextState;
	}

	vector<int> restoreState(int hash) {
		vector<int> result(8);
		for (int i = 0; i < 8; ++i) {
			result[7 - i] = hash % 2;
			hash >>= 1;
		}
		return result;
	}

	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		unordered_map<int, int> hashToOrd, ordToHash;
		for (int i = 0; i < N; ++i) { // transition from state i to i+1
			int h = hash(cells);
			auto it = hashToOrd.find(h);
			if (end(hashToOrd) == it) {
				hashToOrd.emplace_hint(it, h, i);
				ordToHash.emplace(i, h);
				cells = getNextState(cells);
			}
			else {
				int n1 = it->second;
				int loopSize = i - n1;
				int state = n1 + (N - n1) % loopSize;
				return restoreState(ordToHash[state]);
			}
		}
		return cells;
	}
};

void print(const vector<int>& s) {
	copy(begin(s), end(s), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().prisonAfterNDays(vector<int>{0, 1, 0, 1, 1, 0, 0, 1}, 7)); // Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

	print(Solution().prisonAfterNDays(vector<int>{1, 0, 0, 1, 0, 0, 1, 0}, 1000000000)); // Day 7: [0,0,1,1,1,1,1,0]

    return 0;
}

