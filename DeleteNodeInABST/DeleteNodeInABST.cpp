
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/delete-node-in-a-bst/

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
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
//	pair<TreeNode*, TreeNode*> findNode(TreeNode* root, int key) {
//		TreeNode* parent = nullptr;
//
//		while (root) {
//			if (root->val == key)
//				return{ root, parent };
//			parent = root;
//			if (root->val < key)
//				root = root->right;
//			else
//				root = root->left;
//		}
//
//		return{};
//	}
//
//	pair<TreeNode*, TreeNode*> findMin(TreeNode* root) {
//		TreeNode* parent = nullptr;
//
//		while (root->left) {
//			parent = root;
//			root = root->left;
//		}
//
//		return{ root, parent };
//	}
//
//	pair<TreeNode*, TreeNode*> findMax(TreeNode* root) {
//		TreeNode* parent = nullptr;
//
//		while (root->right) {
//			parent = root;
//			root = root->right;
//		}
//
//		return{ root, parent };
//	}
//
//	TreeNode* deleteNode(TreeNode* root, int key) {
//		if (!root)
//			return nullptr;
//		auto r = findNode(root, key);
//		TreeNode *node = r.first, *parent = r.second;
//
//		if (!parent) {
//			if (node->right) {
//				auto m = findMin(node->right);
//				if (m.first == m.second->left)
//					m.second->left = nullptr;
//				else
//					m.second->right = nullptr;
//				if (m.first != node->right)
//					m.first->right = node->right;
//				return m.first;
//			}
//			else if (node->left) {
//				auto m = findMax(node->left);
//				if (m.first == m.second->left)
//					m.second->left = nullptr;
//				else
//					m.second->right = nullptr;
//				if (m.first != node->left)
//					m.first->left = node->left;
//				return m.first;
//			}
//			else {
//				return nullptr;
//			}
//		}
//
//		if (r.second->left == r.first) {
//
//		}
//		else {
//
//		}
//	}
//};

//Runtime: 40 ms, faster than 69.50% of C++ online submissions for Delete Node in a BST.
//Memory Usage : 15.2 MB, less than 5.41% of C++ online submissions for Delete Node in a BST.
class Solution {
public:

	pair<TreeNode*, TreeNode**> findMin(TreeNode* root, TreeNode** parentLink) {
		while (root->left) {
			parentLink = &root->left;
			root = root->left;
		}
	
		return{ root, parentLink };
	}
	
	pair<TreeNode*, TreeNode**> findMax(TreeNode* root, TreeNode** parentLink) {
		while (root->right) {
			parentLink = &root->right;
			root = root->right;
		}
	
		return{ root, parentLink };
	}

	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root)
			return nullptr;

		TreeNode* parent = nullptr;
		TreeNode** parentLink = nullptr;
		TreeNode* node = root;
		
		while (node) {
			if (node->val == key) {
				if (node->right) {
					auto m = findMin(node->right, &node->right);
					TreeNode* mr = m.first->right;
					*m.second = mr;
					if (m.first->right != node->right)
						m.first->right = node->right;
					m.first->left = node->left;
					if (parent)
						*parentLink = m.first;
					return parent ? root : m.first;
				}
				else if (node->left) {
					auto m = findMax(node->left, &node->left);
					TreeNode* ml = m.first->left;
					*m.second = ml;
					if (m.first->left != node->left)
						m.first->left = node->left;
					m.first->right = node->right;
					if (parent)
						*parentLink = m.first;
					return parent ? root : m.first;
				}
				else
				{
					if (parentLink)
						*parentLink = nullptr;
					return parent ? root : nullptr;
				}
			}
			parent = node;
			if (node->val < key) {
				parentLink = &node->right;
				node = node->right;
			}
			else {
				parentLink = &node->left;
				node = node->left;
			}
		}

		return root; // no changes
	}
};

//TreeNode* parseTree(const std::string& s) {
//	if (s == "null")
//		return nullptr;
//	size_t i = 0;
//}

void printTree(TreeNode* root) {
	if (!root)
		return;
	cout << "(";
	printTree(root->left);
	cout << root->val << " ";
	printTree(root->right);
	cout << ")";
}

int main()
{
	{
		TreeNode* root = new TreeNode(5);
		root->left = new TreeNode(3);
		root->right = new TreeNode(6);
		root->left->left = new TreeNode(2);
		root->left->right = new TreeNode(4);
		root->right->right = new TreeNode(7);

		printTree(Solution().deleteNode(root, 3));
		cout << endl << endl;
	}

	{
		TreeNode* root = new TreeNode(5);
	
		printTree(Solution().deleteNode(root, 5));
		cout << endl << endl;
	}

	{
		TreeNode* root = new TreeNode(5);
		root->left = new TreeNode(3);
		root->right = new TreeNode(6);
		root->left->left = new TreeNode(2);
		root->left->right = new TreeNode(4);
		root->right->right = new TreeNode(7);

		printTree(Solution().deleteNode(root, 5));
		cout << endl << endl;
	}

	{
		TreeNode* root = new TreeNode(1);
		root->right = new TreeNode(2);

		printTree(Solution().deleteNode(root, 2));
		cout << endl << endl;
	}

    return 0;
}

