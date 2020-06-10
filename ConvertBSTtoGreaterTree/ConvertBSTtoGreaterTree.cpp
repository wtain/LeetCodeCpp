
#include <iostream>

using namespace std;

/*
https://leetcode.com/problems/convert-bst-to-greater-tree/
https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
    5
  /   \
2     13

Output: The root of a Greater Tree like this:
   18
  /   \
20     13
Note: This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
*/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}	
};

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:

	TreeNode* convertBSTImpl(TreeNode* root, int v, int& sum) {
		if (!root)
			return nullptr;
		TreeNode* newRoot = new TreeNode();

		int sumleft = 0, sumright = 0;

		newRoot->right = convertBSTImpl(root->right, v, sumright);
		newRoot->val = root->val + sumright + v;

		newRoot->left = convertBSTImpl(root->left, newRoot->val, sumleft);

		sum = sumleft + sumright + root->val;

		return newRoot;
	}

	TreeNode* convertBST(TreeNode* root) {
		int sum = 0;
		return convertBSTImpl(root, 0, sum);
	}
};

void printTree(TreeNode* root)
{
	if (!root)
		return;
	cout << "( ";
	printTree(root->left);
	cout << root->val << " ";
	printTree(root->right);
	cout << " )";
}

int main()
{
	{
		TreeNode* root = new TreeNode(5);
		root->left = new TreeNode(2);
		root->right = new TreeNode(13);

		TreeNode* newRoot = Solution().convertBST(root);
		printTree(newRoot);
		cout << endl;
	}

	{
		TreeNode* root = new TreeNode(4);
		
		root->left = new TreeNode(1);
		root->left->left = new TreeNode(0);
		root->left->right = new TreeNode(2);
		root->left->right->right = new TreeNode(3);

		root->right = new TreeNode(6);
		root->right->left = new TreeNode(5);
		root->right->right = new TreeNode(7);
		root->right->right->right = new TreeNode(8);

		TreeNode* newRoot = Solution().convertBST(root);
		printTree(newRoot);
		cout << endl;
	}

    return 0;
}

