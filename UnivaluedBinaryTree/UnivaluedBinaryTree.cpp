
#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/univalued-binary-tree/

A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.



Example 1:


Input: [1,1,1,1,1,null,1]
Output: true
Example 2:


Input: [2,2,2,5,2]
Output: false
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
	bool isUnivalTree(TreeNode* root) {
		if (!root)
			return true;
		stack<TreeNode*> nodes;
		int val = root->val;
		nodes.push(root);
		while (!nodes.empty()) {
			TreeNode* node = nodes.top();
			nodes.pop();
			if (node->val != val)
				return false;
			if (node->left)
				nodes.push(node->left);
			if (node->right)
				nodes.push(node->right);
		}
		return true;
	}
};

int main()
{
	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(1);
		root->right = new TreeNode(1);
		root->left->left = new TreeNode(1);
		root->left->right = new TreeNode(1);
		root->right->right = new TreeNode(1);
		cout << boolalpha << Solution().isUnivalTree(root) << endl; // true
	}
	{
		TreeNode* root = new TreeNode(2);
		root->left = new TreeNode(2);
		root->right = new TreeNode(2);
		root->left->left = new TreeNode(5);
		root->left->right = new TreeNode(2);
		
		cout << boolalpha << Solution().isUnivalTree(root) << endl; // false
	}
    return 0;
}

