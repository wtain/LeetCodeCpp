
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// https://leetcode.com/problems/binary-tree-postorder-traversal/



/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
1
\
2
/
3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) 
	{
		stack<TreeNode*> toVisit;
		stack<int> visited;
		if (root)
			toVisit.push(root);
		while (!toVisit.empty())
		{
			auto p = toVisit.top(); toVisit.pop();
			visited.push(p->val);
			if (p->left)
				toVisit.push(p->left);
			if (p->right)
				toVisit.push(p->right);
		}
		vector<int> result;
		while (!visited.empty())
		{
			result.push_back(visited.top());
			visited.pop();
		}
		return result;
	}
};

void runTest(TreeNode* root)
{
	auto r = Solution().postorderTraversal(root);

	copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	TreeNode* n1 = new TreeNode(1);
	n1->right = new TreeNode(2);
	n1->right->left = new TreeNode(3);

	runTest(n1);

	TreeNode* n2 = new TreeNode(1);
	n2->left = new TreeNode(2);
	n2->right = new TreeNode(3);
	n2->left->left = new TreeNode(4);
	n2->left->right = new TreeNode(5);
	n2->right->left = new TreeNode(6);
	n2->right->right = new TreeNode(7);

	runTest(n2);

    return 0;
}

