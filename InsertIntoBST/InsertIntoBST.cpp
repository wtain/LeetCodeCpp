#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) 
	{
		if (val > root->val)
		{
			if (!root->right)
			{
				root->right = new TreeNode(val);
			}
			else
			{
				insertIntoBST(root->right, val);
			}
		}
		else
		{
			if (!root->left)
			{
				root->left = new TreeNode(val);
			}
			else
			{
				insertIntoBST(root->left, val);
			}
		}
		return root;
	}
};

class Helper
{
	int parseInt(const std::string& s, int& i, int ie)
	{
		int v = 0;
		while (i <= ie && isdigit(s[i]))
		{
			v *= 10;
			v += s[i] - '0';
			++i;
		}
		return v;
	}

	/*
	INT = D+
	TREE = INT|INT(TREE,TREE)|e
	*/
	TreeNode* constructTreeImpl(const std::string& s, int& i, int ie)
	{
		if (i > ie || !isdigit(s[i]))
			return NULL;
		int v = parseInt(s, i, ie);

		TreeNode* node = new TreeNode(v);

		if (i <= ie)
		{
			if (s[i] == '(')
			{
				++i;
				node->left = constructTreeImpl(s, i, ie);
				if (s[i] != ',')
					throw 1;
				++i;
				node->right = constructTreeImpl(s, i, ie);
				if (s[i] != ')')
					throw 1;
				++i;
			}
		}

		return node;
	}

public:

	TreeNode* constructTree(const std::string& s)
	{
		int i = 0;
		return constructTreeImpl(s, i, s.length() - 1);
	}

	void printInOrder(TreeNode* root)
	{
		if (!root)
			return;
		cout << root->val << ", ";
		printInOrder(root->left);
		printInOrder(root->right);
	}

	void printPostOrder(TreeNode* root)
	{
		if (!root)
			return;
		printPostOrder(root->left);
		printPostOrder(root->right);
		cout << root->val << ", ";
	}
};

/*
Given the tree:
    4
   / \
  2   7
 / \
1   3
And the value to insert: 5

*/

int main()
{
	auto tree = Helper().constructTree("4(2(1,3),7)");
	Helper().printInOrder(tree);
	cout << endl;
	Helper().printPostOrder(tree);
	cout << endl << endl;
	Solution().insertIntoBST(tree, 5);
	Helper().printInOrder(tree);
	cout << endl;
	Helper().printPostOrder(tree);
	cout << endl;
    return 0;
}

