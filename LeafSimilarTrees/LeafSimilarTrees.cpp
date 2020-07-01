
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
https://leetcode.com/problems/leaf-similar-trees/

Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.



Constraints:

Both of the given trees will have between 1 and 200 nodes.
Both of the given trees will have values between 0 and 200

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Runtime: 4 ms, faster than 81.36% of C++ online submissions for Leaf - Similar Trees.
//Memory Usage : 12.9 MB, less than 63.82% of C++ online submissions for Leaf - Similar Trees.
class Solution {
public:

	void getLeavesImpl(TreeNode* root, vector<int>& leaves) {
		if (!root)
			return;
		if (!root->left && !root->right) {
			leaves.push_back(root->val);
			return;
		}
		getLeavesImpl(root->left, leaves);
		getLeavesImpl(root->right, leaves);
	}

	vector<int> getLeaves(TreeNode* root) {
		vector<int> result;
		getLeavesImpl(root, result);
		return result;
	}

	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		const auto r1 = getLeaves(root1);
		const auto r2 = getLeaves(root2);
		return r1 == r2;
	}
};

int main()
{
	{
		TreeNode* root1 = new TreeNode(3);
		root1->left = new TreeNode(5);
		root1->left->left = new TreeNode(6);
		root1->left->right = new TreeNode(2);
		root1->left->right->left = new TreeNode(7);
		root1->left->right->right = new TreeNode(4);

		root1->right = new TreeNode(1);
		root1->right->left = new TreeNode(9);
		root1->right->right = new TreeNode(8);


		TreeNode* root2 = new TreeNode(3);
		root2->left = new TreeNode(5);
		root2->left->left = new TreeNode(6);
		root2->left->right = new TreeNode(2);
		root2->left->right->left = new TreeNode(7);
		root2->left->right->right = new TreeNode(4);
		root2->left->right->right->left = new TreeNode(4);
		root2->left->right->right->right = new TreeNode(9);

		root2->right = new TreeNode(8);

		cout << boolalpha << Solution().leafSimilar(root1, root2) << endl; // true
	}

	{
		TreeNode* root1 = new TreeNode(3);
		root1->left = new TreeNode(5);
		root1->left->left = new TreeNode(6);
		root1->left->right = new TreeNode(2);
		root1->left->right->left = new TreeNode(7);
		root1->left->right->right = new TreeNode(4);

		root1->right = new TreeNode(1);
		root1->right->left = new TreeNode(9);
		root1->right->right = new TreeNode(8);


		TreeNode* root2 = new TreeNode(3);
		root2->left = new TreeNode(5);
		root2->left->left = new TreeNode(6);
		root2->left->right = new TreeNode(2);
		root2->left->right->left = new TreeNode(7);
		root2->left->right->right = new TreeNode(4);
		root2->left->right->right->right = new TreeNode(9);

		root2->right = new TreeNode(8);

		cout << boolalpha << Solution().leafSimilar(root1, root2) << endl; // false
	}

    return 0;
}

