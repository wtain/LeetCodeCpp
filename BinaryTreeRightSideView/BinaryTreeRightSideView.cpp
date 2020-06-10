
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/binary-tree-right-side-view/

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

     1            <---
   /   \
  2     3         <---
   \     \
    5     4       <---

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	void rightSideViewImpl(TreeNode* root, vector<int>& result, int level)
	{
		if (!root)
			return;
		if (result.size() == level)
			result.push_back(root->val);
		rightSideViewImpl(root->right, result, level + 1);
		rightSideViewImpl(root->left, result, level + 1);
	}

	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		rightSideViewImpl(root, result, 0);
		return result;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(4);
	// 1, 3, 4
	const auto r = Solution().rightSideView(root);

	copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
	cout << endl;

    return 0;
}

