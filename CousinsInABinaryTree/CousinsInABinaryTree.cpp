
#include <iostream>
#include <iomanip>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.



Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false


Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.

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
//class Solution {
//public:
//
//	pair<TreeNode*, int> getDepth(TreeNode* current, TreeNode* parent, int val, int currentDepth) {
//		if (!current)
//			return{nullptr, -1};
//		if (current->val == val)
//			return{ parent, currentDepth };
//		auto r = getDepth(current->left, current, val, currentDepth + 1);
//		if (r.first)
//			return r;
//		return getDepth(current->right, current, val, currentDepth + 1);
//	}
//
//	bool isCousins(TreeNode* root, int x, int y) {
//		auto xr = getDepth(root, nullptr, x, 0);
//		auto yr = getDepth(root, nullptr, y, 0);
//		return xr.first != yr.first && xr.second == yr.second;
//	}
//};

//class Solution {
//public:
//
//	void getDepth(TreeNode* current, TreeNode* parent, int x, int y, int currentDepth, pair<TreeNode*, int>& xr, pair<TreeNode*, int>& yr) {
//		if (!current)
//			return;
//		if (current->val == x)
//			xr = { parent, currentDepth };
//		if (current->val == y)
//			yr = { parent, currentDepth };
//
//		getDepth(current->left, current, x, y, currentDepth + 1, xr, yr);
//		if (xr.first && yr.first)
//			return;
//		getDepth(current->right, current, x, y, currentDepth + 1, xr, yr);
//	}
//
//	bool isCousins(TreeNode* root, int x, int y) {
//		pair<TreeNode*, int> xr{ nullptr, -1 }, yr{ nullptr, -1 };
//		getDepth(root, nullptr, x, y, 0, xr, yr);
//		return xr.first != yr.first && xr.second == yr.second;
//	}
//};

class Solution {
public:

	void getDepth(TreeNode* current, TreeNode* parent, int x, int y, int currentDepth, pair<TreeNode*, int>& xr, pair<TreeNode*, int>& yr) {
		while (current)
		{
			if (current->val == x)
				xr = { parent, currentDepth };
			if (current->val == y)
				yr = { parent, currentDepth };

			getDepth(current->left, current, x, y, currentDepth + 1, xr, yr);
			if (xr.first && yr.first)
				return;

			parent = current;
			current = current->right;
			++currentDepth;
		}
	}

	bool isCousins(TreeNode* root, int x, int y) {
		pair<TreeNode*, int> xr{ nullptr, -1 }, yr{ nullptr, -1 };
		getDepth(root, nullptr, x, y, 0, xr, yr);
		return xr.first != yr.first && xr.second == yr.second;
	}
};

int main()
{
	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->left->left = new TreeNode(4);
		cout << boolalpha << Solution().isCousins(root, 4, 3) << endl; // false
	}

	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->left->right = new TreeNode(4);
		root->right->right = new TreeNode(5);
		cout << boolalpha << Solution().isCousins(root, 4, 5) << endl; // true
	}

	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->left->right = new TreeNode(4);
		cout << boolalpha << Solution().isCousins(root, 2, 3) << endl; // false
	}

    return 0;
}

