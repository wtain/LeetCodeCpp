
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]



Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printTree(TreeNode* root) {
	if (!root)
		return;
	//cout << "(";
	printTree(root->left);
	//cout << ") " << root->val << " (";
	cout << root->val << " ";
	printTree(root->right);
	//cout << ")";
}

void printLnTree(TreeNode* root) {
	printTree(root);
	cout << endl;
}

//Runtime: 0 ms
//Memory Usage : 9.2 MB
//Runtime: 4 ms, faster than 85.23% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
//Memory Usage : 9 MB, less than 100.00% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
//Runtime: 4 ms, faster than 85.23% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
//Memory Usage : 8.9 MB, less than 100.00% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
class Solution {
public:

	TreeNode* bstFromPreorder(vector<int>& preorder) {
		if (preorder.empty())
			return nullptr;
		TreeNode* root = new TreeNode(preorder[0]);
		stack<TreeNode*> parents;
		parents.push(root);
		for (size_t i = 1; i < preorder.size(); ++i) {
			if (parents.empty())
				break;
			TreeNode* child = new TreeNode(preorder[i]);

			if (parents.top()->val > preorder[i]) {
				parents.top()->left = child;
				parents.emplace(child);
			}
			else {
				TreeNode* prevParent = nullptr;
				while (parents.size() > 1 && parents.top()->val < preorder[i]) {
					prevParent = parents.top();
					parents.pop();
				}
				if (prevParent && parents.top()->val > preorder[i])
					parents.push(prevParent);
				while (parents.top()->right && parents.top()->val < preorder[i]) {
					parents.push(parents.top()->right);
				}
				parents.top()->right = child;
				parents.emplace(child);
			}
		}
		return root;
	}
};

int main()
{
	/*
	                8
                 5    10
                1 7    12
	*/
	printLnTree(Solution().bstFromPreorder(vector<int>{8, 5, 1, 7, 10, 12}));
	

    return 0;
}

