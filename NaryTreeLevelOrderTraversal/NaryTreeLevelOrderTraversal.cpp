
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>

using namespace std;

/*
https://leetcode.com/problems/n-ary-tree-level-order-traversal/

Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).



Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]


Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 10^4]

*/

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

//Runtime: 92 ms, faster than 8.66% of C++ online submissions for N - ary Tree Level Order Traversal.
//Memory Usage : 11.7 MB, less than 76.04% of C++ online submissions for N - ary Tree Level Order Traversal.
class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> result;

		queue<pair<Node*, int>> toVisit;
		if (root)
			toVisit.emplace(root, 0);

		while (!toVisit.empty()) {
			auto p = toVisit.front();
			Node* curr = p.first;
			auto level = p.second;
			toVisit.pop();
			if (level == result.size())
				result.emplace_back();
			result[level].push_back(curr->val);
			for (Node* child : curr->children)
				toVisit.emplace(child, level+1);
		}

		return result;
	}
};

void print(const vector<vector<int>>& r) {
	for (const auto& row : r) {
		copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << endl;
}

int main()
{
	Node* t1 = new Node(1);
	t1->children.push_back(new Node(3));
	t1->children.push_back(new Node(2));
	t1->children.push_back(new Node(4));
	t1->children[0]->children.push_back(new Node(5));
	t1->children[0]->children.push_back(new Node(6));
	print(Solution().levelOrder(t1)); // [[1],[3,2,4],[5,6]]

	Node* t2 = new Node(1);

	t2->children.push_back(new Node(2));
	t2->children.push_back(new Node(3));
	t2->children.push_back(new Node(4));
	t2->children.push_back(new Node(5));

	t2->children[1]->children.push_back(new Node(6));
	t2->children[1]->children.push_back(new Node(7));
	t2->children[1]->children[1]->children.push_back(new Node(11));
	t2->children[1]->children[1]->children[0]->children.push_back(new Node(14));

	t2->children[2]->children.push_back(new Node(8));
	t2->children[2]->children[0]->children.push_back(new Node(12));

	t2->children[3]->children.push_back(new Node(9));
	t2->children[3]->children.push_back(new Node(10));

	t2->children[3]->children[0]->children.push_back(new Node(13));

	print(Solution().levelOrder(t2)); // [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]


    return 0;
}

