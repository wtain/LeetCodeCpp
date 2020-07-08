
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3378/

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its bottom-up level order traversal as:
[
[15,7],
[9,20],
[3]
]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Runtime: 16 ms, faster than 16.38% of C++ online submissions for Binary Tree Level Order Traversal II.
//Memory Usage : 13.5 MB, less than 18.21% of C++ online submissions for Binary Tree Level Order Traversal II.
//class Solution {
//public:
//
//	void levelOrderBottomImpl(vector<vector<int>>& levels, TreeNode* root, int level, int lmax)
//	{
//		if (!root)
//			return;
//		levelOrderBottomImpl(levels, root->left, level + 1, lmax);
//		levelOrderBottomImpl(levels, root->right, level + 1, lmax);
//		levels[lmax - level - 1].push_back(root->val);
//	}
//
//	int maxLevel(TreeNode* root)
//	{
//		if (!root)
//			return 0;
//		return 1 + max(maxLevel(root->left), maxLevel(root->right));
//	}
//
//	vector<vector<int>> levelOrderBottom(TreeNode* root) {
//		vector<vector<int>> levels;
//		int lmax = maxLevel(root);
//		levels.resize(lmax);
//		levelOrderBottomImpl(levels, root, 0, lmax);
//		return levels;
//	}
//};

//Runtime: 4 ms, faster than 92.73% of C++ online submissions for Binary Tree Level Order Traversal II.
//Memory Usage : 12.6 MB, less than 90.39% of C++ online submissions for Binary Tree Level Order Traversal II.
class Solution {
public:

	int maxLevel(TreeNode* root)
	{
		if (!root)
			return 0;
		return 1 + max(maxLevel(root->left), maxLevel(root->right));
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {

		if (!root)
			return{};

		vector<vector<int>> levels;
		int lmax = maxLevel(root);
		levels.resize(lmax);

		vector<TreeNode*> nodes1;
		vector<TreeNode*> nodes2;
		nodes1.emplace_back(root);
		int l = lmax - 1;
		while (!nodes1.empty()) {
			nodes2.clear();

			for (auto n : nodes1) {
				levels[l].push_back(n->val);
				if (n->left)
					nodes2.emplace_back(n->left);
				if (n->right)
					nodes2.emplace_back(n->right);
			}
			
			nodes1.swap(nodes2);

			--l;
		}
		
		return levels;
	}
};

void print(const vector<vector<int>>& levels) {
	for (const auto &l : levels) {
		copy(begin(l), end(l), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}

int main()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	/*15 7
	9 20
	3*/
	auto r = Solution().levelOrderBottom(root);
	print(r);

	print(Solution().levelOrderBottom(nullptr));

    return 0;
}

