
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//#define NULL 0;

/*

https://leetcode.com/problems/binary-tree-maximum-path-sum/

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along 
the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

  1
 / \
2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9   20
     /  \
    15   7

Output: 42
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	void maxPathSumImpl(TreeNode* root, int sumFromRoot, int& maxSumParents, vector<int>& path, int& maxSum)
	{
		sumFromRoot += root->val;
		if (sumFromRoot > maxSumParents)
			maxSumParents = sumFromRoot;

		int maxSumInternal = sumFromRoot;
		int sumInternal = sumFromRoot;
		for (const auto& v : path)
		{
			sumInternal -= v;
			if (sumInternal > maxSumInternal)
				maxSumInternal = sumInternal;
		}
		if (maxSumInternal > maxSum)
			maxSum = maxSumInternal;

		if (maxSumParents > maxSum)
			maxSum = maxSumParents;

		int maxSumRootLeft = sumFromRoot;
		int maxSumRootRight = sumFromRoot;

		if (root->left)
		{
			path.push_back(root->val);
			maxPathSumImpl(root->left, sumFromRoot, maxSumRootLeft, path, maxSum);
			path.pop_back();
		}

		if (root->right)
		{
			path.push_back(root->val);
			maxPathSumImpl(root->right, sumFromRoot, maxSumRootRight, path, maxSum);
			path.pop_back();
		}

		maxSumParents = max(max(maxSumRootLeft, maxSumRootRight), maxSumParents);
		if (maxSumParents > maxSum)
			maxSum = maxSumParents;

		int sumCross = maxSumRootLeft - sumFromRoot + maxSumRootRight - sumFromRoot + root->val;
		if (sumCross > maxSum)
			maxSum = sumCross;
	}

	int maxPathSum(TreeNode* root) {
		if (!root)
			return 0;
		vector<int> path;
		int maxSum = root->val;
		int maxSumParents = root->val;
		maxPathSumImpl(root, 0, maxSumParents, path, maxSum);
		return maxSum;
	}
};

int main()
{
	/*TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(-2);
	root->right = new TreeNode(-3);
	root->right->left = new TreeNode(-2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->left->left->left = new TreeNode(-1);*/

	TreeNode* root = new TreeNode(9);
	root->left = new TreeNode(6);
	root->right = new TreeNode(-3);
	root->right->left = new TreeNode(-6);
	root->right->right = new TreeNode(2);
	root->right->right->left = new TreeNode(2);
	root->right->right->left->left = new TreeNode(-6);
	root->right->right->left->left->left = new TreeNode(-6);
	root->right->right->left->right = new TreeNode(-6);

	Solution sol;
	cout << sol.maxPathSum(root) << endl;

    return 0;
}

