
#include <iostream>
#include <vector>
#include <stack>
//#include <algorithm>
//#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/n-ary-tree-preorder-traversal/

Given an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).



Follow up:

Recursive solution is trivial, could you do it iteratively?



Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]


Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 10^4]

*/

/*
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
*/

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

class Solution {
public:
	vector<int> preorder(Node* root) {
		if (!root)
			return{};
		vector<int> result;
		stack<Node*> nodes;
		nodes.push(root);
		while (!nodes.empty()) {
			Node* n = nodes.top();
			nodes.pop();
			result.push_back(n->val);
			for (int i = n->children.size() - 1; i >= 0; --i)
				nodes.push(n->children[i]);
		}
		return result;
	}
};

int main()
{
	{
		Node* root = new Node(1);
		root->children.push_back(new Node(3));
		root->children[0]->children.push_back(new Node(5));
		root->children[0]->children.push_back(new Node(6));
		root->children.push_back(new Node(2));
		root->children.push_back(new Node(4));
		auto result = Solution().preorder(root);
		for (auto n : result)
			cout << n << " ";
		cout << endl; // [1,3,5,6,2,4]
	}

	{
		Node* root = new Node(1);
		
		root->children.push_back(new Node(2));
		root->children.push_back(new Node(3));
		root->children.push_back(new Node(4));
		root->children.push_back(new Node(5));

		root->children[1]->children.push_back(new Node(6));
		root->children[1]->children.push_back(new Node(7));
		root->children[1]->children[1]->children.push_back(new Node(11));
		root->children[1]->children[1]->children[0]->children.push_back(new Node(14));

		root->children[2]->children.push_back(new Node(8));
		root->children[2]->children[0]->children.push_back(new Node(12));

		root->children[3]->children.push_back(new Node(9));
		root->children[3]->children[0]->children.push_back(new Node(13));
		root->children[3]->children.push_back(new Node(10));

		auto result = Solution().preorder(root);
		for (auto n : result)
			cout << n << " ";
		cout << endl; // [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
	}

    return 0;
}

