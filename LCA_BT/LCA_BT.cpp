
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution
{
public:

	bool getPathImpl(vector<TreeNode*>& path, TreeNode* root, TreeNode* p)
	{
		if (!root)
			return false;
		if (root == p)
		{
			path.push_back(root);
			return true;
		}
		if (getPathImpl(path, root->left, p) ||
			getPathImpl(path, root->right, p))
		{
			path.push_back(root);
			return true;
		}
		return false;
	}

	vector<TreeNode*> getPath(TreeNode* root, TreeNode* p)
	{
		vector<TreeNode*> path;
		getPathImpl(path, root, p);
		return path;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		auto path1 = getPath(root, p);
		auto path2 = getPath(root, q);

		int n1 = path1.size();
		int n2 = path2.size();
		int i = n1 - 1;
		int j = n2 - 1;

		TreeNode* rv = root;
		while (i >= 0 && j >= 0)
		{
			if (path1[i] == path2[j])
				rv = path1[i];
			else
				return rv;
			--i; --j;
		}

		return rv;
	}
};

int main()
{
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node5 = node3->left = new TreeNode(5);
	TreeNode* node1 = node3->right = new TreeNode(1);
	TreeNode* node6 = node5->left = new TreeNode(6);
	TreeNode* node2 = node5->right = new TreeNode(2);
	TreeNode* node7 = node2->left = new TreeNode(7);
	TreeNode* node4 = node2->right = new TreeNode(4);

	TreeNode* node0 = node1->left = new TreeNode(0);
	TreeNode* node8 = node1->right = new TreeNode(8);

	cout << Solution().lowestCommonAncestor(node3, node5, node1)->val << endl;
	cout << Solution().lowestCommonAncestor(node3, node5, node4)->val << endl;

	return 0;
}

