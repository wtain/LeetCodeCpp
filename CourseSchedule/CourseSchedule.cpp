
#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3344/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should
also have finished course 1. So it is impossible.


Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
Hide Hint #1
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Hide Hint #2
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Hide Hint #3
Topological sort could also be done via BFS.

*/

//Runtime: 180 ms
//Memory Usage : 16.4 MB
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<unordered_set<int>> dependencies;
		vector<unordered_set<int>> dependants;
		unordered_set<int> taken;

		dependencies.resize(numCourses);
		dependants.resize(numCourses);
		for (const auto& prereq : prerequisites) {
			dependencies[prereq[1]].insert(prereq[0]);
			dependants[prereq[0]].insert(prereq[1]);
		}

		bool tookSomething = false;
		do {
			tookSomething = false;
			for (int i = 0; i < numCourses; ++i) {
				if (end(taken) == taken.find(i) && dependencies[i].empty()) {
					taken.insert(i);
					tookSomething = true;
					for (auto j : dependants[i])
						dependencies[j].erase(i);
				}
			}
		} while (tookSomething);

		return taken.size() == numCourses;
	}
};

int main()
{
	cout << boolalpha << Solution().canFinish(2, vector<vector<int>>{ {1, 0} }) << endl; // true
	cout << boolalpha << Solution().canFinish(2, vector<vector<int>>{ {1, 0}, {0, 1} }) << endl; // false

	cout << boolalpha << Solution().canFinish(4, vector<vector<int>>{ {0, 1}, {1, 2}, { 2, 3 } }) << endl; // true
	cout << boolalpha << Solution().canFinish(4, vector<vector<int>>{ {0, 1}, { 1, 2 }, { 2, 3 }, {3, 0} }) << endl; // false

    return 0;
}

