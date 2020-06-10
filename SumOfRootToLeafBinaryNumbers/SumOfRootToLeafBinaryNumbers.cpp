
#include <iostream>

using namespace std;

/*
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.



Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22


Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
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

	void sumRootToLeafImpl(TreeNode* root, int& sum, int v) {
		if (!root)
			return;
		int v1 = 2 * v + root->val;

		if (!root->left && !root->right) {
			sum += v1;
			return;
		}

		if (root->left)
			sumRootToLeafImpl(root->left, sum, v1);
		if (root->right)
			sumRootToLeafImpl(root->right, sum, v1);
	}

	int sumRootToLeaf(TreeNode* root) {
		int sum = 0;
		sumRootToLeafImpl(root, sum, 0);
		return sum;
	}
};

int main()
{
	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(0);
		root->right = new TreeNode(1);
		root->left->left = new TreeNode(0);
		root->left->right = new TreeNode(1);
		root->right->left = new TreeNode(0);
		root->right->right = new TreeNode(1);
		cout << Solution().sumRootToLeaf(root) << endl; // 22
	}
    return 0;
}

