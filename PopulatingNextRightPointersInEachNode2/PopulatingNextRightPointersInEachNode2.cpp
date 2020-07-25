
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

Given a binary tree

struct Node {
int val;
Node *left;
Node *right;
Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.



Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.


Example 1:



Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.


Constraints:

The number of nodes in the given tree is less than 6000.
-100 <= node.val <= 100

*/

// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};


//Runtime: 28 ms, faster than 26.35% of C++ online submissions for Populating Next Right Pointers in Each Node II.
//Memory Usage : 17.4 MB, less than 65.27% of C++ online submissions for Populating Next Right Pointers in Each Node II.
class Solution {
public:

	void connectImpl(Node* root, vector<Node*>& next, int level) {
		if (level == next.size())
			next.push_back(root);
		else {
			next[level]->next = root;
			next[level] = root;
		}
		if (root->left)
			connectImpl(root->left, next, level + 1);
		if (root->right)
			connectImpl(root->right, next, level + 1);
	}

	Node* connect(Node* root) {
		if (!root)
			return nullptr;
		vector<Node*> next;
		connectImpl(root, next, 0);
		return root;
	}
};

void printTree(Node* root) {
	queue<Node*> toVisit;
	if (root)
		toVisit.push(root);
	while (!toVisit.empty()) {
		queue<Node*> toVisit2;
		while (!toVisit.empty()) {
			Node* curr = toVisit.front();
			toVisit.pop();
			cout << curr->val << "(";
			if (curr->next)
				cout << curr->next->val;
			else
				cout << "*";
			cout << ") ";
			if (curr->left)
				toVisit2.emplace(curr->left);
			if (curr->right)
				toVisit2.emplace(curr->right);
		}
		cout << endl;
		toVisit.swap(toVisit2);
	}
}

int main()
{
	Node* t1 = new Node(1);
	t1->left = new Node(2);
	t1->right = new Node(3);
	t1->left->left = new Node(4);
	t1->left->right = new Node(5);
	t1->right->right = new Node(7);

	printTree(Solution().connect(t1));

    return 0;
}

