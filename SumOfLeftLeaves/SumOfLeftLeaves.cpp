
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/sum-of-left-leaves/
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3435/
Find the sum of all left leaves in a given binary tree.

Example:

3
/ \
9  20
/  \
15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Left Leaves.
//Memory Usage : 13.7 MB, less than 26.67% of C++ online submissions for Sum of Left Leaves.
class Solution {
public:

	int sumOfLeftLeavesImpl(TreeNode* root, bool isLeft) {
		if (!root)
			return 0;
		if (isLeft && !root->left && !root->right)
			return root->val;
		return sumOfLeftLeavesImpl(root->left, true) + sumOfLeftLeavesImpl(root->right, false);
	}

	int sumOfLeftLeaves(TreeNode* root) {
		return sumOfLeftLeavesImpl(root, false);
	}
};

int main()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	cout << Solution().sumOfLeftLeaves(root) << endl; // 24

    return 0;
}

