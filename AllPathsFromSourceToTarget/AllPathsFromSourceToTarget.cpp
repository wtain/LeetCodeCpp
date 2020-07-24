
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <unordered_set>

using namespace std;

/*
https://leetcode.com/problems/all-paths-from-source-to-target/
https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3400/
Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
*/

//Runtime: 96 ms, faster than 14.19% of C++ online submissions for All Paths From Source to Target.
//Memory Usage : 22.1 MB, less than 15.85% of C++ online submissions for All Paths From Source to Target.
class Solution {
public:

	struct Node {
		int current;
		vector<bool> visited;
		vector<int> path;

		Node(int _current, int n) : current(_current), visited(n, false) {
		}

		Node(int _current, const Node& node) : current(_current), visited(node.visited), path(node.path) {
		}

		void visit() {
			visited[current] = true;
			path.push_back(current);
		}
	};

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> result;
		queue<Node> toVisit;
		if (!graph.empty())
			toVisit.emplace(0, graph.size());
		while (!toVisit.empty()) {
			Node curr = toVisit.front();
			toVisit.pop();
			curr.visit();
			if (curr.current == graph.size() - 1) {
				result.push_back(curr.path);
			}
			for (const auto edge : graph[curr.current]) {
				if (!curr.visited[edge]) {
					toVisit.emplace(edge, curr);
				}
			}
		}
		return result;
	}
};

//class Solution {
//public:
//
//	struct Node {
//		int current;
//		vector<bool> visited;
//		const Node* parent;
//
//		Node(int _current, int n) : current(_current), visited(n, false), parent(nullptr){
//		}
//
//		Node(int _current, const Node& node) : current(_current), visited(node.visited), parent(&node) {
//		}
//
//		void visit() {
//			visited[current] = true;
//		}
//
//		vector<int> getPath() {
//
//		}
//	};
//
//	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//		vector<vector<int>> result;
//		queue<Node> toVisit;
//		if (!graph.empty())
//			toVisit.emplace(0, graph.size());
//		while (!toVisit.empty()) {
//			Node curr = toVisit.front();
//			toVisit.pop();
//			curr.visit();
//			if (curr.current == graph.size() - 1) {
//				result.push_back(curr.getPath());
//			}
//			for (const auto edge : graph[curr.current]) {
//				if (!curr.visited[edge]) {
//					toVisit.emplace(edge, curr);
//				}
//			}
//		}
//		return result;
//	}
//};

void print(const vector<vector<int>>& r) {
	for (const auto& p : r) {
		copy(begin(p), end(p), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << endl;
}

int main()
{
	print(Solution().allPathsSourceTarget(vector<vector<int>> {
		{ 1, 2 }, { 3 }, { 3 }, {}
	})); // [[0,1,3],[0,2,3]] 

    return 0;
}

