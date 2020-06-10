
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <queue>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/n-ary-tree-postorder-traversal/

Given an n-ary tree, return the postorder traversal of its nodes' values.

For example, given a 3-ary tree:

     1
   / | \
  3  2  4
 / \
5   6

Return its postorder traversal as: [5,6,3,2,4,1].


Note:

Recursive solution is trivial, could you do it iteratively?

*/

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/

class Solution {
public:

	/*void postorderImpl(Node* root, vector<int>& result)
	{
		if (!root)
			return;
		for (Node* c: root->children)
			postorderImpl(c, result);
		result.push_back(root->val);
	}

	vector<int> postorder(Node* root) {
		vector<int> result;
		postorderImpl(root, result);
		return result;
	}*/

	vector<int> postorder(Node* root) {
		vector<int> result;
		stack<pair<Node*, int>> nodes;
		if (root)
			nodes.push(make_pair(root, 0));
		while (!nodes.empty())
		{
			auto& ni = nodes.top();
			if (ni.second == ni.first->children.size())
			{
				nodes.pop();
				result.push_back(ni.first->val);
			}
			else
			{
				nodes.push(make_pair(ni.first->children[ni.second++], 0));
			}
		}
		return result;
	}
};

int main()
{

	auto r1 = Solution().postorder(nullptr);
	copy(begin(r1), end(r1), ostream_iterator<int>(cout, " "));
	cout << endl;

	vector<Node*> v2;
	v2.push_back(new Node(5, {}));
	v2.push_back(new Node(6, {}));

	vector<Node*> v1;
	v1.push_back(new Node(3, v2));
	v1.push_back(new Node(2, {}));
	v1.push_back(new Node(4, {}));
	Node* n1 = new Node(1, v1);

	auto r2 = Solution().postorder(n1);
	copy(begin(r2), end(r2), ostream_iterator<int>(cout, " ")); // 5 6 3 2 4 1
	cout << endl;

    return 0;
}

