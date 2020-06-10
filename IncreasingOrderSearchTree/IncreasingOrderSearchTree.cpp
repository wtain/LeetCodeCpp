
#include <iostream>
#include <iomanip>

using namespace std;

/*
https://leetcode.com/problems/increasing-order-search-tree/

Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

      5
     / \
    3    6
   / \    \
  2   4    8
 /        / \
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
           \
            7
             \
              8
               \
                9

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
	pair<TreeNode*, TreeNode*> increasingBSTImpl(TreeNode* root) {
		if (!root)
			return{ nullptr, nullptr };
		auto pleft = increasingBSTImpl(root->left);
		auto pright = increasingBSTImpl(root->right);
		
		TreeNode* pmin = pleft.first ? pleft.first : root;
		TreeNode* pmax = pright.second ? pright.second : root;

		if (pleft.second)
			pleft.second->right = root;
		root->right = pright.first;
		root->left = nullptr;

		return{ pmin, pmax };
	}

	TreeNode* increasingBST(TreeNode* root) {
		return increasingBSTImpl(root).first;
	}
};

/*
if (!root)
return{ nullptr, nullptr };
auto pleft = increasingBSTImpl(root->left);
TreeNode* newRoot = pleft.first;
TreeNode* newRootMax = pleft.second;
if (!newRoot) {
newRoot = root;
}
if (!newRootMax) {
newRootMax = newRoot;
}
auto pright = increasingBSTImpl(root->right);
newRootMax->right = pright.first;
if (pright.second)
newRootMax = pright.second;
else
newRootMax = root;
cout << root->val << "(" << newRoot->val << ", ";
if (newRootMax)
cout << newRootMax->val;
else
cout << "(null)";
cout << ")" << endl;
return{ newRoot, newRootMax };
*/

void printTree(TreeNode* root) {
	if (!root)
		return;
	printTree(root->left);
	cout << root->val << " ";
	printTree(root->right);
}

int main()
{
	{
		TreeNode* root = new TreeNode(5);
		root->left = new TreeNode(3);
		root->right = new TreeNode(6);
		root->left->left = new TreeNode(2);
		root->left->right = new TreeNode(4);
		root->left->left->left = new TreeNode(1);
		root->right->right = new TreeNode(8);
		root->right->right->left = new TreeNode(7);
		root->right->right->right = new TreeNode(9);
		printTree(Solution().increasingBST(root));
		cout << endl;
	}
    return 0;
}

