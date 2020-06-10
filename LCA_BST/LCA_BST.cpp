
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

	int depth(TreeNode* root, TreeNode* node)
	{
		int d = 0;
		int v = node->val;
		while (root->val != v)
		{
			++d;
			if (root->val > v)
				root = root->left;
			else
				root = root->right;
		}
		return d;
	}

	vector<TreeNode*> GetPath(TreeNode* root, TreeNode* node)
	{
		int v = node->val;
		vector<TreeNode*> r;
		while (root->val != v)
		{
			r.push_back(root);
			if (root->val > v)
				root = root->left;
			else
				root = root->right;
		}
		r.push_back(node);
		return r;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		//int dp = depth(root, p);
		//int dq = depth(root, q);
		/*
		const auto p1 = GetPath(root, p);
		const auto p2 = GetPath(root, q);

		int n = min(p1.size(), p2.size());
		for (int i = 0; i < n; ++i)
		{

		}

		return NULL;
		*/

		int v1 = p->val;
		int v2 = q->val;

		while (root->val != v1 && root->val != v2)
		{
			if (v1 < root->val && v2 < root->val)
				root = root->left;
			else if (v1 > root->val && v2 > root->val)
				root = root->right;
			else
				break;
		}
		return root;
	}
};

int main()
{
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node2 = node6->left = new TreeNode(2);
	TreeNode* node8 = node6->right = new TreeNode(8);
	TreeNode* node0 = node2->left = new TreeNode(0);
	TreeNode* node4 = node2->right = new TreeNode(4);
	TreeNode* node3 = node4->left = new TreeNode(3);
	TreeNode* node5 = node4->right = new TreeNode(5);
	TreeNode* node7 = node8->left = new TreeNode(7);
	TreeNode* node9 = node8->right = new TreeNode(9);

	cout << Solution().lowestCommonAncestor(node6, node2, node8)->val << endl;
	cout << Solution().lowestCommonAncestor(node6, node2, node4)->val << endl;

    return 0;
}

