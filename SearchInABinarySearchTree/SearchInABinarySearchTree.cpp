
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/search-in-a-binary-search-tree/

Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

For example,

Given the tree:
4
/ \
2   7
/ \
1   3

And the value to search: 2
You should return this subtree:

2
/ \
1   3
In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.

Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) as [], not null.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 20.20%
class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		while (root) {

			if (root->val == val)
				return root;
			if (root->val > val)
				root = root->left;
			else
				root = root->right;
		}
		return nullptr;
	}
};

// 15.06%
//class Solution {
//public:
//	TreeNode* searchBST(TreeNode* root, int val) {
//		if (!root)
//			return nullptr;
//		if (root->val == val)
//			return root;
//		if (root->val > val)
//			return searchBST(root->left, val);
//		return searchBST(root->right, val);
//	}
//};

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
		TreeNode* root = new TreeNode(4);
		root->left = new TreeNode(2);
		root->right = new TreeNode(7);
		root->left->left = new TreeNode(1);
		root->left->right = new TreeNode(3);

		printTree(Solution().searchBST(root, 2)); // 1 2 3
		cout << endl;
	}
    return 0;
}

