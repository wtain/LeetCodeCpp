
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

/*
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

      4
    /   \
   2     6
  / \
 1   3

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.
*/

// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

1
\
3
/
2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).


Note:

There are at least two nodes in this BST.
This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	void minDistImpl(TreeNode* root, int& minDist, int& vmin, int& vmax)
	{
		if (root->left)
		{
			int dist = root->val - root->left->val;
			minDist = min(minDist, dist);
			int min1 = root->left->val, max1 = root->left->val;
			minDistImpl(root->left, minDist, min1, max1);
			dist = root->val - max1;
			minDist = min(minDist, dist);
			vmin = min(vmin, min1);
			//vmax = max(vmax, max1);
		}
		if (root->right)
		{
			int dist = root->right->val - root->val;
			minDist = min(minDist, dist);
			int min1 = root->right->val, max1 = root->right->val;
			minDistImpl(root->right, minDist, min1, max1);
			dist = min1 - root->val;
			minDist = min(minDist, dist);
			//vmin = min(vmin, min1);
			vmax = max(vmax, max1);
		}
	}

	int minDiffInBST(TreeNode* root) {
		int minDist = numeric_limits<int>::max();
		if (root)
		{
			int vmin = root->val, vmax = root->val;
			minDistImpl(root, minDist, vmin, vmax);
		}
		return minDist;
	}
};

//class Solution {
//public:
//
//	void minDistImpl(TreeNode* root, int& minDist)
//	{
//		if (root->left)
//		{
//			int dist = root->val - root->left->val;
//			minDist = min(minDist, dist);
//			minDistImpl(root->left, minDist);
//		}
//		if (root->right)
//		{
//			int dist = root->right->val - root->val;
//			minDist = min(minDist, dist);
//			minDistImpl(root->right, minDist);
//		}
//	}
//
//	int minDiffInBST(TreeNode* root) {
//		int minDist = numeric_limits<int>::max();
//		if (root)
//			minDistImpl(root, minDist);
//		return minDist;
//	}
//};

int main()
{
	TreeNode* n1 = new TreeNode(4);
	n1->left = new TreeNode(2);
	n1->right = new TreeNode(6);
	n1->left->left = new TreeNode(1);
	n1->left->right = new TreeNode(3);

	cout << Solution().minDiffInBST(n1) << endl; // 1

	TreeNode* n2 = new TreeNode(69);
	n2->left = new TreeNode(3);
	n2->right = new TreeNode(72);
	n2->left->right = new TreeNode(61);
	n2->left->right->left = new TreeNode(47);

	cout << Solution().minDiffInBST(n2) << endl; // 3

    return 0;
}

