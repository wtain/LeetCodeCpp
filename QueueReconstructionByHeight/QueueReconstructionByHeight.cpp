
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include <queue>
#include <tuple>

using namespace std;

/*
https://leetcode.com/problems/queue-reconstruction-by-height/
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3352/

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

*/

//Runtime: 312 ms, faster than 30.83% of C++ online submissions for Queue Reconstruction by Height.
//Memory Usage : 13.6 MB, less than 31.55% of C++ online submissions for Queue Reconstruction by Height.
class Solution {
public:

	struct Compare {
		bool operator() (const vector<int>& left, const vector<int>& right) const {
			//return tie(left[0], left[1]) < tie(right[0], right[1]);
			return tie(left[0], right[1]) < tie(right[0], left[1]);
		}
	};

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		priority_queue<vector<int>, vector<vector<int>>, Compare> queue;
		for (const auto& p : people)
			queue.push(p);

		vector<vector<int>> result;

		result.reserve(queue.size());
		//result.resize(queue.size());
		while (!queue.empty()) {
			const auto p = queue.top(); queue.pop();
			result.insert(begin(result) + p[1], p);
			//result[p[1]] = p;
			//result.push_back(queue.top()); 
		}

		return result;
	}
};

void print(const vector<vector<int>>& result) {
	for (const auto& r : result)
		cout << "(" << r[0] << " " << r[1] << ") ";
	cout << endl;
}

int main()
{
	print(Solution().reconstructQueue(vector<vector<int>>{ { 7,0 },{ 4,4 },{ 7,1 },{ 5,0 },{ 6,1 },{ 5,2 } })); // [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

    return 0;
}

