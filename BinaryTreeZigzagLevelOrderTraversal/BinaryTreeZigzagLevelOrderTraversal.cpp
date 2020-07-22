
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its zigzag level order traversal as:
[
[3],
[20,9],
[15,7]
]

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//class Solution {
//public:
//
//	void zigzagLevelOrderImpl(TreeNode* root, vector<vector<int>>& result, int level) {
//		if (level == result.size())
//			result.emplace_back(vector<int>{ root->val });
//		else
//			result[level].push_back(root->val);
//		//if (level & 1) {
//		//	if (root->right)
//		//		zigzagLevelOrderImpl(root->right, result, level + 1);
//		//	if (root->left)
//		//		zigzagLevelOrderImpl(root->left, result, level + 1);
//		//}
//		//else {
//		//	if (root->left)
//		//		zigzagLevelOrderImpl(root->left, result, level + 1);
//		//	if (root->right)
//		//		zigzagLevelOrderImpl(root->right, result, level + 1);
//		//}
//		if (root->left)
//			zigzagLevelOrderImpl(root->left, result, level + 1);
//		if (root->right)
//			zigzagLevelOrderImpl(root->right, result, level + 1);
//	}
//
//	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//		if (!root)
//			return{};
//		vector<vector<int>> result;
//		zigzagLevelOrderImpl(root, result, 0);
//		return result;
//	}
//};

/*
Runtime: 8 ms, faster than 36.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 12 MB, less than 99.10% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Runtime: 4 ms, faster than 81.35% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 12.2 MB, less than 64.70% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Runtime: 4 ms, faster than 81.35% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 12 MB, less than 98.60% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
*/
class Solution {
public:

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		vector<TreeNode*> toVisit;
		if (root)
			toVisit.push_back(root);
		
		while (!toVisit.empty()) {
			result.push_back(vector<int>{});
			vector<TreeNode*> toVisitNext;
			const bool isOdd = (result.size() & 1) == 0;
			for (int i = toVisit.size() - 1; i >= 0; --i) {
				result.back().push_back(toVisit[i]->val);
				if (toVisit[i]->right && isOdd)
					toVisitNext.push_back(toVisit[i]->right);
				if (toVisit[i]->left)
					toVisitNext.push_back(toVisit[i]->left);
				if (toVisit[i]->right && !isOdd)
					toVisitNext.push_back(toVisit[i]->right);
			}
			toVisitNext.swap(toVisit);
		}
		
		return result;
	}
};

// WRONG
//class Solution {
//public:
//
//	void zigzagLevelOrderImpl(TreeNode* root, vector<vector<int>>& result, int level) {
//		if (level == result.size())
//			result.emplace_back(vector<int>{ root->val });
//		else
//			result[level].push_back(root->val);
//		if (root->left)
//			zigzagLevelOrderImpl(root->left, result, level + 1);
//		if (root->right)
//			zigzagLevelOrderImpl(root->right, result, level + 1);
//	}
//
//	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//		vector<vector<int>> result;
//		vector<TreeNode*> toVisit;
//		if (root)
//			toVisit.push_back(root);
//
//		while (!toVisit.empty()) {
//			result.push_back(vector<int>{});
//			vector<TreeNode*> toVisitNext;
//			const bool isOdd = (result.size() & 1) == 1;
//			for (auto& node: toVisit) {
//				result.back().push_back(node->val);
//				if (node->right && isOdd)
//					toVisitNext.push_back(node->right);
//				if (node->left)
//					toVisitNext.push_back(node->left);
//				if (node->right && !isOdd)
//					toVisitNext.push_back(node->right);
//			}
//			toVisitNext.swap(toVisit);
//		}
//
//		return result;
//	}
//};

void print(const vector<vector<int>>& r) {
	for (const auto& row : r) {
		copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << endl;
}

int main()
{
	{
		TreeNode* root = new TreeNode(3);
		root->left = new TreeNode(9);
		root->right = new TreeNode(20);
		root->right->left = new TreeNode(15);
		root->right->right = new TreeNode(7);

		print(Solution().zigzagLevelOrder(root));
	}

	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->left->left = new TreeNode(4);
		root->left->right = new TreeNode(5);
		root->right = new TreeNode(3);
		root->right->left = new TreeNode(6);
		root->right->right = new TreeNode(7);

		print(Solution().zigzagLevelOrder(root));
	}

	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->left->left = new TreeNode(4);
		root->right = new TreeNode(3);
		root->right->right = new TreeNode(5);

		print(Solution().zigzagLevelOrder(root)); // [[1],[3,2],[4, 5]]
	}

    return 0;
}

