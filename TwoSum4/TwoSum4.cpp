
#define NULL 0

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

/*
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/solution/

Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
*/

class Solution {
public:

	bool find(TreeNode* root, int k)
	{
		if (!root)
			return false;
		if (root->val == k)
			return true;
		if (root->val > k)
			return find(root->left, k);
		else
			return find(root->right, k);
	}

	bool findTargetImpl(TreeNode* root, TreeNode* current, int k)
	{
		if (!current)
			return false;
		int m = k - current->val;
		if (m == k)
			return false;
		if (find(root->left, m))
			return true;
		if (find(root->right, m))
			return true;
		return findTargetImpl(root, current->left, k) || findTargetImpl(root, current->right, k);
	}

	bool findTarget(TreeNode* root, int k)
	{
		return findTargetImpl(root, root, k);
	}
};

int main()
{
	/*TreeNode* root = new TreeNode(5);

	root->left = new TreeNode(3);
	root->right = new TreeNode(6);

	root->right->right = new TreeNode(7);

	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);*/

	TreeNode* root = new TreeNode(2);

	root->right = new TreeNode(3);

	bool r = Solution().find(root, /*28*/6);

    return 0;
}

