
#include <iostream>

using namespace std;

// https://leetcode.com/problems/find-bottom-left-tree-value/description/

/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

  2
 / \
1   3

Output:
1
Example 2:
Input:

    1
   / \
  2   3
 /   / \
4   5   6
   /
  7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		int leftMostVal = root->val; int level = 0; int pos = 0;
		findBottomLeftValueImpl(root, leftMostVal, level, pos, 0, 0);
		return leftMostVal;
	}

	void findBottomLeftValueImpl(TreeNode* root, int& leftMostVal, int& level, int& pos, int curLev, int curPos)
	{
		if (curLev > level || curLev == level && pos > curPos)
		{
			level = curLev;
			leftMostVal = root->val;
			pos = curPos;
		}
		if (root->left)
			findBottomLeftValueImpl(root->left, leftMostVal, level, pos, curLev + 1, curPos - 1);
		if (root->right)
			findBottomLeftValueImpl(root->right, leftMostVal, level, pos, curLev + 1, curPos + 1);
	}
};

int main()
{
	TreeNode* n1 = new TreeNode(2);
	n1->left = new TreeNode(1);
	n1->right = new TreeNode(3);

	cout << Solution().findBottomLeftValue(n1) << endl; // 1

	TreeNode* n2 = new TreeNode(2);
	n2->left = new TreeNode(1);
	n2->right = new TreeNode(3);
	n2->left->left = new TreeNode(4);
	n2->right->left = new TreeNode(5);
	n2->right->right = new TreeNode(6);
	n2->right->left->left = new TreeNode(7);

	cout << Solution().findBottomLeftValue(n2) << endl; // 7

	TreeNode* n3 = new TreeNode(0);
	n3->right = new TreeNode(-1);
	cout << Solution().findBottomLeftValue(n3) << endl; // -1


    return 0;
}

