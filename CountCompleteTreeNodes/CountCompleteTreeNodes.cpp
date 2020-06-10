
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/count-complete-tree-nodes/

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input:
     1
   /   \
  2     3
 / \    /
4   5  6

Output: 6

*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int countNodes(TreeNode* root) 
	{
		int hl = countSide(root, true), hr = countSide(root, false);
		if (hl == hr)
			return (1 << hl) - 1;
		return countNodes(root->left) + countNodes(root->right) + 1;
	}

	int countSide(TreeNode* root, bool l)
	{
		int r = 0;
		while (root)
		{
			++r;
			root = l ? root->left : root->right;
		}
		return r;
	}
};

int main()
{
	TreeNode* n1 = new TreeNode(1);
	n1->left = new TreeNode(2);
	n1->right = new TreeNode(3);
	n1->left->left = new TreeNode(4);
	n1->left->right = new TreeNode(5);
	n1->right->left = new TreeNode(6);

	cout << Solution().countNodes(n1) << endl; // 6
	cout << Solution().countNodes(nullptr) << endl; // 0

    return 0;
}

