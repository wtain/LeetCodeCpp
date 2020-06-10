
#include <iostream>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/diameter-of-binary-tree/

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
1
/ \
2   3
/ \
4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

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
	void diameterOfBinaryTreeImpl(TreeNode* root, int& maxDist, int& currentMax) {
		if (!root)
			return;
		int currentMax1 = 0;
		int currentMax2 = 0;
		diameterOfBinaryTreeImpl(root->left, maxDist, currentMax1);
		diameterOfBinaryTreeImpl(root->right, maxDist, currentMax2);
		currentMax = max(currentMax1, currentMax2) + 1;
		int dist = currentMax1 + currentMax2;
		maxDist = max(maxDist, dist);
	}

	int diameterOfBinaryTree(TreeNode* root) {
		int maxDist = 0, currentMax = 0;
		diameterOfBinaryTreeImpl(root, maxDist, currentMax);
		return maxDist;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);

	cout << Solution().diameterOfBinaryTree(root) << endl; // 3

    return 0;
}

