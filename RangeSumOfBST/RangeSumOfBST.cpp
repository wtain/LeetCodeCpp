
#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

/*
https://leetcode.com/problems/range-sum-of-bst/
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.



Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23


Note:

The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Runtime: 268 ms, faster than 6.66% of C++ online submissions for Range Sum of BST.
Memory Usage: 64.7 MB, less than 5.45% of C++ online submissions for Range Sum of BST.
*/
//class Solution {
//public:
//	int rangeSumBST(TreeNode* root, int L, int R) {
//		if (!root)
//			return 0;
//		if (root->val < L)
//			return rangeSumBST(root->right, L, R);
//		if (root->val > R)
//			return rangeSumBST(root->left, L, R);
//
//		return root->val + rangeSumBST(root->left, L, root->val) + rangeSumBST(root->right, root->val, R);
//	}
//};

/*
Runtime: 236 ms, faster than 8.62% of C++ online submissions for Range Sum of BST.
Memory Usage: 64.8 MB, less than 5.45% of C++ online submissions for Range Sum of BST.
*/
class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		if (!root)
			return 0;

		stack<tuple<TreeNode*, int, int>> toProcess;

		toProcess.emplace(root, L, R);

		int sum = 0;
		while (!toProcess.empty()) {
			auto t = toProcess.top();
			toProcess.pop();

			auto* pNode = get<0>(t);
			auto l = get<1>(t);
			auto r = get<2>(t);

			if (pNode->val < l) {
				if (pNode->right)
					toProcess.emplace(pNode->right, l, r);
			}
			else if (pNode->val > r) {
				if (pNode->left)
					toProcess.emplace(pNode->left, l, r);
			}
			else {
				sum += pNode->val;

				if (pNode->left)
					toProcess.emplace(pNode->left, l, pNode->val);
				if (pNode->right)
					toProcess.emplace(pNode->right, pNode->val, r);
			}
		}

		return sum;
	}
};

int main()
{
	{
		TreeNode* root = new TreeNode(10);
		root->left = new TreeNode(5);
		root->right = new TreeNode(15);
		root->left->left = new TreeNode(3);
		root->left->right = new TreeNode(7);
		root->right->right = new TreeNode(18);

		cout << Solution().rangeSumBST(root, 7, 15) << endl; // 32
	}

	{
		TreeNode* root = new TreeNode(10);
		root->left = new TreeNode(5);
		root->right = new TreeNode(15);
		root->left->left = new TreeNode(3);
		root->left->right = new TreeNode(7);
		root->right->left = new TreeNode(13);
		root->right->right = new TreeNode(18);
		root->left->left->left = new TreeNode(1);
		root->left->right->left = new TreeNode(6);

		cout << Solution().rangeSumBST(root, 6, 10) << endl; // 23
	}

    return 0;
}

