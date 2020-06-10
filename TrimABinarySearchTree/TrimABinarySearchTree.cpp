
#include <iostream>
#include <iomanip>

using namespace std;

/*
https://leetcode.com/problems/trim-a-binary-search-tree/

Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
Input:
1
/ \
0   2

L = 1
R = 2

Output:
1
\
2
Example 2:
Input:
3
/ \
0   4
\
2
/
1

L = 1
R = 3

Output:
3
/
2
/
1
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (!root)
			return nullptr;
		if (root->val > R)
			return trimBST(root->left, L, R);
		else  if (root->val < L)
			return trimBST(root->right, L, R);
		// (root->val >= L && root->val <= R)
		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);
		return root;
	}
};

void printTree(TreeNode* root) {
	if (!root)
		return;
	printTree(root->left);
	cout << root->val << " ";
	printTree(root->right);
}

int main()
{
	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(0);
		root->right = new TreeNode(2);
		printTree(Solution().trimBST(root, 1, 2));
		cout << endl; // 1 2
	}
	{
		TreeNode* root = new TreeNode(3);
		root->left = new TreeNode(0);
		root->right = new TreeNode(4);
		root->left->right = new TreeNode(2);
		root->left->right->left = new TreeNode(1);
		printTree(Solution().trimBST(root, 1, 3));
		cout << endl; // 1 2 3
	}
    return 0;
}

